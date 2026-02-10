import QtQuick
import QtQuick.Layouts

Item {
    id: root
    width: 600
    height: 80
    
    // Bindings
    property bool ready: VehicleData.readyToDrive
    property bool bmsWarning: VehicleData.bmsWarning
    property bool tempWarning: VehicleData.tempWarning || VehicleData.motorTemp > 80
    property bool lowBattery: VehicleData.batterySoc < 20
    property bool hvWarning: VehicleData.hvWarning
    property bool motorFault: VehicleData.motorFault
    property bool reducedPower: VehicleData.reducedPower
    
    property bool leftTurn: VehicleData.leftTurnSignal
    property bool rightTurn: VehicleData.rightTurnSignal
    property bool highBeam: VehicleData.highBeam
    property bool regen: VehicleData.regeneratonActive
    
    property bool seatbelt: VehicleData.seatbeltWarning
    property bool park: VehicleData.parkingBrake
    property bool abs: VehicleData.absWarning
    property bool tc: VehicleData.tractionControl
    property bool door: VehicleData.doorAjar
    property bool low12v: VehicleData.low12V

    // Status Bar Layout
    RowLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 20
        
        // --- TURN SIGNALS ---
        Text {
            text: "⬅️"
            font.pixelSize: 32
            color: root.leftTurn ? "#00E676" : "#222"
            opacity: root.leftTurn ? 1.0 : 0.1
            
            SequentialAnimation on opacity {
                running: root.leftTurn
                loops: Animation.Infinite
                NumberAnimation { to: 0.1; duration: 400 }
                NumberAnimation { to: 1.0; duration: 400 }
            }
        }
        
        // --- CRITICAL WARNINGS ---
        
        // HV Warning with pulse
        Text {
            text: "⚡HV"
            font.pixelSize: 24
            color: "red"
            visible: root.hvWarning
            
            SequentialAnimation on opacity {
                running: root.hvWarning
                loops: Animation.Infinite
                NumberAnimation { to: 0.3; duration: 500 }
                NumberAnimation { to: 1.0; duration: 500 }
            }
        }
        
        // BMS Warning with pulse
        Rectangle {
            visible: root.bmsWarning
            width: 50; height: 26
            color: "red"
            radius: 4
            Text { anchors.centerIn: parent; text: "BMS"; color: "white"; font.bold: true }
            
            SequentialAnimation on scale {
                running: root.bmsWarning
                loops: Animation.Infinite
                NumberAnimation { to: 1.1; duration: 600 }
                NumberAnimation { to: 1.0; duration: 600 }
            }
        }
        
        // Motor Fault with pulse
        Text {
            text: "⚠️ MOTOR"
            font.pixelSize: 20
            color: "red"
            visible: root.motorFault
            
            SequentialAnimation on opacity {
                running: root.motorFault
                loops: Animation.Infinite
                NumberAnimation { to: 0.3; duration: 500 }
                NumberAnimation { to: 1.0; duration: 500 }
            }
        }
        
        // Thermal
        Text {
            text: "🌡️"
            font.pixelSize: 24
            color: root.tempWarning ? "orange" : "#222"
            visible: root.tempWarning
        }
        
        // Turtle (Reduced Power)
        Text {
            text: "🐢"
            font.pixelSize: 24
            color: "orange"
            visible: root.reducedPower
        }

        // --- STANDARD SAFETY ---
        Text { text: "ABS"; color: "orange"; font.bold: true; visible: root.abs }
        Text { text: "TC"; color: "orange"; font.bold: true; visible: root.tc }
        Text { text: "BRAKE"; color: "red"; font.bold: true; visible: root.park }
        Text { text: "💺"; color: "red"; font.pixelSize: 24; visible: root.seatbelt }
        Text { text: "🚪"; color: "red"; font.pixelSize: 24; visible: root.door }
        Text { text: "🔋12V"; color: "red"; font.pixelSize: 18; font.bold: true; visible: root.low12v }

        Item { Layout.fillWidth: true } // Spacer

        // --- STANDARD INDICATORS ---
        
        // Ready
        Text {
            text: "READY"
            color: root.ready ? "#00E676" : "#222"
            font.bold: true
            font.pixelSize: 18
            visible: root.ready
        }
        
        // High Beam
        Text {
            text: "EO" // Glyph
            color: root.highBeam ? "#2979FF" : "#222"
            font.pixelSize: 24
            visible: root.highBeam
        }
        
        // Regen
        Text {
            text: "REGEN"
            color: root.regen ? "#00E676" : "#222"
            font.pixelSize: 16
            visible: root.regen
        }

        // --- RIGHT TURN ---
        Text {
            text: "➡️"
            font.pixelSize: 32
            color: root.rightTurn ? "#00E676" : "#222"
            opacity: root.rightTurn ? 1.0 : 0.1
            
            SequentialAnimation on opacity {
                running: root.rightTurn
                loops: Animation.Infinite
                NumberAnimation { to: 0.1; duration: 400 }
                NumberAnimation { to: 1.0; duration: 400 }
            }
        }
    }
}
