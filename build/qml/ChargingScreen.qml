import QtQuick
import QtQuick.Layouts
import QtQuick.Shapes
import "."

Item {
    id: root
    anchors.fill: parent
    
    // Auto-charging logic
    Timer {
        id: chargingTimer
        interval: 1000 // Update every second
        running: VehicleData.chargingActive && VehicleData.batterySoc < 100
        repeat: true
        onTriggered: {
            // Increment SOC based on charging power
            // Assuming ~7kW charging = ~1% per minute for 50kWh battery
            var chargeRate = 0.0167; // ~1% per minute = 0.0167% per second
            if (VehicleData.batterySoc < 100) {
                VehicleData.batterySoc = Math.min(100, VehicleData.batterySoc + chargeRate);
            }
        }
    }
    
    Rectangle {
        anchors.fill: parent
        color: Style.background
        
        ColumnLayout {
            anchors.centerIn: parent
            spacing: Style.spacing32
            
            // Animated Title with pulse
            Text {
                text: "⚡ CHARGING ACTIVE"
                color: Style.accent
                font.pixelSize: 48
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
                
                SequentialAnimation on opacity {
                    running: true
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.6; duration: 1200 }
                    NumberAnimation { to: 1.0; duration: 1200 }
                }
            }
            
            // Large Battery Graphic with Liquid Fill
            Item {
                width: 400
                height: 200
                Layout.alignment: Qt.AlignHCenter
                
                // Battery Outline
                Rectangle {
                    id: batteryOutline
                    width: 380
                    height: 180
                    anchors.centerIn: parent
                    color: "transparent"
                    border.color: Style.textPrimary
                    border.width: 4
                    radius: 20
                    
                    // Liquid Fill with Wave Animation
                    Rectangle {
                        id: liquidFill
                        anchors.left: parent.left
                        anchors.bottom: parent.bottom
                        anchors.margins: 8
                        width: parent.width - 16
                        height: (parent.height - 16) * (VehicleData.batterySoc / 100)
                        radius: 12
                        
                        // Gradient fill
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: Qt.lighter(Style.accent, 1.3) }
                            GradientStop { position: 1.0; color: Style.accent }
                        }
                        
                        // Smooth height animation
                        Behavior on height {
                            NumberAnimation {
                                duration: 1000
                                easing.type: Easing.OutCubic
                            }
                        }
                        
                        // Shimmer effect overlay
                        Rectangle {
                            anchors.fill: parent
                            radius: parent.radius
                            gradient: Gradient {
                                orientation: Gradient.Horizontal
                                GradientStop { position: 0.0; color: "transparent" }
                                GradientStop { position: 0.5; color: Qt.rgba(1, 1, 1, 0.3) }
                                GradientStop { position: 1.0; color: "transparent" }
                            }
                            
                            // Sliding shimmer animation
                            SequentialAnimation on x {
                                running: VehicleData.chargingActive
                                loops: Animation.Infinite
                                NumberAnimation { from: -parent.width; to: parent.width; duration: 2000 }
                            }
                        }
                    }
                    
                    // Lightning Bolt Icon with Pulse
                    Text {
                        text: "⚡"
                        font.pixelSize: 100
                        anchors.centerIn: parent
                        color: Style.background
                        z: 5
                        
                        SequentialAnimation on scale {
                            running: VehicleData.chargingActive
                            loops: Animation.Infinite
                            NumberAnimation { to: 1.3; duration: 800; easing.type: Easing.InOutSine }
                            NumberAnimation { to: 1.0; duration: 800; easing.type: Easing.InOutSine }
                        }
                        
                        SequentialAnimation on rotation {
                            running: VehicleData.chargingActive
                            loops: Animation.Infinite
                            NumberAnimation { to: -10; duration: 400 }
                            NumberAnimation { to: 10; duration: 800 }
                            NumberAnimation { to: 0; duration: 400 }
                        }
                    }
                }
                
                // Battery Terminal
                Rectangle {
                    width: 20
                    height: 80
                    anchors.left: batteryOutline.right
                    anchors.leftMargin: -5
                    anchors.verticalCenter: batteryOutline.verticalCenter
                    color: Style.textPrimary
                    radius: 5
                }
            }
            
            // Large SOC Display with Count-up Effect
            Text {
                text: VehicleData.batterySoc.toFixed(1) + "%"
                color: Style.textPrimary
                font.pixelSize: 80
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
            }
            
            // Charging Rate Indicator
            Row {
                Layout.alignment: Qt.AlignHCenter
                spacing: Style.spacing16
                
                // Animated power flow particles
                Repeater {
                    model: 5
                    Rectangle {
                        width: 12
                        height: 12
                        radius: 6
                        color: Style.accent
                        
                        SequentialAnimation on opacity {
                            running: VehicleData.chargingActive
                            loops: Animation.Infinite
                            PauseAnimation { duration: index * 200 }
                            NumberAnimation { to: 0.2; duration: 100 }
                            NumberAnimation { to: 1.0; duration: 600 }
                            NumberAnimation { to: 0.2; duration: 100 }
                        }
                        
                        SequentialAnimation on y {
                            running: VehicleData.chargingActive
                            loops: Animation.Infinite
                            PauseAnimation { duration: index * 200 }
                            NumberAnimation { from: 0; to: -20; duration: 800 }
                        }
                    }
                }
            }
            
            // Stats Grid
            GridLayout {
                columns: 2
                rowSpacing: Style.spacing16
                columnSpacing: Style.spacing48
                Layout.alignment: Qt.AlignHCenter
                
                Text { 
                    text: "Charging Power:" 
                    color: Style.textSecondary 
                    font.pixelSize: Style.fontSizeMedium 
                }
                Text { 
                    text: (Math.abs(VehicleData.powerOutput) || 7.0).toFixed(1) + " kW"
                    color: Style.accent
                    font.pixelSize: Style.fontSizeMedium
                    font.bold: true
                }
                
                Text { 
                    text: "Battery Voltage:" 
                    color: Style.textSecondary 
                    font.pixelSize: Style.fontSizeMedium 
                }
                Text { 
                    text: VehicleData.batteryVoltage.toFixed(0) + " V" 
                    color: Style.textPrimary 
                    font.pixelSize: Style.fontSizeMedium 
                    font.bold: true
                }
                
                Text { 
                    text: "Charging Current:" 
                    color: Style.textSecondary 
                    font.pixelSize: Style.fontSizeMedium 
                }
                Text { 
                    text: (Math.abs(VehicleData.batteryCurrent) || 18.0).toFixed(1) + " A"
                    color: Style.textPrimary 
                    font.pixelSize: Style.fontSizeMedium 
                    font.bold: true
                }
                
                Text { 
                    text: "Battery Temp:" 
                    color: Style.textSecondary 
                    font.pixelSize: Style.fontSizeMedium 
                }
                Text { 
                    text: VehicleData.batteryTempAvg.toFixed(1) + " °C"
                    color: VehicleData.batteryTempAvg > 35 ? Style.warning : Style.textPrimary
                    font.pixelSize: Style.fontSizeMedium 
                    font.bold: true
                }
                
                Text { 
                    text: "Time to Full:" 
                    color: Style.textSecondary 
                    font.pixelSize: Style.fontSizeMedium 
                }
                Text {
                    text: {
                        if (VehicleData.batterySoc >= 99.9) return "Complete!";
                        var remaining = Math.max(0, 100 - VehicleData.batterySoc);
                        var minutesRemaining = Math.round(remaining / 0.0167 / 60); // Based on charge rate
                        var hours = Math.floor(minutesRemaining / 60);
                        var mins = minutesRemaining % 60;
                        return hours + "h " + mins + "m";
                    }
                    color: Style.accent
                    font.pixelSize: Style.fontSizeMedium 
                    font.bold: true
                }
            }
            
            // Charging Complete Message (when 100%)
            Rectangle {
                visible: VehicleData.batterySoc >= 99.9
                width: 500
                height: 80
                radius: 40
                color: Style.accent
                Layout.alignment: Qt.AlignHCenter
                
                Text {
                    anchors.centerIn: parent
                    text: "✓ CHARGING COMPLETE"
                    color: Style.background
                    font.pixelSize: 32
                    font.bold: true
                }
                
                SequentialAnimation on scale {
                    running: visible
                    loops: Animation.Infinite
                    NumberAnimation { to: 1.05; duration: 1000 }
                    NumberAnimation { to: 1.0; duration: 1000 }
                }
            }
        }
        
        // Ambient Glow Effect (Corner particles)
        Repeater {
            model: 8
            Rectangle {
                width: 40
                height: 40
                radius: 20
                color: Style.accent
                opacity: 0.1
                x: Math.random() * parent.width
                y: Math.random() * parent.height
                
                SequentialAnimation on opacity {
                    running: VehicleData.chargingActive
                    loops: Animation.Infinite
                    PauseAnimation { duration: index * 300 }
                    NumberAnimation { to: 0.3; duration: 2000; easing.type: Easing.InOutSine }
                    NumberAnimation { to: 0.05; duration: 2000; easing.type: Easing.InOutSine }
                }
                
                SequentialAnimation on scale {
                    running: VehicleData.chargingActive
                    loops: Animation.Infinite
                    PauseAnimation { duration: index * 300 }
                    NumberAnimation { to: 2.0; duration: 2000 }
                    NumberAnimation { to: 0.5; duration: 2000 }
                }
            }
        }
    }
}
