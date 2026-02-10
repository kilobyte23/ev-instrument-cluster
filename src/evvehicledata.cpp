#include "evvehicledata.h"
#include <QDebug>

EVVehicleData::EVVehicleData(QObject *parent) : QObject(parent)
{
    // Initialize default values if needed
}

void EVVehicleData::setSpeed(float speed)
{
    if (qFuzzyCompare(m_speed, speed))
        return;
    m_speed = speed;
    emit speedChanged();
}



void EVVehicleData::setOdometer(float odometer)
{
    if (qFuzzyCompare(m_odometer, odometer))
        return;
    m_odometer = odometer;
    emit odometerChanged();
}

void EVVehicleData::setTripDistanceA(float tripDistanceA)
{
    if (qFuzzyCompare(m_tripDistanceA, tripDistanceA))
        return;
    m_tripDistanceA = tripDistanceA;
    emit tripDistanceAChanged();
}

void EVVehicleData::setTripDistanceB(float tripDistanceB)
{
    if (qFuzzyCompare(m_tripDistanceB, tripDistanceB))
        return;
    m_tripDistanceB = tripDistanceB;
    emit tripDistanceBChanged();
}

void EVVehicleData::setBatterySoc(float batterySoc)
{
    if (qFuzzyCompare(m_batterySoc, batterySoc))
        return;
    m_batterySoc = batterySoc;
    emit batterySocChanged();
    
    // Intelligent range calculation with smoothing
    float batteryCapacityKwh = 77.4f;  // 4W default
    float availableEnergyKwh = (m_batterySoc / 100.0f) * batteryCapacityKwh;
    
    // Update smoothed efficiency with exponential moving average
    // Only update when we have valid consumption data (ignore during regen)
    if (m_averageConsumption > 50.0f && m_averageConsumption < 500.0f) {
        // Alpha = 0.1 means 10% new value, 90% previous (slow, stable)
        float alpha = 0.1f;
        m_smoothedEfficiency = alpha * m_averageConsumption + (1.0f - alpha) * m_smoothedEfficiency;
    }
    
    // Use smoothed efficiency for range calculation
    float efficiencyWhPerKm = m_smoothedEfficiency;
    
    // Base range calculation: available energy / efficiency
    float baseRange = (availableEnergyKwh * 1000.0f) / efficiencyWhPerKm;
    
    // Temperature compensation factor
    float tempFactor = 1.0f;
    if (m_batteryTempAvg < 0) {
        tempFactor = 0.70f;  // 30% reduction in extreme cold
    } else if (m_batteryTempAvg < 10) {
        tempFactor = 0.85f;  // 15% reduction in cold
    } else if (m_batteryTempAvg < 20) {
        tempFactor = 0.95f;  // 5% reduction
    } else if (m_batteryTempAvg > 45) {
        tempFactor = 0.85f;  // 15% reduction in high heat
    } else if (m_batteryTempAvg > 35) {
        tempFactor = 0.95f;  // Slight reduction
    }
    
    // Apply temperature compensation
    float calculatedRange = baseRange * tempFactor;
    
    // Smooth the range output itself (prevents jumps)
    // Alpha = 0.2 means 20% new value, 80% previous
    if (m_previousRange > 0) {
        calculatedRange = 0.2f * calculatedRange + 0.8f * m_previousRange;
    }
    m_previousRange = calculatedRange;
    
    // Reserve last 5% of battery
    if (m_batterySoc < 5.0f) {
        calculatedRange = 0.0f;
    }
    
    setEstimatedRange(calculatedRange);
}

void EVVehicleData::setBatteryVoltage(float batteryVoltage)
{
    if (qFuzzyCompare(m_batteryVoltage, batteryVoltage))
        return;
    m_batteryVoltage = batteryVoltage;
    emit batteryVoltageChanged();
}

void EVVehicleData::setBatteryCurrent(float batteryCurrent)
{
    if (qFuzzyCompare(m_batteryCurrent, batteryCurrent))
        return;
    m_batteryCurrent = batteryCurrent;
    emit batteryCurrentChanged();
}

