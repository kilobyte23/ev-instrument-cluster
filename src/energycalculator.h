#ifndef ENERGYCALCULATOR_H
#define ENERGYCALCULATOR_H

#include <QObject>
#include <QList>

class EnergyCalculator : public QObject
{
    Q_OBJECT

public:
    explicit EnergyCalculator(QObject *parent = nullptr);
    
    // Update energy consumption based on power and speed over time interval
    void updateConsumption(float powerKw, float speedKmph, float deltaTimeSec);
    
    // Getters for energy statistics
    float getTripConsumption() const;      // kWh consumed in current trip
    float getTotalConsumption() const;     // kWh consumed overall
    float getRegenEnergy() const;          // kWh recovered via regen
    float getAverageConsumption() const;   // Wh/km overall average
    float getTripEfficiency() const;       // Wh/km for current trip
    float getInstantConsumption() const;   // Current power (kW)
    
    // Distance tracking
    float getTripDistance() const;         // km traveled this trip
    float getTotalDistance() const;        // km traveled overall
    
    // Reset functions
    void resetTrip();                      // Reset trip counters
    void resetAll();                       // Reset all counters

private:
    float m_totalEnergyKwh;               // Total energy consumed
    float m_totalDistanceKm;              // Total distance traveled
    float m_regenEnergyKwh;               // Energy recovered from regen
    float m_tripEnergyKwh;                // Energy consumed this trip
    float m_tripDistanceKm;               // Distance this trip
   
    QList<float> m_recentPowerSamples;    // Recent power samples for instant calculation
};

#endif // ENERGYCALCULATOR_H
