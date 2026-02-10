import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "."

Item {
    id: root
    anchors.fill: parent
    
    // Properties bound to VehicleData
    property bool active: VehicleData.chargingActive
    property real soc: VehicleData.batterySoc
    property real power: Math.abs(VehicleData.powerOutput)
    property real batteryTemp: VehicleData.batteryTempAvg
    
    // Time remaining calculation
    property string timeRemaining: {
        if (power < 1.0) return "--:--"
        var kwhNeeded = (100 - soc) * 0.65
        var hours = kwhNeeded / power
        var h = Math.floor(hours)
        var m = Math.floor((hours - h) * 60)
        return h + "h " + m + "m"
    }

    Rectangle {
        anchors.fill: parent
        color: "#050505"
        
        // ── Ambient Floating Particles ──
        Repeater {
            model: 12
            Rectangle {
                id: particle
                width: 6 + Math.random() * 10
                height: width
                radius: width / 2
                color: Style.accent
                opacity: 0.0
                x: parent.width * 0.2 + Math.random() * parent.width * 0.6
                y: parent.height
                
                SequentialAnimation on y {
                    running: active
                    loops: Animation.Infinite
                    PauseAnimation { duration: index * 400 }
                    NumberAnimation {
                        from: particle.parent ? particle.parent.height : 480
                        to: -20
                        duration: 3000 + Math.random() * 2000
                        easing.type: Easing.OutQuad
                    }
                }
                
                SequentialAnimation on opacity {
                    running: active
                    loops: Animation.Infinite
                    PauseAnimation { duration: index * 400 }
                    NumberAnimation { to: 0.4; duration: 600 }
                    NumberAnimation { to: 0.15; duration: 2000 }
                    NumberAnimation { to: 0.0; duration: 400 }
                    PauseAnimation { duration: 1000 }
                }
            }
        }
        
        ColumnLayout {
            anchors.centerIn: parent
            spacing: 16

            // ── CHARGING Title ──
            Text {
                text: "⚡ CHARGING"
                color: Style.accent
                font.pixelSize: 36
                font.bold: true
                font.letterSpacing: 8
                Layout.alignment: Qt.AlignHCenter
                
                SequentialAnimation on opacity {
                    loops: Animation.Infinite
                    NumberAnimation { from: 0.5; to: 1.0; duration: 1200; easing.type: Easing.InOutSine }
                    NumberAnimation { from: 1.0; to: 0.5; duration: 1200; easing.type: Easing.InOutSine }
                }
            }

            // ── Battery Graphic ──
            Item {
                id: batteryGraphic
                Layout.preferredWidth: 320
                Layout.preferredHeight: 160
                Layout.alignment: Qt.AlignHCenter
                
                // Battery Body
                Rectangle {
                    id: batteryBody
                    width: 280
                    height: 140
                    anchors.centerIn: parent
                    color: "transparent"
                    border.color: "#555"
                    border.width: 3
                    radius: 16
                    
                    // Inner dark background
                    Rectangle {
                        anchors.fill: parent
                        anchors.margins: 4
                        color: "#111"
                        radius: 12
                    }
                    
                    // ── Liquid Fill ──
                    Item {
                        id: fillArea
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        anchors.margins: 6
                        height: (parent.height - 12) * Math.min(soc / 100.0, 1.0)
                        clip: true
                        
                        Behavior on height {
                            NumberAnimation { duration: 800; easing.type: Easing.OutCubic }
                        }
                        
                        // Main fill gradient
                        Rectangle {
                            anchors.fill: parent
                            radius: 10
                            gradient: Gradient {
                                GradientStop { position: 0.0; color: Qt.lighter(Style.accent, 1.4) }
                                GradientStop { position: 0.5; color: Style.accent }
                                GradientStop { position: 1.0; color: Qt.darker(Style.accent, 1.3) }
                            }
                        }

                        // Wave effect overlay (top of liquid)
                        Rectangle {
                            id: wave1
                            width: parent.width * 2
                            height: 16
                            y: -6
                            radius: 8
                            color: Qt.lighter(Style.accent, 1.6)
                            opacity: 0.3
                            
                            NumberAnimation on x {
                                running: active
                                loops: Animation.Infinite
                                from: -parent.width
                                to: 0
                                duration: 3000
                                easing.type: Easing.InOutSine
                            }
                        }
                        
                        Rectangle {
                            id: wave2
                            width: parent.width * 2
                            height: 12
                            y: -3
                            radius: 6
                            color: Qt.lighter(Style.accent, 1.8)
                            opacity: 0.2
                            
                            NumberAnimation on x {
                                running: active
                                loops: Animation.Infinite
                                from: 0
                                to: -parent.width
                                duration: 2400
                                easing.type: Easing.InOutSine
                            }
                        }
                        
                        // Shimmer sweep
                        Rectangle {
                            id: shimmer
                            width: 60
                            height: parent.height
                            radius: 10
                            opacity: 0.25
                            gradient: Gradient {
                                orientation: Gradient.Horizontal
                                GradientStop { position: 0.0; color: "transparent" }
                                GradientStop { position: 0.5; color: "white" }
                                GradientStop { position: 1.0; color: "transparent" }
                            }
                            
                            SequentialAnimation on x {
                                running: active
                                loops: Animation.Infinite
                                NumberAnimation {
                                    from: -60
                                    to: fillArea.width + 60
                                    duration: 2000
                                    easing.type: Easing.InOutQuad
                                }
                                PauseAnimation { duration: 1500 }
                            }
                        }
                        
                        // Bubble particles inside liquid
                        Repeater {
                            model: 6
                            Rectangle {
                                width: 4 + Math.random() * 6
                                height: width
                                radius: width / 2
                                color: "white"
                                opacity: 0.3
                                x: 20 + Math.random() * (fillArea.width - 40)
                                
                                SequentialAnimation on y {
                                    running: active
                                    loops: Animation.Infinite
                                    PauseAnimation { duration: index * 600 }
                                    NumberAnimation {
                                        from: fillArea.height
                                        to: 0
                                        duration: 1500 + Math.random() * 1000
                                    }
                                }
                                
                                SequentialAnimation on opacity {
                                    running: active
                                    loops: Animation.Infinite
                                    PauseAnimation { duration: index * 600 }
                                    NumberAnimation { to: 0.5; duration: 300 }
                                    NumberAnimation { to: 0.0; duration: 1200 }
                                    PauseAnimation { duration: 500 }
                                }
                            }
                        }
                    }
                    
                    // ── Lightning Bolt (centered on battery) ──
                    Text {
                        text: "⚡"
                        font.pixelSize: 64
                        anchors.centerIn: parent
                        color: "#FFFFFF"
                        opacity: 0.9
                        z: 10
                        
                        SequentialAnimation on scale {
                            running: active
                            loops: Animation.Infinite
                            NumberAnimation { to: 1.25; duration: 600; easing.type: Easing.InOutSine }
                            NumberAnimation { to: 0.95; duration: 600; easing.type: Easing.InOutSine }
                        }
                        
                        SequentialAnimation on opacity {
                            running: active
                            loops: Animation.Infinite
                            NumberAnimation { from: 0.7; to: 1.0; duration: 400 }
                            NumberAnimation { from: 1.0; to: 0.7; duration: 800 }
                        }
                    }
                }
                
                // Battery Terminal (positive nub on right)
                Rectangle {
                    width: 14
                    height: 50
                    anchors.left: batteryBody.right
                    anchors.leftMargin: -3
                    anchors.verticalCenter: batteryBody.verticalCenter
                    color: "#555"
                    radius: 6
                }
            }

            // ── Big SoC Percentage ──
            Text {
                text: Math.round(soc) + "%"
                color: "white"
                font.pixelSize: 80
                font.family: Style.monoFont
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
            }

            // ── Animated Energy Flow Dots ──
            Row {
                Layout.alignment: Qt.AlignHCenter
                spacing: 12
                
                Repeater {
                    model: 5
                    Rectangle {
                        width: 10
                        height: 10
                        radius: 5
                        color: Style.accent
                        
                        SequentialAnimation on opacity {
                            running: active
                            loops: Animation.Infinite
                            PauseAnimation { duration: index * 180 }
                            NumberAnimation { from: 0.15; to: 1.0; duration: 300; easing.type: Easing.OutQuad }
                            NumberAnimation { from: 1.0; to: 0.15; duration: 500; easing.type: Easing.InQuad }
                            PauseAnimation { duration: 200 }
                        }
                        
                        SequentialAnimation on scale {
                            running: active
                            loops: Animation.Infinite
                            PauseAnimation { duration: index * 180 }
                            NumberAnimation { from: 0.6; to: 1.4; duration: 300 }
                            NumberAnimation { from: 1.4; to: 0.6; duration: 500 }
                            PauseAnimation { duration: 200 }
                        }
                    }
                }
            }

            // ── Stats Grid ──
            GridLayout {
                columns: 3
                rowSpacing: 12
                columnSpacing: 40
                Layout.alignment: Qt.AlignHCenter
                
                // Power
                Column {
                    Text { text: "POWER"; color: "#666"; font.pixelSize: 12; font.letterSpacing: 2; anchors.horizontalCenter: parent.horizontalCenter }
                    Text { text: power.toFixed(1) + " kW"; color: Style.accent; font.pixelSize: 28; font.family: Style.monoFont; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                }
                
                // Time Remaining
                Column {
                    Text { text: "REMAINING"; color: "#666"; font.pixelSize: 12; font.letterSpacing: 2; anchors.horizontalCenter: parent.horizontalCenter }
                    Text { text: timeRemaining; color: "white"; font.pixelSize: 28; font.family: Style.monoFont; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                }
                
                // Temperature
                Column {
                    Text { text: "BATTERY"; color: "#666"; font.pixelSize: 12; font.letterSpacing: 2; anchors.horizontalCenter: parent.horizontalCenter }
                    Text {
                        text: batteryTemp.toFixed(1) + "°C"
                        color: batteryTemp > 40 ? Style.danger : batteryTemp > 35 ? Style.warning : "white"
                        font.pixelSize: 28; font.family: Style.monoFont; font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            
            // ── Footer ──
            Text {
                text: "Vehicle immobilized · Charging cable connected"
                color: "#333"
                font.pixelSize: 12
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 8
            }
        }
        
        // ── Corner Glow Orbs ──
        Repeater {
            model: 6
            Rectangle {
                width: 30 + Math.random() * 30
                height: width
                radius: width / 2
                color: Style.accent
                opacity: 0.0
                x: Math.random() * parent.width
                y: Math.random() * parent.height
                
                SequentialAnimation on opacity {
                    running: active
                    loops: Animation.Infinite
                    PauseAnimation { duration: index * 500 }
                    NumberAnimation { to: 0.08; duration: 2500; easing.type: Easing.InOutSine }
                    NumberAnimation { to: 0.02; duration: 2500; easing.type: Easing.InOutSine }
                }
                
                SequentialAnimation on scale {
                    running: active
                    loops: Animation.Infinite
                    PauseAnimation { duration: index * 500 }
                    NumberAnimation { to: 1.8; duration: 3000; easing.type: Easing.InOutSine }
                    NumberAnimation { to: 0.8; duration: 3000; easing.type: Easing.InOutSine }
                }
            }
        }
    }
}
