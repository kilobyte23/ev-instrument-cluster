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

    property bool isBike: false // Default to Car (4W)

    // Root Item to handle state switching
    Item {
        anchors.fill: parent
        
        // Loader for 2W vs 4W Cluster
        Loader {
            id: clusterLoader
            anchors.fill: parent
            source: isBike ? "Cluster2W.qml" : "Cluster4W.qml"
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
            text: "WEZU TECHNOLOGIES" 
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
    
    // Dev Simulator removed - use Python simulator only
    
    // Keyboard Shortcuts
    
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
            settingsScreen.visible = false
        }
    }
}
