import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "."

Item {
    id: root
    anchors.fill: parent
    
    // 4-Wheeler: DUAL GAUGE LAYOUT (Template 1)
    // Structure: Top Bar | Left Gauge | Center Battery | Right Gauge | Bottom Bar
    
    // TOP BAR (72px) - Status & Indicators
    Rectangle {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: Style.topBarHeight
        color: "#CC000000" // Semi-transparent
        z: 10
        
        RowLayout {
            anchors.fill: parent
            anchors.margins: Style.spacing24
            spacing: Style.spacing16
            
            // Left: Drive Status
            Row {
                spacing: Style.spacing16
                Layout.alignment: Qt.AlignLeft
                
                Text {
                    text: VehicleData.readyToDrive ? "READY" : "PARK"
                    color: VehicleData.readyToDrive ? Style.accent : Style.textSecondary  
                    font.pixelSize: Style.fontSizeLabel
                    font.bold: true
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
            
            // Center: Time & Date
            Column {
                Layout.alignment: Qt.AlignHCenter
                spacing: 0
                
                Text {
                    text: Qt.formatTime(new Date(), "hh:mm AP")
                    color: Style.textPrimary
                    font.pixelSize: 20
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                
                Text {
                    text: Qt.formatDate(new Date(), "ddd MMM d")
                    color: Style.textSecondary
                    font.pixelSize: Style.fontSizeSmall
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            
            Item { Layout.fillWidth: true }
            
            // Right: Temperature & Warning Cluster
            Row {
                spacing: Style.spacing16
                Layout.alignment: Qt.AlignRight
                
                Text {
                    text: VehicleData.motorTemp.toFixed(0) + "°C"
                    color: VehicleData.motorTemp > 70 ? Style.warning : Style.textSecondary
                    font.pixelSize: Style.fontSizeLabel
                }
                
                // Critical warnings only
                Row {
                    spacing: Style.spacing8
                    
                    Text {
                        text: "⚠️"
                        font.pixelSize: Style.iconSmall
                        visible: VehicleData.batterySoc < 20
                    }
                    
                    Text {
                        text: "🔋"
                        font.pixelSize: Style.iconSmall
                        visible: VehicleData.chargingActive
                    }
                }
            }
        }
    }
    
    // MAIN CONTENT AREA (504px height)
    Item {
        id: mainContent
        anchors.top: topBar.bottom
        anchors.bottom: bottomBar.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Style.spacing32
        
        RowLayout {
            anchors.fill: parent
            spacing: Style.spacing48
            
            // LEFT GAUGE (360x504px) - Speedometer
            Item {
                Layout.preferredWidth: Style.gaugeWidth
                Layout.fillHeight: true
                
                Speedometer {
                    anchors.centerIn: parent
                    width: Style.gaugeWidth
                    height: Style.gaugeWidth
                    speed: VehicleData.speed
                }
            }
            
            // CENTER SECTION (1200x504px) - Battery Hero
            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                Column {
                    anchors.centerIn: parent
                    spacing: Style.spacing24
                    width: parent.width
                    
                    // Large Battery Percentage
                    Text {
                        text: Math.round(VehicleData.batterySoc) + "%"
                        color: Style.textPrimary
                        font.pixelSize: Style.fontSizeHero
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    
                    // Battery Progress Bar
                    Rectangle {
                        width: parent.width * 0.8
                        height: 60
                        color: "transparent"
                        border.color: Style.textMuted
                        border.width: 2
                        radius: 8
                        anchors.horizontalCenter: parent.horizontalCenter
                        
                        Rectangle {
                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.margins: 4
                            width: (parent.width - 8) * (VehicleData.batterySoc / 100)
                            radius: 6
                            
                            gradient: Gradient {
                                GradientStop { 
                                    position: 0.0
                                    color: VehicleData.batterySoc > 50 ? Style.accent : 
                                           VehicleData.batterySoc > 20 ? Style.warning : Style.critical
                                }
                                GradientStop { 
                                    position: 1.0
                                    color: VehicleData.batterySoc > 50 ? Style.primary : 
                                           VehicleData.batterySoc > 20 ? Style.warning : Style.danger
                                }
                            }
                        }
                    }
                    
                    // Range Display
                    Text {
                        text: "Range: " + Math.round(VehicleData.estimatedRange) + " km"
                        color: Style.textSecondary
                        font.pixelSize: Style.fontSizePrimary
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    
                    // Battery Icon (simplified representation)
                    Text {
                        text: "🔋"
                        font.pixelSize: 64
                        anchors.horizontalCenter: parent.horizontalCenter
                        opacity: 0.6
                    }
                }
            }
            
            // RIGHT GAUGE (360x504px) - Power Meter
            Item {
                Layout.preferredWidth: Style.gaugeWidth
                Layout.fillHeight: true
                
                Column {
                    anchors.centerIn: parent
                    spacing: Style.spacing24
                    
                    // Power Value
                    Column {
                        anchors.horizontalCenter: parent.horizontalCenter
                        spacing: Style.spacing8
                        
                        Text {
                            text: VehicleData.powerOutput.toFixed(1)
                            color: VehicleData.powerOutput < 0 ? Style.accent : 
                                   VehicleData.powerOutput < 20 ? Style.primary :
                                   VehicleData.powerOutput < 50 ? Style.warning : Style.critical
                            font.pixelSize: Style.fontSizeHero
                            font.bold: true
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        
                        Text {
                            text: "kW"
                            color: Style.textSecondary
                            font.pixelSize: Style.fontSizeSecondary
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        
                        Text {
                            text: VehicleData.powerOutput < 0 ? "(Regen)" : ""
                            color: Style.accent
                            font.pixelSize: Style.fontSizeLabel
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                    
                    // Simplified Power Bar (bi-directional)
                    Rectangle {
                        width: 300
                        height: 40
                        color: Style.backgroundSecondary
                        radius: 20
                        border.color: Style.textMuted
                        border.width: 2
                        
                        // Center marker
                        Rectangle {
                            anchors.centerIn: parent
                            width: 4
                            height: parent.height
                            color: Style.textPrimary
                        }
                        
                        // Power indicator
                        Rectangle {
                            anchors.verticalCenter: parent.verticalCenter
                            x: {
                                var maxPower = 150; // Max power output
                                var maxRegen = 50;  // Max regen
                                var normalized = VehicleData.powerOutput >= 0 ? 
                                    (VehicleData.powerOutput / maxPower) : 
                                    (VehicleData.powerOutput / maxRegen);
                                return parent.width/2 + (normalized * parent.width/2) - width/2;
                            }
                            width: 12
                            height: 12
                            radius: 6
                            color: VehicleData.powerOutput < 0 ? Style.accent : Style.critical
                        }
                    }
                }
            }
        }
    }
    
    // BOTTOM BAR (144px) - Info Strip
    Rectangle {
        id: bottomBar
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: Style.bottomBarHeight
        color: "#CC000000"
        
        RowLayout {
            anchors.fill: parent
            anchors.margins: Style.spacing24
            spacing: 0
            
            // Section 1: Trip Distance
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: Style.spacing8
                
                Text {
                    text: VehicleData.tripDistanceA.toFixed(1)
                    color: Style.textPrimary
                    font.pixelSize: Style.fontSizeSecondary
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: "Trip (km)"
                    color: Style.textSecondary
                    font.pixelSize: Style.fontSizeLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            
            // Section 2: Efficiency
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: Style.spacing8
                
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
                    font.pixelSize: Style.fontSizeLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            
            // Section 3: Temperature
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: Style.spacing8
                
                Text {
                    text: VehicleData.batteryTempAvg.toFixed(0) + "°"
                    color: VehicleData.batteryTempAvg > 40 ? Style.warning : Style.textPrimary
                    font.pixelSize: Style.fontSizeSecondary
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: "Battery"
                    color: Style.textSecondary
                    font.pixelSize: Style.fontSizeLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            
            // Section 4: Odometer
            Column {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignCenter
                spacing: Style.spacing8
                
                Text {
                    text: (VehicleData.odometer / 1000).toFixed(0)
                    color: Style.textPrimary
                    font.pixelSize: Style.fontSizeSecondary
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: "Odometer (km)"
                    color: Style.textSecondary
                    font.pixelSize: Style.fontSizeLabel
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
