import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "."

Item {
    id: root
    anchors.fill: parent
    
    // 2-Wheeler: SIMPLIFIED LAYOUT (Template 3)
    // Structure: Top Bar | Speed Hero | Battery Bar | Bottom Info
    
    // TOP BAR (60px) - Essential Status Only
    Rectangle {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: Style.topBarHeight2W
        color: "#CC000000"
        z: 10
        
        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: Style.spacing24
            anchors.rightMargin: Style.spacing24
            anchors.topMargin: Style.spacing16
            anchors.bottomMargin: Style.spacing16
            spacing: Style.spacing16
            
            // Left: Ready & Mode
            Row {
                spacing: Style.spacing16
                
                Text {
                    text: VehicleData.readyToDrive ? "●" : "○"
                    color: VehicleData.readyToDrive ? Style.accent : Style.textMuted
                    font.pixelSize: Style.fontSizeMedium
                }
                
                Text {
                    text: {
                        if (VehicleData.driveMode === 0) return "ECO";
                        else if (VehicleData.driveMode === 1) return "NORMAL";
                        else return "SPORT";
                    }
                    color: {
                        if (VehicleData.driveMode === 0) return Style.accent;
                        else if (VehicleData.driveMode === 1) return Style.primary;
                        else return Style.critical;
                    }
                    font.pixelSize: Style.fontSizeLabel
                    font.bold: true
                }
            }
            
            Item { Layout.fillWidth: true }
            
            // Center: Time
            Text {
                text: Qt.formatTime(new Date(), "hh:mm")
                color: Style.textPrimary
                font.pixelSize: Style.fontSizeMedium
                font.bold: true
            }
            
            Item { Layout.fillWidth: true }
            
            // Right: Critical Warnings Only
            Row {
                spacing: Style.spacing8
                
                Text {
                    text: "⚠️"
                    font.pixelSize: Style.iconMedium
                    visible: VehicleData.batterySoc < 15
                }
                
                Text {
                    text: "🔋"
                    font.pixelSize: Style.iconMedium
                    visible: VehicleData.chargingActive
                }
                
                Text {
                    text: "🚪"
                    font.pixelSize: Style.iconMedium
                    visible: VehicleData.doorAjar // Side stand in bike mode
                }
            }
        }
    }
    
    // SPEED SECTION (300px) - HERO DISPLAY
    Item {
        id: speedSection
        anchors.top: topBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: Style.speedSectionHeight2W
        
        Column {
            anchors.centerIn: parent
            spacing: Style.spacing16
            
            // MASSIVE Speed Number for Rider Glance
            Text {
                text: Math.round(VehicleData.speed)
                color: Style.textPrimary
                font.pixelSize: Style.fontSizeHero2W
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            // Unit
            Text {
                text: "km/h"
                color: Style.textSecondary
                font.pixelSize: Style.fontSizePrimary
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
    
    // BATTERY BAR SECTION (60px) - Full Width Bar
    Rectangle {
        id: batterySection
        anchors.top: speedSection.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Style.spacing24
        height: Style.batterySectionHeight2W
        color: "transparent"
        
        RowLayout {
            anchors.fill: parent
            spacing: Style.spacing16
            
            // Battery Percentage
            Text {
                text: Math.round(VehicleData.batterySoc) + "%"
                color: VehicleData.batterySoc > 20 ? Style.textPrimary : Style.critical
                font.pixelSize: Style.fontSizePrimary
                font.bold: true
            }
            
            // Battery Progress Bar
            Rectangle {
                Layout.fillWidth: true
                height: 40
                color: Style.backgroundSecondary
                border.color: Style.textMuted
                border.width: 2
                radius: 20
                
                Rectangle {
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.margins: 4
                    width: Math.max(0, (parent.width - 8) * (VehicleData.batterySoc / 100))
                    radius: 16
                    color: VehicleData.batterySoc > 50 ? Style.accent :
                           VehicleData.batterySoc > 20 ? Style.warning : Style.critical
                }
                
                // Battery icon overlay
                Text {
                    anchors.centerIn: parent
                    text: "BATTERY"
                    color: Style.textSecondary
                    font.pixelSize: 12
                    opacity: 0.5
                }
            }
            
            // Range
            Text {
                text: Math.round(VehicleData.estimatedRange) + " km"
                color: Style.textPrimary
                font.pixelSize: Style.fontSizeSecondary
                font.bold: true
            }
        }
    }
    
    // BOTTOM INFO BAR (60px) - 4 Items Max
    Rectangle {
        id: bottomBar
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: Style.bottomBarHeight2W
        color: "#CC000000"
        
        RowLayout {
            anchors.fill: parent
            anchors.margins: Style.spacing16
            spacing: 0
            
            // Item 1: Power
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: 4
                
                Text {
                    text: VehicleData.powerOutput.toFixed(1)
                    color: VehicleData.powerOutput < 0 ? Style.accent : Style.textPrimary
                    font.pixelSize: Style.fontSizeSecondary
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: "kW"
                    color: Style.textSecondary
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            
            // Item 2: Temperature
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: 4
                
                Text {
                    text: VehicleData.motorTemp.toFixed(0) + "°"
                    color: VehicleData.motorTemp > 70 ? Style.warning : Style.textPrimary
                    font.pixelSize: Style.fontSizeSecondary
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: "Motor"
                    color: Style.textSecondary
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            
            // Item 3: Trip
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: 4
                
                Text {
                    text: VehicleData.tripDistanceA.toFixed(1)
                    color: Style.textPrimary
                    font.pixelSize: Style.fontSizeSecondary
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: "Trip km"
                    color: Style.textSecondary
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            
            // Item 4: Efficiency
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: 4
                
                Text {
                    text: VehicleData.averageConsumption.toFixed(0)
                    color: Style.textPrimary
                    font.pixelSize: Style.fontSizeSecondary
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: "Wh/km"
                    color: Style.textSecondary
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
    
    // Warning Overlay (Top Layer)
    WarningOverlay {
        anchors.fill: parent
    }
}

