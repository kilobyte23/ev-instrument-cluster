import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import EVComponents 1.0
import "." // Allow access to Style singleton in same dir

Window {
    width: 1280
    height: 480 // Ultrawide standard for auto clusters
    visible: true
    title: qsTr("EV Instrument Cluster")
    color: "black"

    // Main Background
    Rectangle {
        anchors.fill: parent
        color: Style.background
    }

    // Root Item to handle state switching
    Item {
        anchors.fill: parent
        
        // Drive View (Visible when NOT charging)
        Item {
            id: driveView
            anchors.fill: parent
            visible: !VehicleData.chargingActive

            // Top Status Bar (Time, Temp, Warnings)
    RowLayout {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        height: 40

        Text {
            text: Qt.formatTime(new Date(), "hh:mm")
            color: "white"
            font.pixelSize: 20
        }
        
        Item { Layout.fillWidth: true }
        
        WarningLights {
            bmsWarning: false // Bind to backend
            tempWarning: VehicleData.motorTemp > 80
            lowBattery: VehicleData.batterySoc < 20
            ready: true
        }
        
        Item { Layout.fillWidth: true }
        
        Text {
            text: VehicleData.motorTemp.toFixed(0) + "°C"
            color: VehicleData.motorTemp > 70 ? "orange" : "#888888"
            font.pixelSize: 20
        }
    }

    // Main Content Area
    RowLayout {
        anchors.top: topBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        spacing: 40

            // Left Panel: Power & Stats
        ColumnLayout {
            Layout.preferredWidth: 300
            visible: !VehicleData.fullScreenMap
            
            PowerMeter {
                Layout.alignment: Qt.AlignHCenter
                power: VehicleData.powerOutput
            }
            
            TripComputer {
                Layout.fillWidth: true
                odometer: VehicleData.odometer
                tripA: VehicleData.tripDistanceA
                efficiency: VehicleData.averageConsumption
            }
        }

        // Center Panel: Speed & Map
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            
            // Map Navigation
            MapView {
                anchors.fill: parent
                // In a real app we'd bind these to GPS properties
                // userLat: VehicleData.gpsLatitude 
                // userLon: VehicleData.gpsLongitude
                vehicleHeading: VehicleData.heading
            }
            
            // Speedometer Overlay
            Speedometer {
                anchors.centerIn: parent
                // Scale down slightly to not obscure map too much
                scale: 0.8
                speed: VehicleData.speed
                visible: !VehicleData.fullScreenMap
            }
            
            // Minimal Speed for Full Screen
            Text {
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 20
                text: VehicleData.speed.toFixed(0)
                font.pixelSize: 64
                color: "white"
                visible: VehicleData.fullScreenMap
                style: Text.Outline; styleColor: "black"
            }
            
            // Turn-by-Turn Overlay
            Rectangle {
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 20
                width: 200
                height: 80
                color: "#CC000000"
                radius: 8
                visible: true // vehicleData.navActive
                
                RowLayout {
                    anchors.centerIn: parent
                    spacing: 15
                    Text { text: "↰"; font.pixelSize: 48; color: "white" } // Mock arrow
                    Column {
                        Text { text: VehicleData.nextTurnDistance; color: "white"; font.pixelSize: 24; font.bold: true }
                        Text { text: "Turn Left"; color: "#ccc"; font.pixelSize: 14 }
                    }
                }
            }
            
            // Map Toggle Button
            Row {
                spacing: 10
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.margins: 20
                
                Button {
                    text: VehicleData.fullScreenMap ? "Split View" : "Full Map"
                    onClicked: VehicleData.fullScreenMap = !VehicleData.fullScreenMap
                }
                
                Button {
                    text: "Settings"
                    onClicked: settingsScreen.visible = true
                }
            }
        }

        // Right Panel: Battery & Info
        ColumnLayout {
            Layout.preferredWidth: 300
            visible: !VehicleData.fullScreenMap
            
            BatteryDisplay {
                Layout.alignment: Qt.AlignHCenter
                soc: VehicleData.batterySoc
                range: VehicleData.estimatedRange
                charging: VehicleData.chargingActive
            }

            EfficiencyGraph {
                Layout.fillWidth: true
                Layout.preferredHeight: 150
            }
            
            // Drive Mode Indicator
            Rectangle {
                Layout.fillWidth: true
                height: 50
                color: "transparent"
                border.color: "#333"
                radius: 8
                
                RowLayout {
                    anchors.centerIn: parent
                    spacing: 20
                    
                    Text { text: "ECO"; color: VehicleData.driveMode === EVVehicleData.Eco ? "#00E676" : "#444"; font.bold: true }
                    Text { text: "NORMAL"; color: VehicleData.driveMode === EVVehicleData.Normal ? "#2979FF" : "#444"; font.bold: true }
                    Text { text: "SPORT"; color: VehicleData.driveMode === EVVehicleData.Sport ? "#FF1744" : "#444"; font.bold: true }
                }
            }
        }
            }
        }
    }
    
    // Charging Overlay (Visible when charging)
    ChargingScreen {
        anchors.fill: parent
        visible: VehicleData.chargingActive
        z: 10
    }
    
    // Settings Screen Overlay (Hidden by Default)
    Settings {
        id: settingsScreen
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.8
        visible: false
        z: 50
    }
    
    // Start Overlay (logo etc)
    Rectangle {
        id: startupOverlay
        anchors.fill: parent
        color: "black"
        z: 100
        opacity: 1.0
        
        Text {
            anchors.centerIn: parent
            text: "EV SYSTEM REQUEST" 
            color: Style.textPrimary
            font.pixelSize: 32
            font.bold: true
            font.letterSpacing: 5
            opacity: 0.0
            id: logoText
        }
        
        SequentialAnimation {
            id: startupSequence
            running: true
            
            // 1. Logo Fade In
            NumberAnimation { target: logoText; property: "opacity"; to: 1.0; duration: 1000; easing.type: Easing.InOutQuad }
            PauseAnimation { duration: 500 }
            
            // 2. Logo Fade Out
            NumberAnimation { target: logoText; property: "opacity"; to: 0.0; duration: 500 }
            
            // 3. Reveal Dashboard
            NumberAnimation { target: startupOverlay; property: "opacity"; to: 0.0; duration: 800 }
            
            // 4. Gauge Sweep handled by property bindings if we exposed "demoMode" or we can just trigger it here manually if we had access to the gauges directly
            // For now, the reveal is the main "startup" styling.
            // To do a real sweep, we'd need to mock the data in C++ or have a "test sweep" signal.
            
            ScriptAction {
                script: {
                    // Optional: Signal backend to do a sweep if supported
                    // console.log("Startup complete")
                }
            }
        }
    }
    
    // Dev Simulator Overlay
    DevSimulator {
        id: devSim
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.margins: 20
        z: 200 // On top of everything
    }
    
    // Hidden "Secret" Button to toggle Dev Simulator (Top Left Corner)
    MouseArea {
        anchors.top: parent.top
        anchors.left: parent.left
        width: 100
        height: 100
        z: 1000
        // Double click is still there, but we add a visible button below
        onDoubleClicked: devSim.visible = !devSim.visible
    }
    
    // Fallback: Visible "DEV" Button for non-touch users
    Button {
        text: "DEV"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 20
        z: 2000
        opacity: 0.5
        onClicked: devSim.visible = !devSim.visible
    }
    
    // Keyboard Shortcuts
    Shortcut {
        sequence: "D"
        onActivated: devSim.visible = !devSim.visible
    }
    
    Shortcut {
        sequence: "S"
        onActivated: settingsScreen.visible = !settingsScreen.visible
    }
    
    Shortcut {
        sequence: "M"
        onActivated: VehicleData.fullScreenMap = !VehicleData.fullScreenMap
    }
    
    Shortcut {
        sequence: "Esc"
        onActivated: {
            devSim.visible = false
            settingsScreen.visible = false
        }
    }
}
