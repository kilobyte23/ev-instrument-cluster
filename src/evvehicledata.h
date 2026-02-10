#ifndef EVVEHICLEDATA_H
#define EVVEHICLEDATA_H

#include <QObject>
#include <QString>
#include <QDateTime>

class EVVehicleData : public QObject
{
    Q_OBJECT

    // Motion
    Q_PROPERTY(float speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(float odometer READ odometer WRITE setOdometer NOTIFY odometerChanged)
    Q_PROPERTY(float tripDistanceA READ tripDistanceA WRITE setTripDistanceA NOTIFY tripDistanceAChanged)
    Q_PROPERTY(float tripDistanceB READ tripDistanceB WRITE setTripDistanceB NOTIFY tripDistanceBChanged)

    // Battery
    Q_PROPERTY(float batterySoc READ batterySoc WRITE setBatterySoc NOTIFY batterySocChanged)
    Q_PROPERTY(float batteryVoltage READ batteryVoltage WRITE setBatteryVoltage NOTIFY batteryVoltageChanged)
    Q_PROPERTY(float batteryCurrent READ batteryCurrent WRITE setBatteryCurrent NOTIFY batteryCurrentChanged)
    Q_PROPERTY(float batteryTempAvg READ batteryTempAvg WRITE setBatteryTempAvg NOTIFY batteryTempAvgChanged)
    Q_PROPERTY(float batterySoh READ batterySoh WRITE setBatterySoh NOTIFY batterySohChanged)

    // Power & Energy
    Q_PROPERTY(float powerOutput READ powerOutput WRITE setPowerOutput NOTIFY powerOutputChanged)
    Q_PROPERTY(float instantConsumption READ instantConsumption WRITE setInstantConsumption NOTIFY instantConsumptionChanged)
    Q_PROPERTY(float estimatedRange READ estimatedRange WRITE setEstimatedRange NOTIFY estimatedRangeChanged)
    Q_PROPERTY(int timeToEmpty READ timeToEmpty WRITE setTimeToEmpty NOTIFY timeToEmptyChanged)
    Q_PROPERTY(int timeToFull READ timeToFull WRITE setTimeToFull NOTIFY timeToFullChanged)
    Q_PROPERTY(float averageConsumption READ averageConsumption WRITE setAverageConsumption NOTIFY averageConsumptionChanged)
    Q_PROPERTY(QList<float> consumptionHistory READ consumptionHistory WRITE setConsumptionHistory NOTIFY consumptionHistoryChanged)
    Q_PROPERTY(float motorTemp READ motorTemp WRITE setMotorTemp NOTIFY motorTempChanged)
    Q_PROPERTY(float controllerTemp READ controllerTemp WRITE setControllerTemp NOTIFY controllerTempChanged)
    Q_PROPERTY(float motorRpm READ motorRpm WRITE setMotorRpm NOTIFY motorRpmChanged)

    // Drive Mode
    Q_PROPERTY(DriveMode driveMode READ driveMode WRITE setDriveMode NOTIFY driveModeChanged)
    Q_PROPERTY(RegenLevel regenLevel READ regenLevel WRITE setRegenLevel NOTIFY regenLevelChanged)

    // Status
    // Status
    Q_PROPERTY(bool chargingActive READ chargingActive WRITE setChargingActive NOTIFY chargingActiveChanged)
    Q_PROPERTY(bool readyToDrive READ readyToDrive WRITE setReadyToDrive NOTIFY readyToDriveChanged)

    // Critical Warnings
    Q_PROPERTY(bool bmsWarning READ bmsWarning WRITE setBmsWarning NOTIFY bmsWarningChanged)
    Q_PROPERTY(bool hvWarning READ hvWarning WRITE setHvWarning NOTIFY hvWarningChanged)
    Q_PROPERTY(bool tempWarning READ tempWarning WRITE setTempWarning NOTIFY tempWarningChanged)
    Q_PROPERTY(bool motorFault READ motorFault WRITE setMotorFault NOTIFY motorFaultChanged)
    Q_PROPERTY(bool reducedPower READ reducedPower WRITE setReducedPower NOTIFY reducedPowerChanged)

    // Indicators
    Q_PROPERTY(bool leftTurnSignal READ leftTurnSignal WRITE setLeftTurnSignal NOTIFY leftTurnSignalChanged)
    Q_PROPERTY(bool rightTurnSignal READ rightTurnSignal WRITE setRightTurnSignal NOTIFY rightTurnSignalChanged)
    Q_PROPERTY(bool highBeam READ highBeam WRITE setHighBeam NOTIFY highBeamChanged)
    Q_PROPERTY(bool regeneratonActive READ regeneratonActive WRITE setRegeneratonActive NOTIFY regeneratonActiveChanged)
    Q_PROPERTY(bool tractionControl READ tractionControl WRITE setTractionControl NOTIFY tractionControlChanged)
    Q_PROPERTY(bool absWarning READ absWarning WRITE setAbsWarning NOTIFY absWarningChanged)
    Q_PROPERTY(bool parkingBrake READ parkingBrake WRITE setParkingBrake NOTIFY parkingBrakeChanged)
    Q_PROPERTY(bool seatbeltWarning READ seatbeltWarning WRITE setSeatbeltWarning NOTIFY seatbeltWarningChanged)
    Q_PROPERTY(bool doorAjar READ doorAjar WRITE setDoorAjar NOTIFY doorAjarChanged)
    Q_PROPERTY(bool low12V READ low12V WRITE setLow12V NOTIFY low12VChanged)
    
    // Navigation Data
    Q_PROPERTY(QString nextTurnIcon READ nextTurnIcon WRITE setNextTurnIcon NOTIFY nextTurnIconChanged)
    Q_PROPERTY(QString nextTurnDistance READ nextTurnDistance WRITE setNextTurnDistance NOTIFY nextTurnDistanceChanged)
    Q_PROPERTY(QString destinationEta READ destinationEta WRITE setDestinationEta NOTIFY destinationEtaChanged)
    Q_PROPERTY(float distToDestination READ distToDestination WRITE setDistToDestination NOTIFY distToDestinationChanged)
    Q_PROPERTY(double gpsLatitude READ gpsLatitude WRITE setGpsLatitude NOTIFY gpsLatitudeChanged)
    Q_PROPERTY(double gpsLongitude READ gpsLongitude WRITE setGpsLongitude NOTIFY gpsLongitudeChanged)
    Q_PROPERTY(float heading READ heading WRITE setHeading NOTIFY headingChanged)
    
    // UI State
    Q_PROPERTY(bool nightMode READ nightMode WRITE setNightMode NOTIFY nightModeChanged)
    Q_PROPERTY(bool fullScreenMap READ fullScreenMap WRITE setFullScreenMap NOTIFY fullScreenMapChanged)

public:
    explicit EVVehicleData(QObject *parent = nullptr);

    enum DriveMode {
        Eco,
        Normal,
        Sport,
        Custom
    };
    Q_ENUM(DriveMode)

    enum RegenLevel {
        Low,
        Medium,
        High,
        OnePedal
    };
    Q_ENUM(RegenLevel)

    // Getters
    float speed() const { return m_speed; }
    float odometer() const { return m_odometer; }
    float tripDistanceA() const { return m_tripDistanceA; }
    float tripDistanceB() const { return m_tripDistanceB; }
    float batterySoc() const { return m_batterySoc; }
    float batteryVoltage() const { return m_batteryVoltage; }
    float batteryCurrent() const { return m_batteryCurrent; }
    float batteryTempAvg() const { return m_batteryTempAvg; }
    float batterySoh() const { return m_batterySoh; }
    float powerOutput() const { return m_powerOutput; }
    float instantConsumption() const { return m_instantConsumption; }
    float estimatedRange() const { return m_estimatedRange; }
    int timeToEmpty() const { return m_timeToEmpty; }
    int timeToFull() const { return m_timeToFull; }
    float averageConsumption() const { return m_averageConsumption; }
    QList<float> consumptionHistory() const { return m_consumptionHistory; }
    float motorTemp() const { return m_motorTemp; }
    float controllerTemp() const { return m_controllerTemp; }
    float motorRpm() const { return m_motorRpm; }
    DriveMode driveMode() const { return m_driveMode; }
    RegenLevel regenLevel() const { return m_regenLevel; }
    bool chargingActive() const { return m_chargingActive; }
    bool readyToDrive() const { return m_readyToDrive; }
    bool bmsWarning() const { return m_bmsWarning; }
    bool hvWarning() const { return m_hvWarning; }
    bool tempWarning() const { return m_tempWarning; }
    bool motorFault() const { return m_motorFault; }
    bool reducedPower() const { return m_reducedPower; }
    bool leftTurnSignal() const { return m_leftTurnSignal; }
    bool rightTurnSignal() const { return m_rightTurnSignal; }
    bool highBeam() const { return m_highBeam; }
    bool regeneratonActive() const { return m_regeneratonActive; }
    bool tractionControl() const { return m_tractionControl; }
    bool absWarning() const { return m_absWarning; }
    bool parkingBrake() const { return m_parkingBrake; }
    bool seatbeltWarning() const { return m_seatbeltWarning; }
    bool doorAjar() const { return m_doorAjar; }
    bool low12V() const { return m_low12V; }
    QString nextTurnIcon() const { return m_nextTurnIcon; }
    QString nextTurnDistance() const { return m_nextTurnDistance; }
    QString destinationEta() const { return m_destinationEta; }
    float distToDestination() const { return m_distToDestination; }
    double gpsLatitude() const { return m_gpsLatitude; }
    double gpsLongitude() const { return m_gpsLongitude; }
    float heading() const { return m_heading; }
    bool nightMode() const { return m_nightMode; }
    bool fullScreenMap() const { return m_fullScreenMap; }

public slots:
    // Setters
    void setSpeed(float speed);
    void setOdometer(float odometer);
    void setTripDistanceA(float tripDistanceA);
    void setTripDistanceB(float tripDistanceB);
    void setBatterySoc(float batterySoc);
    void setBatteryVoltage(float batteryVoltage);
    void setBatteryCurrent(float batteryCurrent);
    void setBatteryTempAvg(float batteryTempAvg);
    void setBatterySoh(float batterySoh);
    void setPowerOutput(float powerOutput);
    void setInstantConsumption(float instantConsumption);
    void setEstimatedRange(float estimatedRange);
    void setTimeToEmpty(int timeToEmpty);
    void setTimeToFull(int timeToFull);
    void setAverageConsumption(float averageConsumption);
    void setConsumptionHistory(const QList<float> &consumptionHistory);
    void setMotorTemp(float motorTemp);
    void setControllerTemp(float controllerTemp);
    void setMotorRpm(float motorRpm);
    void setDriveMode(DriveMode driveMode);
    void setRegenLevel(RegenLevel regenLevel);
    void setChargingActive(bool chargingActive);
    void setReadyToDrive(bool readyToDrive);
    void setBmsWarning(bool bmsWarning);
    void setHvWarning(bool hvWarning);
    void setTempWarning(bool tempWarning);
    void setMotorFault(bool motorFault);
    void setReducedPower(bool reducedPower);
    void setLeftTurnSignal(bool leftTurnSignal);
    void setRightTurnSignal(bool rightTurnSignal);
    void setHighBeam(bool highBeam);
    void setRegeneratonActive(bool regeneratonActive);
    void setTractionControl(bool tractionControl);
    void setAbsWarning(bool absWarning);
    void setParkingBrake(bool parkingBrake);
    void setSeatbeltWarning(bool seatbeltWarning);
    void setDoorAjar(bool doorAjar);
    void setLow12V(bool low12V);
    void setNextTurnIcon(const QString &nextTurnIcon);
    void setNextTurnDistance(const QString &nextTurnDistance);
    void setDestinationEta(const QString &destinationEta);
    void setDistToDestination(float distToDestination);
    void setGpsLatitude(double gpsLatitude);
    void setGpsLongitude(double gpsLongitude);
    void setHeading(float heading);
    void setNightMode(bool nightMode);
    void setFullScreenMap(bool fullScreenMap);

    // Simulation helper
    void updateFromSimulation(const QVariantMap& data);

signals:
    void speedChanged();
    void odometerChanged();
    void tripDistanceAChanged();
    void tripDistanceBChanged();
    void batterySocChanged();
    void batteryVoltageChanged();
    void batteryCurrentChanged();
    void batteryTempAvgChanged();
    void batterySohChanged();
    void powerOutputChanged();
    void instantConsumptionChanged();
    void estimatedRangeChanged();
    void timeToEmptyChanged();
    void timeToFullChanged();
    void averageConsumptionChanged();
    void consumptionHistoryChanged();
    void motorTempChanged();
    void controllerTempChanged();
    void motorRpmChanged();
    void driveModeChanged();
    void regenLevelChanged();
    void chargingActiveChanged();
    void readyToDriveChanged();
    void bmsWarningChanged();
    void hvWarningChanged();
    void tempWarningChanged();
    void motorFaultChanged();
    void reducedPowerChanged();
    void leftTurnSignalChanged();
    void rightTurnSignalChanged();
    void highBeamChanged();
    void regeneratonActiveChanged();
    void tractionControlChanged();
    void absWarningChanged();
    void parkingBrakeChanged();
    void seatbeltWarningChanged();
    void doorAjarChanged();
    void low12VChanged();
    void nextTurnIconChanged();
    void nextTurnDistanceChanged();
    void destinationEtaChanged();
    void distToDestinationChanged();
    void gpsLatitudeChanged();
    void gpsLongitudeChanged();
    void headingChanged();
    void nightModeChanged();
    void fullScreenMapChanged();


private:
    float m_speed = 0.0f;
    float m_odometer = 0.0f;
    float m_tripDistanceA = 0.0f;
    float m_tripDistanceB = 0.0f;
    float m_batterySoc = 0.0f;
    float m_batteryVoltage = 0.0f;
    float m_batteryCurrent = 0.0f;
    float m_batteryTempAvg = 0.0f;
    float m_batterySoh = 100.0f;
    float m_powerOutput = 0.0f;
    float m_instantConsumption = 0.0f;
    float m_estimatedRange = 0.0f;
    int m_timeToEmpty = 0;
    int m_timeToFull = 0;
    float m_averageConsumption = 0.0f;
    QList<float> m_consumptionHistory;
    float m_motorTemp = 0.0f;
    float m_controllerTemp = 0.0f;
    float m_motorRpm = 0.0f;
    DriveMode m_driveMode = Normal;
    RegenLevel m_regenLevel = Medium;
    bool m_chargingActive = false;
    bool m_readyToDrive = false;
    bool m_bmsWarning = false;
    bool m_hvWarning = false;
    bool m_tempWarning = false;
    bool m_motorFault = false;
    bool m_reducedPower = false;
    bool m_leftTurnSignal = false;
    bool m_rightTurnSignal = false;
    bool m_highBeam = false;
    bool m_regeneratonActive = false;
    bool m_tractionControl = false;
    bool m_absWarning = false;
    bool m_parkingBrake = false;
    bool m_seatbeltWarning = false;
    bool m_doorAjar = false;
    bool m_low12V = false;
    
    QString m_nextTurnIcon = "";
    QString m_nextTurnDistance = "";
    QString m_destinationEta = "";
    float m_distToDestination = 0.0f;
    double m_gpsLatitude = 28.6139;
    double m_gpsLongitude = 77.2090;
    float m_heading = 0.0f;
    bool m_nightMode = true; // Default to night/dark mode
    bool m_fullScreenMap = false;
    
    // Range calculation smoothing
    float m_previousRange = 0.0f;
    float m_smoothedEfficiency = 180.0f;  // Wh/km
};

#endif // EVVEHICLEDATA_H
