#include "energycalculator.h"

EnergyCalculator::EnergyCalculator(QObject *parent) : QObject(parent),
    m_totalEnergyKwh(0), m_totalDistanceKm(0)
{
}

void EnergyCalculator::updateConsumption(float powerKw, float speedKmph)
{
    // Integrated over time (called e.g. every 100ms)
    // float dt = 0.1f; // hours
    // m_totalEnergyKwh += powerKw * dt;
    // m_totalDistanceKm += speedKmph * dt;
}

float EnergyCalculator::getTripConsumption() { return m_totalEnergyKwh; }
float EnergyCalculator::getAverageConsumption() {
    return m_totalDistanceKm > 0 ? (m_totalEnergyKwh / m_totalDistanceKm) * 100.0f : 0.0f;
}
