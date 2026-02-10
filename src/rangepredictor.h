#ifndef RANGEPREDICTOR_H
#define RANGEPREDICTOR_H

#include <QObject>
#include <QList>

class RangePredictor : public QObject
{
    Q_OBJECT

public:
    explicit RangePredictor(QObject *parent = nullptr);
    
    // Update with current vehicle state
    void updateState(float batterySoc, float powerKw, float speedKmh, float batteryTemp);
    
    // Get range estimates
    float getOptimisticRange() const;    // Best case scenario
    float getRealisticRange() const;     // Most likely range
    float getPessimisticRange() const;   // Worst case scenario
    
    // Get efficiency metrics
    float getAverageEfficiency() const;  // Wh/km
    float getRecentEfficiency() const;   // Wh/km (last few minutes)
    
    // Reset learning
    void reset();

private:
    float calculateRangeEstimate(float efficiency, float batterySoc) const;
    float m_batteryCapacityKwh;          // Total battery capacity
    
    QList<float> m_efficiencyHistory;    // Historical efficiency (Wh/km)
    QList<float> m_recentEfficiency;     // Recent efficiency samples
    
    float m_temperatureFactor;           // Efficiency impact from temperature
    int m_sampleCount;
};

#endif // RANGEPREDICTOR_H
