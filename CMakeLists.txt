cmake_minimum_required(VERSION 3.16)

project(EVInstrumentCluster VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Gui Network SerialBus Sql Location Positioning QuickControls2)

set(PROJECT_SOURCES
    src/main.cpp
    src/evvehicledata.cpp
    src/simulationreceiver.cpp
    src/caninterface.cpp
    src/bmsinterface.cpp
    src/gpshandler.cpp
    src/database.cpp
    src/chargingmanager.cpp
    src/energycalculator.cpp
    src/rangepredictor.cpp
    resources.qrc
    # QML Resources
    qml/main.qml
    qml/Style.qml
    qml/Speedometer.qml
    qml/PowerMeter.qml
    qml/BatteryDisplay.qml
    qml/ChargingScreen.qml
    qml/MapView.qml
    qml/WarningLights.qml
    qml/WarningOverlay.qml
    qml/TripComputer.qml
    qml/GaugeCluster.qml
    qml/BatteryHealth.qml
    qml/Cluster2W.qml
    qml/Cluster4W.qml
    qml/DevSimulator.qml
    qml/qmldir
)

add_executable(ev-cluster
    ${PROJECT_SOURCES}
)

target_link_libraries(ev-cluster PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Network
    Qt6::SerialBus
    Qt6::Sql
    Qt6::Location
    Qt6::Positioning
    Qt6::QuickControls2
)

# Copy assets and config to build directory for easier development running
add_custom_command(TARGET ev-cluster POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/config ${CMAKE_BINARY_DIR}/config
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/qml ${CMAKE_BINARY_DIR}/qml
)
