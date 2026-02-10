#include "chargingmanager.h"
#include <QDebug>

ChargingManager::ChargingManager(QObject *parent)
    : QObject(parent),
      m_isCharging(false),
      m_batteryCapacity(77.4),
      m_targetSoc(80.0),
      m_energyAddedThisSession(0.0)
{
    m_currentSession.isComplete = false;
}

void ChargingManager::updateChargingState(bool isCharging, float batterySoc, float chargePowerKw)
{
    // Detect charging start
    if (isCharging && !m_isCharging) {
        startChargingSession(batterySoc);
    }
    
    // Detect charging end
    if (!isCharging && m_isCharging) {
        endChargingSession(batterySoc);
    }
    
    // Update tracking during charging
    if (isCharging) {
        // Track power samples for average calculation
        m_recentPowerSamples.append(chargePowerKw);
        if (m_recentPowerSamples.size() > 300) {  // Last ~60 seconds at 200ms
            m_recentPowerSamples.removeFirst();
        }
        
        // Estimate energy added (power * time)
        // Assuming updates every ~0.2 seconds
        m_energyAddedThisSession += chargePowerKw * (0.2 / 3600.0);  // kW * hours
        
        m_currentSession.energyAdded = m_energyAddedThisSession;
        m_currentSession.endSoc = batterySoc;
        m_currentSession.durationSeconds = m_sessionStartTime.secsTo(QDateTime::currentDateTime());
    }
    
    m_isCharging = isCharging;
}

void ChargingManager::startChargingSession(float batterySoc)
{
    qDebug() << "ChargingManager: Charging session started at" << batterySoc << "% SoC";
    
    m_currentSession.startTime = QDateTime::currentDateTime();
    m_currentSession.startSoc = batterySoc;
    m_currentSession.endSoc = batterySoc;
    m_currentSession.energyAdded = 0.0;
    m_currentSession.averagePower = 0.0;
    m_currentSession.durationSeconds = 0;
    m_currentSession.isComplete = false;
    
    m_energyAddedThisSession = 0.0;
    m_recentPowerSamples.clear();
    m_sessionStartTime = QDateTime::currentDateTime();
    
    emit chargingStarted();
}

void ChargingManager::endChargingSession(float batterySoc)
{
    qDebug() << "ChargingManager: Charging session ended at" << batterySoc << "% SoC";
    
    m_currentSession.endTime = QDateTime::currentDateTime();
    m_currentSession.endSoc = batterySoc;
    m_currentSession.averagePower = getAveragePower();
    m_currentSession.isComplete = true;
    
    qDebug() << "  Duration:" << m_currentSession.durationSeconds << "seconds";
    qDebug() << "  Energy added:" << m_currentSession.energyAdded << "kWh";
    qDebug() << "  Average power:" << m_currentSession.averagePower << "kW";
    
    emit chargingCompleted();
}

int ChargingManager::getTimeToFull() const
{
    if (!m_isCharging || m_recentPowerSamples.isEmpty()) {
        return 0;
    }
    
    // Calculate average power from recent samples
    float avgPower = 0.0f;
    for (float power : m_recentPowerSamples) {
        avgPower += power;
    }
    avgPower /= m_recentPowerSamples.size();
    
    if (avgPower <= 0.1) {
        return 0;
    }
    
    // Energy needed to reach target SoC
    float currentEnergy = (m_currentSession.endSoc / 100.0f) * m_batteryCapacity;
    float targetEnergy = (m_targetSoc / 100.0f) * m_batteryCapacity;
    float energyNeeded = targetEnergy - currentEnergy;
    
    if (energyNeeded <= 0) {
        return 0;  // Already at or above target
    }
    
    // Time = Energy / Power (in hours), convert to minutes
    float timeHours = energyNeeded / avgPower;
    return static_cast<int>(timeHours * 60.0f);
}

float ChargingManager::getEnergyAdded() const
{
    return m_energyAddedThisSession;
}

float ChargingManager::getAveragePower() const
{
    if (m_recentPowerSamples.isEmpty()) {
        return 0.0f;
    }
    
    float sum = 0.0f;
    for (float power : m_recentPowerSamples) {
        sum += power;
    }
    
    return sum / m_recentPowerSamples.size();
}

int ChargingManager::getSessionDuration() const
{
    if (m_isCharging) {
        return m_sessionStartTime.secsTo(QDateTime::currentDateTime());
    }
    return m_currentSession.durationSeconds;
}
