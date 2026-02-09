import QtQuick
import QtQuick.Shapes
import "."

Item {
    id: root
    property real power: 0 // +kW consumption, -kW regen
    property real animatedPower: 0
    
    Behavior on animatedPower {
        SmoothedAnimation { velocity: 100; duration: 300 }
    }
    onPowerChanged: animatedPower = power
    property real maxPower: 150
    property real maxRegen: 50

    width: 300
    height: 300

    // Background Arc
    Shape {
        anchors.fill: parent
        layer.enabled: true
        layer.samples: 4

        ShapePath {
            fillColor: "transparent"
            strokeColor: "#333333"
            strokeWidth: 15
            capStyle: ShapePath.FlatCap

            // Regen side (Left: 135 to 270 degrees in polar, but ShapePath starts 3 oclock is 0)
            // Let's use startAngle logic. 
            // 0 is 3 o'clock, 90 is 6 o'clock. 
            // We want gauge from 8 o'clock (regen start) to 4 o'clock (power end)
            // 8 o'clock is approx 120 deg? No:
            // 6 is 90, 9 is 180. 8 is approx 150?
            // Let's standardize: Standard gauge 135 (bottom left) to 405 (bottom right)
            // Neutral is top (270)
            
            // Let's make it simpler:
            // Vertical bar or Gauge? User asked for Arc Visualization presumably?
            // "Bi-directional gauge"
            
            PathAngleArc {
                centerX: root.width / 2
                centerY: root.height / 2
                radiusX: root.width / 2 - 20
                radiusY: root.height / 2 - 20
                startAngle: 135
                sweepAngle: 270
            }
        }
    }

    // Zero Mark
    Rectangle {
        width: 4
        height: 20
        color: "white"
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -(root.height / 2 - 20)
        rotation: 0
    }

    // Power Arc (Positive) - Starts at top (270 deg) and goes CW
    Shape {
        anchors.fill: parent
        layer.enabled: true
        layer.samples: 4
        visible: animatedPower > 0
        opacity: animatedPower > 0 ? 1.0 : 0.0
        Behavior on opacity { NumberAnimation { duration: 100 } }

        ShapePath {
            fillColor: "transparent"
            strokeColor: {
                if (animatedPower < 50) return Style.primary
                if (animatedPower < 100) return Style.powerColor
                return Style.critical
            }
            strokeWidth: 15
            capStyle: ShapePath.FlatCap

            PathAngleArc {
                centerX: root.width / 2
                centerY: root.height / 2
                radiusX: root.width / 2 - 20
                radiusY: root.height / 2 - 20
                startAngle: 270
                sweepAngle: 135 * (Math.min(animatedPower, maxPower) / maxPower)
            }
        }
    }

    // Regen Arc (Negative) - Starts at top (270 deg) and goes CCW
    Shape {
        anchors.fill: parent
        layer.enabled: true
        layer.samples: 4
        visible: animatedPower < 0
        opacity: animatedPower < 0 ? 1.0 : 0.0
        Behavior on opacity { NumberAnimation { duration: 100 } }

        ShapePath {
            fillColor: "transparent"
            strokeColor: Style.regenColor
            strokeWidth: 15
            capStyle: ShapePath.FlatCap

            PathAngleArc {
                centerX: root.width / 2
                centerY: root.height / 2
                radiusX: root.width / 2 - 20
                radiusY: root.height / 2 - 20
                startAngle: 270
                sweepAngle: -135 * (Math.min(Math.abs(animatedPower), maxRegen) / maxRegen)
            }
        }
    }

    Text {
        anchors.centerIn: parent
        text: Math.abs(animatedPower).toFixed(0) + " kW"
        color: animatedPower < 0 ? Style.regenColor : Style.textPrimary
        font.pixelSize: 32
        font.bold: true
        font.family: Style.fontFamily
    }
    
    Text {
        anchors.centerIn: parent
        anchors.verticalCenterOffset: 30
        text: animatedPower < 0 ? "REGEN" : "POWER"
        color: Style.textSecondary
        font.pixelSize: Style.fontSizeSmall
        font.family: Style.fontFamily
    }
}