void EVVehicleData::setBatteryTempAvg(float batteryTempAvg)
{
    if (qFuzzyCompare(m_batteryTempAvg, batteryTempAvg))
        return;
    m_batteryTempAvg = batteryTempAvg;
    emit batteryTempAvgChanged();
}

void EVVehicleData::setBatterySoh(float batterySoh)
{
    if (qFuzzyCompare(m_batterySoh, batterySoh))
        return;
    m_batterySoh = batterySoh;
    emit batterySohChanged();
}

void EVVehicleData::setPowerOutput(float powerOutput)
{
    if (qFuzzyCompare(m_powerOutput, powerOutput))
        return;
    m_powerOutput = powerOutput;
    emit powerOutputChanged();
}

void EVVehicleData::setInstantConsumption(float instantConsumption)
{
    if (qFuzzyCompare(m_instantConsumption, instantConsumption))
        return;
    m_instantConsumption = instantConsumption;
    emit instantConsumptionChanged();
}

void EVVehicleData::setEstimatedRange(float estimatedRange)
{
    if (qFuzzyCompare(m_estimatedRange, estimatedRange))
        return;
    m_estimatedRange = estimatedRange;
    emit estimatedRangeChanged();
}

void EVVehicleData::setTimeToEmpty(int timeToEmpty)
{
    if (m_timeToEmpty == timeToEmpty)
        return;
    m_timeToEmpty = timeToEmpty;
    emit timeToEmptyChanged();
}

void EVVehicleData::setTimeToFull(int timeToFull)
{
    if (m_timeToFull == timeToFull) return;
    m_timeToFull = timeToFull;
    emit timeToFullChanged();
}

void EVVehicleData::setAverageConsumption(float averageConsumption)
{
    if (qFuzzyCompare(m_averageConsumption, averageConsumption))
        return;
    m_averageConsumption = averageConsumption;
    emit averageConsumptionChanged();
}

void EVVehicleData::setConsumptionHistory(const QList<float> &consumptionHistory)
{
    if (m_consumptionHistory == consumptionHistory)
        return;
    m_consumptionHistory = consumptionHistory;
    emit consumptionHistoryChanged();
}

void EVVehicleData::setMotorTemp(float motorTemp)
{
    if (qFuzzyCompare(m_motorTemp, motorTemp))
        return;
    m_motorTemp = motorTemp;
    emit motorTempChanged();
}

void EVVehicleData::setControllerTemp(float controllerTemp)
{
    if (qFuzzyCompare(m_controllerTemp, controllerTemp))
        return;
    m_controllerTemp = controllerTemp;
    emit controllerTempChanged();
}

void EVVehicleData::setMotorRpm(float motorRpm)
{
    if (qFuzzyCompare(m_motorRpm, motorRpm))
        return;
    m_motorRpm = motorRpm;
    emit motorRpmChanged();
}

void EVVehicleData::setDriveMode(DriveMode driveMode)
{
    if (m_driveMode == driveMode)
        return;
    m_driveMode = driveMode;
    emit driveModeChanged();
}

void EVVehicleData::setRegenLevel(RegenLevel regenLevel)
{
    if (m_regenLevel == regenLevel)
        return;
    m_regenLevel = regenLevel;
    emit regenLevelChanged();
}

void EVVehicleData::setChargingActive(bool chargingActive)
{
    if (m_chargingActive == chargingActive)
        return;
    m_chargingActive = chargingActive;
    emit chargingActiveChanged();
}

void EVVehicleData::setReadyToDrive(bool readyToDrive)
{
    if (m_readyToDrive == readyToDrive)
        return;
    m_readyToDrive = readyToDrive;
    emit readyToDriveChanged();
}

void EVVehicleData::setBmsWarning(bool bmsWarning)
{
    if (m_bmsWarning == bmsWarning) return;
    m_bmsWarning = bmsWarning;
    emit bmsWarningChanged();
}

