#include "rangepredictor.h"
#include <QDebug>
#include <QtMath>

RangePredictor::RangePredictor(QObject *parent)
    : QObject(parent),
      m_batteryCapacityKwh(77.4),  // Default 4W capacity
      m_temperatureFactor(1.0),
      m_sampleCount(0)
{
}

void RangePredictor::updateState(float batterySoc, float powerKw, float speedKmh, float batteryTemp)
{
    // Only calculate efficiency when moving
    if (speedKmh < 1.0 || qAbs(powerKw) < 0.5) {
        return;
    }
    
    // Calculate instantaneous efficiency (Wh/km)
    float instantEfficiency = (powerKw * 1000.0f) / speedKmh;  // kW to Wh, per km
    
    // Temperature impact (simplified model)
    // Optimal at 20-30°C, efficiency drops at extremes
    if (batteryTemp < 0) {
        m_temperatureFactor = 0.70;  // 30% reduction in cold
    } else if (batteryTemp < 10) {
        m_temperatureFactor = 0.85;  // 15% reduction
    } else if (batteryTemp < 20) {
        m_temperatureFactor = 0.95;  // 5% reduction
    } else if (batteryTemp <= 35) {
        m_temperatureFactor = 1.0;   // Optimal
    } else if (batteryTemp <= 45) {
        m_temperatureFactor = 0.95;  // Slight reduction in heat
    } else {
        m_temperatureFactor = 0.85;  // 15% reduction in high heat
    }
    
    // Add to recent efficiency (last ~5 minutes at 200ms updates = 1500 samples)
    m_recentEfficiency.append(instantEfficiency);
    if (m_recentEfficiency.size() > 1500) {
        m_recentEfficiency.removeFirst();
    }
    
    // Add to overall history (keep last 10000 samples ~ 30 min)
    m_efficiencyHistory.append(instantEfficiency);
    if (m_efficiencyHistory.size() > 10000) {
        m_efficiencyHistory.removeFirst();
    }
    
    m_sampleCount++;
}

float RangePredictor::calculateRangeEstimate(float efficiency, float batterySoc) const
{
    if (efficiency <= 0 || batterySoc <= 0) {
        return 0.0f;
    }
    
    // Available energy in kWh
    float availableEnergy = (batterySoc / 100.0f) * m_batteryCapacityKwh;
    
    // Convert to Wh and divide by efficiency (Wh/km) to get range
    float rangeKm = (availableEnergy * 1000.0f) / efficiency;
    
    // Apply temperature factor
    rangeKm *= m_temperatureFactor;
    
    return rangeKm;
}

float RangePredictor::getOptimisticRange() const
{
    if (m_efficiencyHistory.isEmpty()) {
        return 0.0f;
    }
    
    // Find best 20% efficiency (lowest Wh/km = best)
    QList<float> sorted = m_efficiencyHistory;
    std::sort(sorted.begin(), sorted.end());
    
    int percentile20 = sorted.size() / 5;
    float bestEfficiency = sorted[qMax(0, percentile20)];
    
    return calculateRangeEstimate(bestEfficiency, 100.0f);  // At 100% SoC
}

float RangePredictor::getRealisticRange() const
{
    float avgEfficiency = getAverageEfficiency();
    return calculateRangeEstimate(avgEfficiency, 100.0f);
}

float RangePredictor::getPessimisticRange() const
{
    if (m_efficiencyHistory.isEmpty()) {
        return 0.0f;
    }
    
    // Find worst 20% efficiency (highest Wh/km = worst)
    QList<float> sorted = m_efficiencyHistory;
    std::sort(sorted.begin(), sorted.end(), std::greater<float>());
    
    int percentile20 = sorted.size() / 5;
    float worstEfficiency = sorted[qMax(0, percentile20)];
    
    return calculateRangeEstimate(worstEfficiency, 100.0f);
}

float RangePredictor::getAverageEfficiency() const
{
    if (m_efficiencyHistory.isEmpty()) {
        return 180.0f;  // Default typical EV efficiency
    }
    
    float sum = 0.0f;
    for (float eff : m_efficiencyHistory) {
        sum += eff;
    }
    
    return sum / m_efficiencyHistory.size();
}

float RangePredictor::getRecentEfficiency() const
{
    if (m_recentEfficiency.isEmpty()) {
        return getAverageEfficiency();
    }
    
    float sum = 0.0f;
    for (float eff : m_recentEfficiency) {
        sum += eff;
    }
    
    return sum / m_recentEfficiency.size();
}

void RangePredictor::reset()
{
    m_efficiencyHistory.clear();
    m_recentEfficiency.clear();
    m_temperatureFactor = 1.0;
    m_sampleCount = 0;
    qDebug() << "RangePredictor: Reset";
}
