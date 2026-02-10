#include "energycalculator.h"
#include <QDebug>

EnergyCalculator::EnergyCalculator(QObject *parent) 
    : QObject(parent),
      m_totalEnergyKwh(0),
      m_totalDistanceKm(0),
      m_regenEnergyKwh(0),
      m_tripEnergyKwh(0),
      m_tripDistanceKm(0)
{
}

void EnergyCalculator::updateConsumption(float powerKw, float speedKmph, float deltaTimeSec)
{
    // Only update if moving or power is being consumed/regenerated
    if (speedKmph > 0.1 || qAbs(powerKw) > 0.5) {
        // Convert time to hours
        float deltaTimeHours = deltaTimeSec / 3600.0f;
        
        // Calculate energy consumed (positive) or regenerated (negative)
        float energyDelta = powerKw * deltaTimeHours;
        
        // Track total energy
        if (powerKw >= 0) {
            m_totalEnergyKwh += energyDelta;
            m_tripEnergyKwh += energyDelta;
        } else {
            // Regenerative braking
            m_regenEnergyKwh += qAbs(energyDelta);
            m_tripEnergyKwh += energyDelta;  // Still counts toward trip (negative)
        }
        
        // Calculate distance traveled
        float distanceDelta = speedKmph * deltaTimeHours;
        m_totalDistanceKm += distanceDelta;
        m_tripDistanceKm += distanceDelta;
        
        // Update recent power history for efficiency calculation (last 60 samples ~12 sec at 200ms)
        m_recentPowerSamples.append(powerKw);
        if (m_recentPowerSamples.size() > 60) {
            m_recentPowerSamples.removeFirst();
        }
    }
}

float EnergyCalculator::getTripConsumption() const
{
    return m_tripEnergyKwh;
}

float EnergyCalculator::getTotalConsumption() const
{
    return m_totalEnergyKwh;
}

float EnergyCalculator::getRegenEnergy() const
{
    return m_regenEnergyKwh;
}

float EnergyCalculator::getAverageConsumption() const
{
    // Wh/km
    return m_totalDistanceKm > 0.1 ? (m_totalEnergyKwh / m_totalDistanceKm) * 1000.0f : 0.0f;
}

float EnergyCalculator::getTripEfficiency() const
{
    // Wh/km for current trip
    return m_tripDistanceKm > 0.1 ? (m_tripEnergyKwh / m_tripDistanceKm) * 1000.0f : 0.0f;
}

float EnergyCalculator::getInstantConsumption() const
{
    // Calculate average power over recent samples
    if (m_recentPowerSamples.isEmpty()) {
        return 0.0f;
    }
    
    float avgPower = 0.0f;
    for (float power : m_recentPowerSamples) {
        avgPower += power;
    }
    avgPower /= m_recentPowerSamples.size();
    
    // Convert to Wh/km (assuming typical speed for conversion)
    // This is instantaneous, so just return power in kW for now
    return avgPower;
}

void EnergyCalculator::resetTrip()
{
    m_tripEnergyKwh = 0.0f;
    m_tripDistanceKm = 0.0f;
    qDebug() << "EnergyCalculator: Trip reset";
}

void EnergyCalculator::resetAll()
{
    m_totalEnergyKwh = 0.0f;
    m_totalDistanceKm = 0.0f;
    m_regenEnergyKwh = 0.0f;
    m_tripEnergyKwh = 0.0f;
    m_tripDistanceKm = 0.0f;
    m_recentPowerSamples.clear();
    qDebug() << "EnergyCalculator: All data reset";
}

float EnergyCalculator::getTripDistance() const
{
    return m_tripDistanceKm;
}

float EnergyCalculator::getTotalDistance() const
{
    return m_totalDistanceKm;
}