void EVVehicleData::setHvWarning(bool hvWarning)
{
    if (m_hvWarning == hvWarning) return;
    m_hvWarning = hvWarning;
    emit hvWarningChanged();
}

void EVVehicleData::setTempWarning(bool tempWarning)
{
    if (m_tempWarning == tempWarning) return;
    m_tempWarning = tempWarning;
    emit tempWarningChanged();
}

void EVVehicleData::setMotorFault(bool motorFault)
{
    if (m_motorFault == motorFault) return;
    m_motorFault = motorFault;
    emit motorFaultChanged();
}

void EVVehicleData::setReducedPower(bool reducedPower)
{
    if (m_reducedPower == reducedPower) return;
    m_reducedPower = reducedPower;
    emit reducedPowerChanged();
}

void EVVehicleData::setLeftTurnSignal(bool leftTurnSignal)
{
    if (m_leftTurnSignal == leftTurnSignal) return;
    m_leftTurnSignal = leftTurnSignal;
    emit leftTurnSignalChanged();
}

void EVVehicleData::setRightTurnSignal(bool rightTurnSignal)
{
    if (m_rightTurnSignal == rightTurnSignal) return;
    m_rightTurnSignal = rightTurnSignal;
    emit rightTurnSignalChanged();
}

void EVVehicleData::setHighBeam(bool highBeam)
{
    if (m_highBeam == highBeam) return;
    m_highBeam = highBeam;
    emit highBeamChanged();
}

void EVVehicleData::setRegeneratonActive(bool regeneratonActive)
{
    if (m_regeneratonActive == regeneratonActive) return;
    m_regeneratonActive = regeneratonActive;
    emit regeneratonActiveChanged();
}

void EVVehicleData::setTractionControl(bool tractionControl)
{
    if (m_tractionControl == tractionControl) return;
    m_tractionControl = tractionControl;
    emit tractionControlChanged();
}

void EVVehicleData::setAbsWarning(bool absWarning)
{
    if (m_absWarning == absWarning) return;
    m_absWarning = absWarning;
    emit absWarningChanged();
}

void EVVehicleData::setParkingBrake(bool parkingBrake)
{
    if (m_parkingBrake == parkingBrake) return;
    m_parkingBrake = parkingBrake;
    emit parkingBrakeChanged();
}

void EVVehicleData::setSeatbeltWarning(bool seatbeltWarning)
{
    if (m_seatbeltWarning == seatbeltWarning) return;
    m_seatbeltWarning = seatbeltWarning;
    emit seatbeltWarningChanged();
}

void EVVehicleData::setDoorAjar(bool doorAjar)
{
    if (m_doorAjar == doorAjar) return;
    m_doorAjar = doorAjar;
    emit doorAjarChanged();
}

void EVVehicleData::setLow12V(bool low12V)
{
    if (m_low12V == low12V) return;
    m_low12V = low12V;
    emit low12VChanged();
}

void EVVehicleData::setNextTurnIcon(const QString &nextTurnIcon)
{
    if (m_nextTurnIcon == nextTurnIcon) return;
    m_nextTurnIcon = nextTurnIcon;
    emit nextTurnIconChanged();
}

void EVVehicleData::setNextTurnDistance(const QString &nextTurnDistance)
{
    if (m_nextTurnDistance == nextTurnDistance) return;
    m_nextTurnDistance = nextTurnDistance;
    emit nextTurnDistanceChanged();
}

void EVVehicleData::setDestinationEta(const QString &destinationEta)
{
    if (m_destinationEta == destinationEta) return;
    m_destinationEta = destinationEta;
    emit destinationEtaChanged();
}

void EVVehicleData::setDistToDestination(float distToDestination)
{
    if (qFuzzyCompare(m_distToDestination, distToDestination)) return;
    m_distToDestination = distToDestination;
    emit distToDestinationChanged();
}

