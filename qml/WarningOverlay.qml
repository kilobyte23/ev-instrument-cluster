import QtQuick
import QtQuick.Layouts
import "."

Item {
    id: root
    anchors.fill: parent
    
    // Overspeed Warning (Subtle - top right corner)
    Rectangle {
        visible: VehicleData.speed > 120
        width: 200
        height: 60
        radius: 30
        color: "#CC000000"
        border.color: Style.warning
        border.width: 2
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: Style.spacing24
        z: 100
        
        Row {
            anchors.centerIn: parent
            spacing: Style.spacing8
            
            Text {
                text: "⚠️"
                font.pixelSize: 28
                color: Style.warning
                
                SequentialAnimation on opacity {
                    running: parent.parent.parent.visible
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.4; duration: 600 }
                    NumberAnimation { to: 1.0; duration: 600 }
                }
            }
            
            Column {
                spacing: 2
                
                Text {
                    text: "OVERSPEED"
                    font.pixelSize: 16
                    font.bold: true
                    color: Style.warning
                }
                
                Text {
                    text: Math.round(VehicleData.speed) + " km/h"
                    font.pixelSize: 20
                    font.bold: true
                    color: Style.textPrimary
                }
            }
        }
        
        // Subtle pulse
        SequentialAnimation on scale {
            running: visible
            loops: Animation.Infinite
            NumberAnimation { to: 1.05; duration: 800 }
            NumberAnimation { to: 1.0; duration: 800 }
        }
    }
    
    // High Temperature Warning (Critical - center overlay)
    Rectangle {
        visible: VehicleData.batteryTempAvg > 45 || VehicleData.motorTemp > 80
        width: 500
        height: 300
        radius: 20
        color: "#DD000000"
        border.color: Style.critical
        border.width: 4
        anchors.centerIn: parent
        z: 200
        
        Column {
            anchors.centerIn: parent
            spacing: Style.spacing24
            
            // Warning icon with shake
            Text {
                text: "🌡️"
                font.pixelSize: 100
                anchors.horizontalCenter: parent.horizontalCenter
                
                SequentialAnimation on rotation {
                    running: parent.parent.parent.visible
                    loops: Animation.Infinite
                    NumberAnimation { to: -15; duration: 150 }
                    NumberAnimation { to: 15; duration: 150 }
                    NumberAnimation { to: 0; duration: 150 }
                    PauseAnimation { duration: 1000 }
                }
            }
            
            Text {
                text: "HIGH TEMPERATURE WARNING"
                font.pixelSize: 28
                font.bold: true
                color: Style.critical
                anchors.horizontalCenter: parent.horizontalCenter
                
                SequentialAnimation on opacity {
                    running: parent.parent.parent.visible
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.5; duration: 500 }
                    NumberAnimation { to: 1.0; duration: 500 }
                }
            }
            
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Style.spacing32
                
                // Battery temp
                Column {
                    spacing: Style.spacing8
                    
                    Text {
                        text: "Battery"
                        font.pixelSize: 18
                        color: Style.textSecondary
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    
                    Text {
                        text: VehicleData.batteryTempAvg.toFixed(1) + "°C"
                        font.pixelSize: 36
                        font.bold: true
                        color: VehicleData.batteryTempAvg > 45 ? Style.critical : Style.textPrimary
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
                
                Rectangle {
                    width: 2
                    height: 80
                    color: Style.textMuted
                }
                
                // Motor temp
                Column {
                    spacing: Style.spacing8
                    
                    Text {
                        text: "Motor"
                        font.pixelSize: 18
                        color: Style.textSecondary
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    
                    Text {
                        text: VehicleData.motorTemp.toFixed(1) + "°C"
                        font.pixelSize: 36
                        font.bold: true
                        color: VehicleData.motorTemp > 80 ? Style.critical : Style.textPrimary
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            
            Text {
                text: "⚠️ REDUCE LOAD & MONITOR"
                font.pixelSize: 20
                color: Style.warning
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        
        // Red pulsing edge glow
        SequentialAnimation on opacity {
            running: visible
            loops: Animation.Infinite
            NumberAnimation { to: 0.8; duration: 700 }
            NumberAnimation { to: 1.0; duration: 700 }
        }
    }
    
    // Low Battery Health Warning (Center overlay)
    Rectangle {
        visible: VehicleData.batterySoh < 80
        width: 500
        height: 280
        radius: 20
        color: "#DD000000"
        border.color: Style.warning
        border.width: 4
        anchors.centerIn: parent
        z: 190
        
        Column {
            anchors.centerIn: parent
            spacing: Style.spacing24
            
            Text {
                text: "🔋"
                font.pixelSize: 80
                anchors.horizontalCenter: parent.horizontalCenter
                opacity: 0.8
            }
            
            Text {
                text: "BATTERY HEALTH LOW"
                font.pixelSize: 28
                font.bold: true
                color: Style.warning
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            Rectangle {
                width: 400
                height: 80
                radius: 10
                color: Style.backgroundSecondary
                border.color: Style.warning
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                
                Column {
                    anchors.centerIn: parent
                    spacing: Style.spacing8
                    
                    Text {
                        text: "State of Health (SOH)"
                        font.pixelSize: 16
                        color: Style.textSecondary
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    
                    Text {
                        text: VehicleData.batterySoh.toFixed(1) + "%"
                        font.pixelSize: 48
                        font.bold: true
                        color: VehicleData.batterySoh < 70 ? Style.critical : 
                               VehicleData.batterySoh < 80 ? Style.warning : Style.accent
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            
            Text {
                text: VehicleData.batterySoh < 70 ? 
                      "⚠️ SERVICE REQUIRED - BATTERY DEGRADED" :
                      "💡 Consider battery service check"
                font.pixelSize: 18
                color: VehicleData.batterySoh < 70 ? Style.critical : Style.textSecondary
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        
        // Pulse animation
        SequentialAnimation on scale {
            running: visible && VehicleData.batterySoh < 70
            loops: Animation.Infinite
            NumberAnimation { to: 1.03; duration: 800 }
            NumberAnimation { to: 1.0; duration: 800 }
        }
    }
    
    // Critical Battery Low + Speed Warning Combo (if both)
    Rectangle {
        visible: VehicleData.batterySoc < 10 && VehicleData.speed > 80
        width: 600
        height: 200
        radius: 20
        color: "#EE000000"
        border.color: Style.critical
        border.width: 5
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 100
        z: 250
        
        Column {
            anchors.centerIn: parent
            spacing: Style.spacing16
            
            Text {
                text: "🔋⚡ CRITICAL: LOW BATTERY + HIGH SPEED"
                font.pixelSize: 24
                font.bold: true
                color: Style.critical
                anchors.horizontalCenter: parent.horizontalCenter
                
                SequentialAnimation on opacity {
                    running: parent.parent.parent.visible
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.3; duration: 400 }
                    NumberAnimation { to: 1.0; duration: 400 }
                }
            }
            
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Style.spacing48
                
                Column {
                    spacing: 4
                    Text {
                        text: "Battery"
                        font.pixelSize: 16
                        color: Style.textSecondary
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        text: Math.round(VehicleData.batterySoc) + "%"
                        font.pixelSize: 48
                        font.bold: true
                        color: Style.critical
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
                
                Column {
                    spacing: 4
                    Text {
                        text: "Speed"
                        font.pixelSize: 16
                        color: Style.textSecondary
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        text: Math.round(VehicleData.speed) + " km/h"
                        font.pixelSize: 48
                        font.bold: true
                        color: Style.critical
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            
            Text {
                text: "⚠️ REDUCE SPEED IMMEDIATELY - RANGE LIMITED"
                font.pixelSize: 20
                font.bold: true
                color: Style.warning
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        
        // Aggressive pulse for critical combo
        SequentialAnimation on scale {
            running: visible
            loops: Animation.Infinite
            NumberAnimation { to: 1.08; duration: 500 }
            NumberAnimation { to: 1.0; duration: 500 }
        }
    }
}
