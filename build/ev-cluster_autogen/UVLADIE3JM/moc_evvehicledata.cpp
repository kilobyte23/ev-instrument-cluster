/****************************************************************************
** Meta object code from reading C++ file 'evvehicledata.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/evvehicledata.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'evvehicledata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13EVVehicleDataE_t {};
} // unnamed namespace

template <> constexpr inline auto EVVehicleData::qt_create_metaobjectdata<qt_meta_tag_ZN13EVVehicleDataE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "EVVehicleData",
        "speedChanged",
        "",
        "odometerChanged",
        "tripDistanceAChanged",
        "tripDistanceBChanged",
        "batterySocChanged",
        "batteryVoltageChanged",
        "batteryCurrentChanged",
        "batteryTempAvgChanged",
        "batterySohChanged",
        "powerOutputChanged",
        "instantConsumptionChanged",
        "estimatedRangeChanged",
        "timeToEmptyChanged",
        "timeToFullChanged",
        "averageConsumptionChanged",
        "consumptionHistoryChanged",
        "motorTempChanged",
        "controllerTempChanged",
        "motorRpmChanged",
        "driveModeChanged",
        "regenLevelChanged",
        "chargingActiveChanged",
        "readyToDriveChanged",
        "bmsWarningChanged",
        "hvWarningChanged",
        "tempWarningChanged",
        "motorFaultChanged",
        "reducedPowerChanged",
        "leftTurnSignalChanged",
        "rightTurnSignalChanged",
        "highBeamChanged",
        "regeneratonActiveChanged",
        "tractionControlChanged",
        "absWarningChanged",
        "parkingBrakeChanged",
        "seatbeltWarningChanged",
        "doorAjarChanged",
        "low12VChanged",
        "nextTurnIconChanged",
        "nextTurnDistanceChanged",
        "destinationEtaChanged",
        "distToDestinationChanged",
        "gpsLatitudeChanged",
        "gpsLongitudeChanged",
        "headingChanged",
        "nightModeChanged",
        "fullScreenMapChanged",
        "setSpeed",
        "speed",
        "setOdometer",
        "odometer",
        "setTripDistanceA",
        "tripDistanceA",
        "setTripDistanceB",
        "tripDistanceB",
        "setBatterySoc",
        "batterySoc",
        "setBatteryVoltage",
        "batteryVoltage",
        "setBatteryCurrent",
        "batteryCurrent",
        "setBatteryTempAvg",
        "batteryTempAvg",
        "setBatterySoh",
        "batterySoh",
        "setPowerOutput",
        "powerOutput",
        "setInstantConsumption",
        "instantConsumption",
        "setEstimatedRange",
        "estimatedRange",
        "setTimeToEmpty",
        "timeToEmpty",
        "setTimeToFull",
        "timeToFull",
        "setAverageConsumption",
        "averageConsumption",
        "setConsumptionHistory",
        "QList<float>",
        "consumptionHistory",
        "setMotorTemp",
        "motorTemp",
        "setControllerTemp",
        "controllerTemp",
        "setMotorRpm",
        "motorRpm",
        "setDriveMode",
        "DriveMode",
        "driveMode",
        "setRegenLevel",
        "RegenLevel",
        "regenLevel",
        "setChargingActive",
        "chargingActive",
        "setReadyToDrive",
        "readyToDrive",
        "setBmsWarning",
        "bmsWarning",
        "setHvWarning",
        "hvWarning",
        "setTempWarning",
        "tempWarning",
        "setMotorFault",
        "motorFault",
        "setReducedPower",
        "reducedPower",
        "setLeftTurnSignal",
        "leftTurnSignal",
        "setRightTurnSignal",
        "rightTurnSignal",
        "setHighBeam",
        "highBeam",
        "setRegeneratonActive",
        "regeneratonActive",
        "setTractionControl",
        "tractionControl",
        "setAbsWarning",
        "absWarning",
        "setParkingBrake",
        "parkingBrake",
        "setSeatbeltWarning",
        "seatbeltWarning",
        "setDoorAjar",
        "doorAjar",
        "setLow12V",
        "low12V",
        "setNextTurnIcon",
        "nextTurnIcon",
        "setNextTurnDistance",
        "nextTurnDistance",
        "setDestinationEta",
        "destinationEta",
        "setDistToDestination",
        "distToDestination",
        "setGpsLatitude",
        "gpsLatitude",
        "setGpsLongitude",
        "gpsLongitude",
        "setHeading",
        "heading",
        "setNightMode",
        "nightMode",
        "setFullScreenMap",
        "fullScreenMap",
        "updateFromSimulation",
        "QVariantMap",
        "data",
        "Eco",
        "Normal",
        "Sport",
        "Custom",
        "Low",
        "Medium",
        "High",
        "OnePedal"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'speedChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'odometerChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tripDistanceAChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tripDistanceBChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'batterySocChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'batteryVoltageChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'batteryCurrentChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'batteryTempAvgChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'batterySohChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'powerOutputChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'instantConsumptionChanged'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'estimatedRangeChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timeToEmptyChanged'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timeToFullChanged'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'averageConsumptionChanged'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'consumptionHistoryChanged'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'motorTempChanged'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'controllerTempChanged'
        QtMocHelpers::SignalData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'motorRpmChanged'
        QtMocHelpers::SignalData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'driveModeChanged'
        QtMocHelpers::SignalData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'regenLevelChanged'
        QtMocHelpers::SignalData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'chargingActiveChanged'
        QtMocHelpers::SignalData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readyToDriveChanged'
        QtMocHelpers::SignalData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bmsWarningChanged'
        QtMocHelpers::SignalData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hvWarningChanged'
        QtMocHelpers::SignalData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tempWarningChanged'
        QtMocHelpers::SignalData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'motorFaultChanged'
        QtMocHelpers::SignalData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'reducedPowerChanged'
        QtMocHelpers::SignalData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'leftTurnSignalChanged'
        QtMocHelpers::SignalData<void()>(30, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rightTurnSignalChanged'
        QtMocHelpers::SignalData<void()>(31, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'highBeamChanged'
        QtMocHelpers::SignalData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'regeneratonActiveChanged'
        QtMocHelpers::SignalData<void()>(33, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tractionControlChanged'
        QtMocHelpers::SignalData<void()>(34, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'absWarningChanged'
        QtMocHelpers::SignalData<void()>(35, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'parkingBrakeChanged'
        QtMocHelpers::SignalData<void()>(36, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'seatbeltWarningChanged'
        QtMocHelpers::SignalData<void()>(37, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'doorAjarChanged'
        QtMocHelpers::SignalData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'low12VChanged'
        QtMocHelpers::SignalData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nextTurnIconChanged'
        QtMocHelpers::SignalData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nextTurnDistanceChanged'
        QtMocHelpers::SignalData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'destinationEtaChanged'
        QtMocHelpers::SignalData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'distToDestinationChanged'
        QtMocHelpers::SignalData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gpsLatitudeChanged'
        QtMocHelpers::SignalData<void()>(44, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gpsLongitudeChanged'
        QtMocHelpers::SignalData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'headingChanged'
        QtMocHelpers::SignalData<void()>(46, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nightModeChanged'
        QtMocHelpers::SignalData<void()>(47, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'fullScreenMapChanged'
        QtMocHelpers::SignalData<void()>(48, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSpeed'
        QtMocHelpers::SlotData<void(float)>(49, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 50 },
        }}),
        // Slot 'setOdometer'
        QtMocHelpers::SlotData<void(float)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 52 },
        }}),
        // Slot 'setTripDistanceA'
        QtMocHelpers::SlotData<void(float)>(53, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 54 },
        }}),
        // Slot 'setTripDistanceB'
        QtMocHelpers::SlotData<void(float)>(55, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 56 },
        }}),
        // Slot 'setBatterySoc'
        QtMocHelpers::SlotData<void(float)>(57, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 58 },
        }}),
        // Slot 'setBatteryVoltage'
        QtMocHelpers::SlotData<void(float)>(59, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 60 },
        }}),
        // Slot 'setBatteryCurrent'
        QtMocHelpers::SlotData<void(float)>(61, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 62 },
        }}),
        // Slot 'setBatteryTempAvg'
        QtMocHelpers::SlotData<void(float)>(63, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 64 },
        }}),
        // Slot 'setBatterySoh'
        QtMocHelpers::SlotData<void(float)>(65, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 66 },
        }}),
        // Slot 'setPowerOutput'
        QtMocHelpers::SlotData<void(float)>(67, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 68 },
        }}),
        // Slot 'setInstantConsumption'
        QtMocHelpers::SlotData<void(float)>(69, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 70 },
        }}),
        // Slot 'setEstimatedRange'
        QtMocHelpers::SlotData<void(float)>(71, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 72 },
        }}),
        // Slot 'setTimeToEmpty'
        QtMocHelpers::SlotData<void(int)>(73, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 74 },
        }}),
        // Slot 'setTimeToFull'
        QtMocHelpers::SlotData<void(int)>(75, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 76 },
        }}),
        // Slot 'setAverageConsumption'
        QtMocHelpers::SlotData<void(float)>(77, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 78 },
        }}),
        // Slot 'setConsumptionHistory'
        QtMocHelpers::SlotData<void(const QList<float> &)>(79, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 80, 81 },
        }}),
        // Slot 'setMotorTemp'
        QtMocHelpers::SlotData<void(float)>(82, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 83 },
        }}),
        // Slot 'setControllerTemp'
        QtMocHelpers::SlotData<void(float)>(84, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 85 },
        }}),
        // Slot 'setMotorRpm'
        QtMocHelpers::SlotData<void(float)>(86, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 87 },
        }}),
        // Slot 'setDriveMode'
        QtMocHelpers::SlotData<void(enum DriveMode)>(88, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 89, 90 },
        }}),
        // Slot 'setRegenLevel'
        QtMocHelpers::SlotData<void(enum RegenLevel)>(91, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 92, 93 },
        }}),
        // Slot 'setChargingActive'
        QtMocHelpers::SlotData<void(bool)>(94, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 95 },
        }}),
        // Slot 'setReadyToDrive'
        QtMocHelpers::SlotData<void(bool)>(96, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 97 },
        }}),
        // Slot 'setBmsWarning'
        QtMocHelpers::SlotData<void(bool)>(98, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 99 },
        }}),
        // Slot 'setHvWarning'
        QtMocHelpers::SlotData<void(bool)>(100, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 101 },
        }}),
        // Slot 'setTempWarning'
        QtMocHelpers::SlotData<void(bool)>(102, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 103 },
        }}),
        // Slot 'setMotorFault'
        QtMocHelpers::SlotData<void(bool)>(104, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 105 },
        }}),
        // Slot 'setReducedPower'
        QtMocHelpers::SlotData<void(bool)>(106, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 107 },
        }}),
        // Slot 'setLeftTurnSignal'
        QtMocHelpers::SlotData<void(bool)>(108, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 109 },
        }}),
        // Slot 'setRightTurnSignal'
        QtMocHelpers::SlotData<void(bool)>(110, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 111 },
        }}),
        // Slot 'setHighBeam'
        QtMocHelpers::SlotData<void(bool)>(112, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 113 },
        }}),
        // Slot 'setRegeneratonActive'
        QtMocHelpers::SlotData<void(bool)>(114, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 115 },
        }}),
        // Slot 'setTractionControl'
        QtMocHelpers::SlotData<void(bool)>(116, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 117 },
        }}),
        // Slot 'setAbsWarning'
        QtMocHelpers::SlotData<void(bool)>(118, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 119 },
        }}),
        // Slot 'setParkingBrake'
        QtMocHelpers::SlotData<void(bool)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 121 },
        }}),
        // Slot 'setSeatbeltWarning'
        QtMocHelpers::SlotData<void(bool)>(122, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 123 },
        }}),
        // Slot 'setDoorAjar'
        QtMocHelpers::SlotData<void(bool)>(124, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 125 },
        }}),
        // Slot 'setLow12V'
        QtMocHelpers::SlotData<void(bool)>(126, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 127 },
        }}),
        // Slot 'setNextTurnIcon'
        QtMocHelpers::SlotData<void(const QString &)>(128, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 129 },
        }}),
        // Slot 'setNextTurnDistance'
        QtMocHelpers::SlotData<void(const QString &)>(130, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 131 },
        }}),
        // Slot 'setDestinationEta'
        QtMocHelpers::SlotData<void(const QString &)>(132, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 133 },
        }}),
        // Slot 'setDistToDestination'
        QtMocHelpers::SlotData<void(float)>(134, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 135 },
        }}),
        // Slot 'setGpsLatitude'
        QtMocHelpers::SlotData<void(double)>(136, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 137 },
        }}),
        // Slot 'setGpsLongitude'
        QtMocHelpers::SlotData<void(double)>(138, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 139 },
        }}),
        // Slot 'setHeading'
        QtMocHelpers::SlotData<void(float)>(140, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 141 },
        }}),
        // Slot 'setNightMode'
        QtMocHelpers::SlotData<void(bool)>(142, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 143 },
        }}),
        // Slot 'setFullScreenMap'
        QtMocHelpers::SlotData<void(bool)>(144, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 145 },
        }}),
        // Slot 'updateFromSimulation'
        QtMocHelpers::SlotData<void(const QVariantMap &)>(146, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 147, 148 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'speed'
        QtMocHelpers::PropertyData<float>(50, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'odometer'
        QtMocHelpers::PropertyData<float>(52, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'tripDistanceA'
        QtMocHelpers::PropertyData<float>(54, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'tripDistanceB'
        QtMocHelpers::PropertyData<float>(56, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'batterySoc'
        QtMocHelpers::PropertyData<float>(58, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'batteryVoltage'
        QtMocHelpers::PropertyData<float>(60, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'batteryCurrent'
        QtMocHelpers::PropertyData<float>(62, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'batteryTempAvg'
        QtMocHelpers::PropertyData<float>(64, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'batterySoh'
        QtMocHelpers::PropertyData<float>(66, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'powerOutput'
        QtMocHelpers::PropertyData<float>(68, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'instantConsumption'
        QtMocHelpers::PropertyData<float>(70, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'estimatedRange'
        QtMocHelpers::PropertyData<float>(72, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 11),
        // property 'timeToEmpty'
        QtMocHelpers::PropertyData<int>(74, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 12),
        // property 'timeToFull'
        QtMocHelpers::PropertyData<int>(76, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 13),
        // property 'averageConsumption'
        QtMocHelpers::PropertyData<float>(78, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 14),
        // property 'consumptionHistory'
        QtMocHelpers::PropertyData<QList<float>>(81, 0x80000000 | 80, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 15),
        // property 'motorTemp'
        QtMocHelpers::PropertyData<float>(83, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 16),
        // property 'controllerTemp'
        QtMocHelpers::PropertyData<float>(85, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 17),
        // property 'motorRpm'
        QtMocHelpers::PropertyData<float>(87, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 18),
        // property 'driveMode'
        QtMocHelpers::PropertyData<enum DriveMode>(90, 0x80000000 | 89, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 19),
        // property 'regenLevel'
        QtMocHelpers::PropertyData<enum RegenLevel>(93, 0x80000000 | 92, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 20),
        // property 'chargingActive'
        QtMocHelpers::PropertyData<bool>(95, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 21),
        // property 'readyToDrive'
        QtMocHelpers::PropertyData<bool>(97, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 22),
        // property 'bmsWarning'
        QtMocHelpers::PropertyData<bool>(99, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 23),
        // property 'hvWarning'
        QtMocHelpers::PropertyData<bool>(101, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 24),
        // property 'tempWarning'
        QtMocHelpers::PropertyData<bool>(103, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 25),
        // property 'motorFault'
        QtMocHelpers::PropertyData<bool>(105, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 26),
        // property 'reducedPower'
        QtMocHelpers::PropertyData<bool>(107, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 27),
        // property 'leftTurnSignal'
        QtMocHelpers::PropertyData<bool>(109, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 28),
        // property 'rightTurnSignal'
        QtMocHelpers::PropertyData<bool>(111, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 29),
        // property 'highBeam'
        QtMocHelpers::PropertyData<bool>(113, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 30),
        // property 'regeneratonActive'
        QtMocHelpers::PropertyData<bool>(115, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 31),
        // property 'tractionControl'
        QtMocHelpers::PropertyData<bool>(117, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 32),
        // property 'absWarning'
        QtMocHelpers::PropertyData<bool>(119, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 33),
        // property 'parkingBrake'
        QtMocHelpers::PropertyData<bool>(121, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 34),
        // property 'seatbeltWarning'
        QtMocHelpers::PropertyData<bool>(123, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 35),
        // property 'doorAjar'
        QtMocHelpers::PropertyData<bool>(125, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 36),
        // property 'low12V'
        QtMocHelpers::PropertyData<bool>(127, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 37),
        // property 'nextTurnIcon'
        QtMocHelpers::PropertyData<QString>(129, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 38),
        // property 'nextTurnDistance'
        QtMocHelpers::PropertyData<QString>(131, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 39),
        // property 'destinationEta'
        QtMocHelpers::PropertyData<QString>(133, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 40),
        // property 'distToDestination'
        QtMocHelpers::PropertyData<float>(135, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 41),
        // property 'gpsLatitude'
        QtMocHelpers::PropertyData<double>(137, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 42),
        // property 'gpsLongitude'
        QtMocHelpers::PropertyData<double>(139, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 43),
        // property 'heading'
        QtMocHelpers::PropertyData<float>(141, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 44),
        // property 'nightMode'
        QtMocHelpers::PropertyData<bool>(143, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 45),
        // property 'fullScreenMap'
        QtMocHelpers::PropertyData<bool>(145, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 46),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'DriveMode'
        QtMocHelpers::EnumData<enum DriveMode>(89, 89, QMC::EnumFlags{}).add({
            {  149, DriveMode::Eco },
            {  150, DriveMode::Normal },
            {  151, DriveMode::Sport },
            {  152, DriveMode::Custom },
        }),
        // enum 'RegenLevel'
        QtMocHelpers::EnumData<enum RegenLevel>(92, 92, QMC::EnumFlags{}).add({
            {  153, RegenLevel::Low },
            {  154, RegenLevel::Medium },
            {  155, RegenLevel::High },
            {  156, RegenLevel::OnePedal },
        }),
    };
    return QtMocHelpers::metaObjectData<EVVehicleData, qt_meta_tag_ZN13EVVehicleDataE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject EVVehicleData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13EVVehicleDataE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13EVVehicleDataE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13EVVehicleDataE_t>.metaTypes,
    nullptr
} };

void EVVehicleData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EVVehicleData *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->odometerChanged(); break;
        case 2: _t->tripDistanceAChanged(); break;
        case 3: _t->tripDistanceBChanged(); break;
        case 4: _t->batterySocChanged(); break;
        case 5: _t->batteryVoltageChanged(); break;
        case 6: _t->batteryCurrentChanged(); break;
        case 7: _t->batteryTempAvgChanged(); break;
        case 8: _t->batterySohChanged(); break;
        case 9: _t->powerOutputChanged(); break;
        case 10: _t->instantConsumptionChanged(); break;
        case 11: _t->estimatedRangeChanged(); break;
        case 12: _t->timeToEmptyChanged(); break;
        case 13: _t->timeToFullChanged(); break;
        case 14: _t->averageConsumptionChanged(); break;
        case 15: _t->consumptionHistoryChanged(); break;
        case 16: _t->motorTempChanged(); break;
        case 17: _t->controllerTempChanged(); break;
        case 18: _t->motorRpmChanged(); break;
        case 19: _t->driveModeChanged(); break;
        case 20: _t->regenLevelChanged(); break;
        case 21: _t->chargingActiveChanged(); break;
        case 22: _t->readyToDriveChanged(); break;
        case 23: _t->bmsWarningChanged(); break;
        case 24: _t->hvWarningChanged(); break;
        case 25: _t->tempWarningChanged(); break;
        case 26: _t->motorFaultChanged(); break;
        case 27: _t->reducedPowerChanged(); break;
        case 28: _t->leftTurnSignalChanged(); break;
        case 29: _t->rightTurnSignalChanged(); break;
        case 30: _t->highBeamChanged(); break;
        case 31: _t->regeneratonActiveChanged(); break;
        case 32: _t->tractionControlChanged(); break;
        case 33: _t->absWarningChanged(); break;
        case 34: _t->parkingBrakeChanged(); break;
        case 35: _t->seatbeltWarningChanged(); break;
        case 36: _t->doorAjarChanged(); break;
        case 37: _t->low12VChanged(); break;
        case 38: _t->nextTurnIconChanged(); break;
        case 39: _t->nextTurnDistanceChanged(); break;
        case 40: _t->destinationEtaChanged(); break;
        case 41: _t->distToDestinationChanged(); break;
        case 42: _t->gpsLatitudeChanged(); break;
        case 43: _t->gpsLongitudeChanged(); break;
        case 44: _t->headingChanged(); break;
        case 45: _t->nightModeChanged(); break;
        case 46: _t->fullScreenMapChanged(); break;
        case 47: _t->setSpeed((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 48: _t->setOdometer((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 49: _t->setTripDistanceA((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 50: _t->setTripDistanceB((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 51: _t->setBatterySoc((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 52: _t->setBatteryVoltage((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 53: _t->setBatteryCurrent((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 54: _t->setBatteryTempAvg((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 55: _t->setBatterySoh((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 56: _t->setPowerOutput((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 57: _t->setInstantConsumption((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 58: _t->setEstimatedRange((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 59: _t->setTimeToEmpty((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 60: _t->setTimeToFull((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 61: _t->setAverageConsumption((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 62: _t->setConsumptionHistory((*reinterpret_cast<std::add_pointer_t<QList<float>>>(_a[1]))); break;
        case 63: _t->setMotorTemp((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 64: _t->setControllerTemp((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 65: _t->setMotorRpm((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 66: _t->setDriveMode((*reinterpret_cast<std::add_pointer_t<enum DriveMode>>(_a[1]))); break;
        case 67: _t->setRegenLevel((*reinterpret_cast<std::add_pointer_t<enum RegenLevel>>(_a[1]))); break;
        case 68: _t->setChargingActive((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 69: _t->setReadyToDrive((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 70: _t->setBmsWarning((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 71: _t->setHvWarning((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 72: _t->setTempWarning((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 73: _t->setMotorFault((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 74: _t->setReducedPower((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 75: _t->setLeftTurnSignal((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 76: _t->setRightTurnSignal((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 77: _t->setHighBeam((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 78: _t->setRegeneratonActive((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 79: _t->setTractionControl((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 80: _t->setAbsWarning((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 81: _t->setParkingBrake((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 82: _t->setSeatbeltWarning((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 83: _t->setDoorAjar((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 84: _t->setLow12V((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 85: _t->setNextTurnIcon((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 86: _t->setNextTurnDistance((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 87: _t->setDestinationEta((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 88: _t->setDistToDestination((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 89: _t->setGpsLatitude((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 90: _t->setGpsLongitude((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 91: _t->setHeading((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 92: _t->setNightMode((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 93: _t->setFullScreenMap((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 94: _t->updateFromSimulation((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 62:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<float> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::speedChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::odometerChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::tripDistanceAChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::tripDistanceBChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::batterySocChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::batteryVoltageChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::batteryCurrentChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::batteryTempAvgChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::batterySohChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::powerOutputChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::instantConsumptionChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::estimatedRangeChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::timeToEmptyChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::timeToFullChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::averageConsumptionChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::consumptionHistoryChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::motorTempChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::controllerTempChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::motorRpmChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::driveModeChanged, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::regenLevelChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::chargingActiveChanged, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::readyToDriveChanged, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::bmsWarningChanged, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::hvWarningChanged, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::tempWarningChanged, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::motorFaultChanged, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::reducedPowerChanged, 27))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::leftTurnSignalChanged, 28))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::rightTurnSignalChanged, 29))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::highBeamChanged, 30))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::regeneratonActiveChanged, 31))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::tractionControlChanged, 32))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::absWarningChanged, 33))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::parkingBrakeChanged, 34))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::seatbeltWarningChanged, 35))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::doorAjarChanged, 36))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::low12VChanged, 37))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::nextTurnIconChanged, 38))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::nextTurnDistanceChanged, 39))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::destinationEtaChanged, 40))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::distToDestinationChanged, 41))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::gpsLatitudeChanged, 42))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::gpsLongitudeChanged, 43))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::headingChanged, 44))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::nightModeChanged, 45))
            return;
        if (QtMocHelpers::indexOfMethod<void (EVVehicleData::*)()>(_a, &EVVehicleData::fullScreenMapChanged, 46))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<float> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<float*>(_v) = _t->speed(); break;
        case 1: *reinterpret_cast<float*>(_v) = _t->odometer(); break;
        case 2: *reinterpret_cast<float*>(_v) = _t->tripDistanceA(); break;
        case 3: *reinterpret_cast<float*>(_v) = _t->tripDistanceB(); break;
        case 4: *reinterpret_cast<float*>(_v) = _t->batterySoc(); break;
        case 5: *reinterpret_cast<float*>(_v) = _t->batteryVoltage(); break;
        case 6: *reinterpret_cast<float*>(_v) = _t->batteryCurrent(); break;
        case 7: *reinterpret_cast<float*>(_v) = _t->batteryTempAvg(); break;
        case 8: *reinterpret_cast<float*>(_v) = _t->batterySoh(); break;
        case 9: *reinterpret_cast<float*>(_v) = _t->powerOutput(); break;
        case 10: *reinterpret_cast<float*>(_v) = _t->instantConsumption(); break;
        case 11: *reinterpret_cast<float*>(_v) = _t->estimatedRange(); break;
        case 12: *reinterpret_cast<int*>(_v) = _t->timeToEmpty(); break;
        case 13: *reinterpret_cast<int*>(_v) = _t->timeToFull(); break;
        case 14: *reinterpret_cast<float*>(_v) = _t->averageConsumption(); break;
        case 15: *reinterpret_cast<QList<float>*>(_v) = _t->consumptionHistory(); break;
        case 16: *reinterpret_cast<float*>(_v) = _t->motorTemp(); break;
        case 17: *reinterpret_cast<float*>(_v) = _t->controllerTemp(); break;
        case 18: *reinterpret_cast<float*>(_v) = _t->motorRpm(); break;
        case 19: *reinterpret_cast<enum DriveMode*>(_v) = _t->driveMode(); break;
        case 20: *reinterpret_cast<enum RegenLevel*>(_v) = _t->regenLevel(); break;
        case 21: *reinterpret_cast<bool*>(_v) = _t->chargingActive(); break;
        case 22: *reinterpret_cast<bool*>(_v) = _t->readyToDrive(); break;
        case 23: *reinterpret_cast<bool*>(_v) = _t->bmsWarning(); break;
        case 24: *reinterpret_cast<bool*>(_v) = _t->hvWarning(); break;
        case 25: *reinterpret_cast<bool*>(_v) = _t->tempWarning(); break;
        case 26: *reinterpret_cast<bool*>(_v) = _t->motorFault(); break;
        case 27: *reinterpret_cast<bool*>(_v) = _t->reducedPower(); break;
        case 28: *reinterpret_cast<bool*>(_v) = _t->leftTurnSignal(); break;
        case 29: *reinterpret_cast<bool*>(_v) = _t->rightTurnSignal(); break;
        case 30: *reinterpret_cast<bool*>(_v) = _t->highBeam(); break;
        case 31: *reinterpret_cast<bool*>(_v) = _t->regeneratonActive(); break;
        case 32: *reinterpret_cast<bool*>(_v) = _t->tractionControl(); break;
        case 33: *reinterpret_cast<bool*>(_v) = _t->absWarning(); break;
        case 34: *reinterpret_cast<bool*>(_v) = _t->parkingBrake(); break;
        case 35: *reinterpret_cast<bool*>(_v) = _t->seatbeltWarning(); break;
        case 36: *reinterpret_cast<bool*>(_v) = _t->doorAjar(); break;
        case 37: *reinterpret_cast<bool*>(_v) = _t->low12V(); break;
        case 38: *reinterpret_cast<QString*>(_v) = _t->nextTurnIcon(); break;
        case 39: *reinterpret_cast<QString*>(_v) = _t->nextTurnDistance(); break;
        case 40: *reinterpret_cast<QString*>(_v) = _t->destinationEta(); break;
        case 41: *reinterpret_cast<float*>(_v) = _t->distToDestination(); break;
        case 42: *reinterpret_cast<double*>(_v) = _t->gpsLatitude(); break;
        case 43: *reinterpret_cast<double*>(_v) = _t->gpsLongitude(); break;
        case 44: *reinterpret_cast<float*>(_v) = _t->heading(); break;
        case 45: *reinterpret_cast<bool*>(_v) = _t->nightMode(); break;
        case 46: *reinterpret_cast<bool*>(_v) = _t->fullScreenMap(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeed(*reinterpret_cast<float*>(_v)); break;
        case 1: _t->setOdometer(*reinterpret_cast<float*>(_v)); break;
        case 2: _t->setTripDistanceA(*reinterpret_cast<float*>(_v)); break;
        case 3: _t->setTripDistanceB(*reinterpret_cast<float*>(_v)); break;
        case 4: _t->setBatterySoc(*reinterpret_cast<float*>(_v)); break;
        case 5: _t->setBatteryVoltage(*reinterpret_cast<float*>(_v)); break;
        case 6: _t->setBatteryCurrent(*reinterpret_cast<float*>(_v)); break;
        case 7: _t->setBatteryTempAvg(*reinterpret_cast<float*>(_v)); break;
        case 8: _t->setBatterySoh(*reinterpret_cast<float*>(_v)); break;
        case 9: _t->setPowerOutput(*reinterpret_cast<float*>(_v)); break;
        case 10: _t->setInstantConsumption(*reinterpret_cast<float*>(_v)); break;
        case 11: _t->setEstimatedRange(*reinterpret_cast<float*>(_v)); break;
        case 12: _t->setTimeToEmpty(*reinterpret_cast<int*>(_v)); break;
        case 13: _t->setTimeToFull(*reinterpret_cast<int*>(_v)); break;
        case 14: _t->setAverageConsumption(*reinterpret_cast<float*>(_v)); break;
        case 15: _t->setConsumptionHistory(*reinterpret_cast<QList<float>*>(_v)); break;
        case 16: _t->setMotorTemp(*reinterpret_cast<float*>(_v)); break;
        case 17: _t->setControllerTemp(*reinterpret_cast<float*>(_v)); break;
        case 18: _t->setMotorRpm(*reinterpret_cast<float*>(_v)); break;
        case 19: _t->setDriveMode(*reinterpret_cast<enum DriveMode*>(_v)); break;
        case 20: _t->setRegenLevel(*reinterpret_cast<enum RegenLevel*>(_v)); break;
        case 21: _t->setChargingActive(*reinterpret_cast<bool*>(_v)); break;
        case 22: _t->setReadyToDrive(*reinterpret_cast<bool*>(_v)); break;
        case 23: _t->setBmsWarning(*reinterpret_cast<bool*>(_v)); break;
        case 24: _t->setHvWarning(*reinterpret_cast<bool*>(_v)); break;
        case 25: _t->setTempWarning(*reinterpret_cast<bool*>(_v)); break;
        case 26: _t->setMotorFault(*reinterpret_cast<bool*>(_v)); break;
        case 27: _t->setReducedPower(*reinterpret_cast<bool*>(_v)); break;
        case 28: _t->setLeftTurnSignal(*reinterpret_cast<bool*>(_v)); break;
        case 29: _t->setRightTurnSignal(*reinterpret_cast<bool*>(_v)); break;
        case 30: _t->setHighBeam(*reinterpret_cast<bool*>(_v)); break;
        case 31: _t->setRegeneratonActive(*reinterpret_cast<bool*>(_v)); break;
        case 32: _t->setTractionControl(*reinterpret_cast<bool*>(_v)); break;
        case 33: _t->setAbsWarning(*reinterpret_cast<bool*>(_v)); break;
        case 34: _t->setParkingBrake(*reinterpret_cast<bool*>(_v)); break;
        case 35: _t->setSeatbeltWarning(*reinterpret_cast<bool*>(_v)); break;
        case 36: _t->setDoorAjar(*reinterpret_cast<bool*>(_v)); break;
        case 37: _t->setLow12V(*reinterpret_cast<bool*>(_v)); break;
        case 38: _t->setNextTurnIcon(*reinterpret_cast<QString*>(_v)); break;
        case 39: _t->setNextTurnDistance(*reinterpret_cast<QString*>(_v)); break;
        case 40: _t->setDestinationEta(*reinterpret_cast<QString*>(_v)); break;
        case 41: _t->setDistToDestination(*reinterpret_cast<float*>(_v)); break;
        case 42: _t->setGpsLatitude(*reinterpret_cast<double*>(_v)); break;
        case 43: _t->setGpsLongitude(*reinterpret_cast<double*>(_v)); break;
        case 44: _t->setHeading(*reinterpret_cast<float*>(_v)); break;
        case 45: _t->setNightMode(*reinterpret_cast<bool*>(_v)); break;
        case 46: _t->setFullScreenMap(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *EVVehicleData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EVVehicleData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13EVVehicleDataE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EVVehicleData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 95)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 95;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 95)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 95;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    return _id;
}

// SIGNAL 0
void EVVehicleData::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EVVehicleData::odometerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EVVehicleData::tripDistanceAChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EVVehicleData::tripDistanceBChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void EVVehicleData::batterySocChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EVVehicleData::batteryVoltageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void EVVehicleData::batteryCurrentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void EVVehicleData::batteryTempAvgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void EVVehicleData::batterySohChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void EVVehicleData::powerOutputChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void EVVehicleData::instantConsumptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void EVVehicleData::estimatedRangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void EVVehicleData::timeToEmptyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void EVVehicleData::timeToFullChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void EVVehicleData::averageConsumptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void EVVehicleData::consumptionHistoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void EVVehicleData::motorTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void EVVehicleData::controllerTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void EVVehicleData::motorRpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void EVVehicleData::driveModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void EVVehicleData::regenLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void EVVehicleData::chargingActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void EVVehicleData::readyToDriveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void EVVehicleData::bmsWarningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void EVVehicleData::hvWarningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void EVVehicleData::tempWarningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void EVVehicleData::motorFaultChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void EVVehicleData::reducedPowerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void EVVehicleData::leftTurnSignalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void EVVehicleData::rightTurnSignalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void EVVehicleData::highBeamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void EVVehicleData::regeneratonActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void EVVehicleData::tractionControlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 32, nullptr);
}

// SIGNAL 33
void EVVehicleData::absWarningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}

// SIGNAL 34
void EVVehicleData::parkingBrakeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 34, nullptr);
}

// SIGNAL 35
void EVVehicleData::seatbeltWarningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 35, nullptr);
}

// SIGNAL 36
void EVVehicleData::doorAjarChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 36, nullptr);
}

// SIGNAL 37
void EVVehicleData::low12VChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 37, nullptr);
}

// SIGNAL 38
void EVVehicleData::nextTurnIconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void EVVehicleData::nextTurnDistanceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 39, nullptr);
}

// SIGNAL 40
void EVVehicleData::destinationEtaChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 40, nullptr);
}

// SIGNAL 41
void EVVehicleData::distToDestinationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 41, nullptr);
}

// SIGNAL 42
void EVVehicleData::gpsLatitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 42, nullptr);
}

// SIGNAL 43
void EVVehicleData::gpsLongitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 43, nullptr);
}

// SIGNAL 44
void EVVehicleData::headingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 44, nullptr);
}

// SIGNAL 45
void EVVehicleData::nightModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 45, nullptr);
}

// SIGNAL 46
void EVVehicleData::fullScreenMapChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 46, nullptr);
}
QT_WARNING_POP