void EVVehicleData::setGpsLatitude(double gpsLatitude)
{
    if (qFuzzyCompare(m_gpsLatitude, gpsLatitude)) return;
    m_gpsLatitude = gpsLatitude;
    emit gpsLatitudeChanged();
}

void EVVehicleData::setGpsLongitude(double gpsLongitude)
{
    if (qFuzzyCompare(m_gpsLongitude, gpsLongitude)) return;
    m_gpsLongitude = gpsLongitude;
    emit gpsLongitudeChanged();
}

void EVVehicleData::setHeading(float heading)
{
    if (qFuzzyCompare(m_heading, heading)) return;
    m_heading = heading;
    emit headingChanged();
}

void EVVehicleData::setNightMode(bool nightMode)
{
    if (m_nightMode == nightMode) return;
    m_nightMode = nightMode;
    emit nightModeChanged();
}

void EVVehicleData::setFullScreenMap(bool fullScreenMap)
{
    if (m_fullScreenMap == fullScreenMap) return;
    m_fullScreenMap = fullScreenMap;
    emit fullScreenMapChanged();
}

void EVVehicleData::updateFromSimulation(const QVariantMap& data)
{
    if (data.contains("speed")) setSpeed(data["speed"].toFloat());
    if (data.contains("soc")) setBatterySoc(data["soc"].toFloat());
    if (data.contains("power")) setPowerOutput(data["power"].toFloat());
    if (data.contains("range")) setEstimatedRange(data["range"].toFloat());
    if (data.contains("motor_temp")) setMotorTemp(data["motor_temp"].toFloat());
    if (data.contains("motor_rpm")) setMotorRpm(data["motor_rpm"].toFloat());
    if (data.contains("battery_voltage")) setBatteryVoltage(data["battery_voltage"].toFloat());
    if (data.contains("battery_current")) setBatteryCurrent(data["battery_current"].toFloat());
    if (data.contains("battery_temp")) setBatteryTempAvg(data["battery_temp"].toFloat());
    if (data.contains("odometer")) setOdometer(data["odometer"].toFloat());
    if (data.contains("trip_distance_a")) setTripDistanceA(data["trip_distance_a"].toFloat());
    if (data.contains("soh")) setBatterySoh(data["soh"].toFloat());
    if (data.contains("efficiency")) setAverageConsumption(data["efficiency"].toFloat());
    if (data.contains("ready")) setReadyToDrive(data["ready"].toBool());
    if (data.contains("charging")) setChargingActive(data["charging"].toBool());
    
    // Warnings
    if (data.contains("bms_warning")) setBmsWarning(data["bms_warning"].toBool());
    if (data.contains("hv_warning")) setHvWarning(data["hv_warning"].toBool());
    if (data.contains("time_to_full")) setTimeToFull(data["time_to_full"].toInt());

    // Indicators
    if (data.contains("left_signal")) setLeftTurnSignal(data["left_signal"].toBool());
    if (data.contains("right_signal")) setRightTurnSignal(data["right_signal"].toBool());
    if (data.contains("high_beam")) setHighBeam(data["high_beam"].toBool());
    
    if (data.contains("abs")) setAbsWarning(data["abs"].toBool());
    if (data.contains("tc")) setTractionControl(data["tc"].toBool());
    if (data.contains("seatbelt")) setSeatbeltWarning(data["seatbelt"].toBool());
    if (data.contains("door_ajar")) setDoorAjar(data["door_ajar"].toBool());
    if (data.contains("parking")) setParkingBrake(data["parking"].toBool());
    if (data.contains("low_12v")) setLow12V(data["low_12v"].toBool());
    
    // Nav
    if (data.contains("next_turn_dist")) setNextTurnDistance(data["next_turn_dist"].toString());
    if (data.contains("nav_active")) { /* TODO state */ }
    
    // GPS
    if (data.contains("lat")) setGpsLatitude(data["lat"].toDouble());
    if (data.contains("lon")) setGpsLongitude(data["lon"].toDouble());
    if (data.contains("heading")) setHeading(data["heading"].toFloat());
    
    // Add other fields as needed
}
