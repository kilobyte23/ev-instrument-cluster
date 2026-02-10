#ifndef CHARGINGMANAGER_H
#define CHARGINGMANAGER_H

#include <QObject>
#include <QDateTime>

struct ChargingSession {
    QDateTime startTime;
    QDateTime endTime;
    float startSoc;
    float endSoc;
    float energyAdded;         // kWh
    float averagePower;        // kW
    int durationSeconds;
    bool isComplete;
};

class ChargingManager : public QObject
{
    Q_OBJECT

public:
    explicit ChargingManager(QObject *parent = nullptr);
    
    // Update charging state
    void updateChargingState(bool isCharging, float batterySoc, float chargePowerKw);
    
    // Get current session info
    bool isChargingActive() const { return m_isCharging; }
    int getTimeToFull() const;           // minutes
    float getEnergyAdded() const;        // kWh this session
    float getAveragePower() const;       // kW average this session
    int getSessionDuration() const;      // seconds
    float getTargetSoc() const { return m_targetSoc; }
    
    // Set charging parameters
    void setTargetSoc(float targetSoc) { m_targetSoc = targetSoc; }
    void setBatteryCapacity(float capacityKwh) { m_batteryCapacity = capacityKwh; }
    
    // Session history
    ChargingSession getCurrentSession() const { return m_currentSession; }
    
signals:
    void chargingStarted();
    void chargingCompleted();

private:
    void startChargingSession(float batterySoc);
    void endChargingSession(float batterySoc);
    
    bool m_isCharging;
    float m_batteryCapacity;     // kWh
    float m_targetSoc;           // Target SoC percentage
    
    ChargingSession m_currentSession;
    float m_energyAddedThisSession;
    QList<float> m_recentPowerSamples;
    QDateTime m_sessionStartTime;
};

#endif // CHARGINGMANAGER_H
