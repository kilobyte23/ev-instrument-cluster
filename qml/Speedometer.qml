import QtQuick
import QtQuick.Shapes
import "."

Item {
    id: root
    property real speed: 0
    property real animatedSpeed: 0
    
    Behavior on animatedSpeed {
        SmoothedAnimation { velocity: 150; duration: 400 }
    }
    
    // Update animatedSpeed when speed changes, but we use animatedSpeed for display
    onSpeedChanged: animatedSpeed = speed
    property real maxSpeed: 150
    property bool metric: true

    width: 300
    height: 300

    // Background Arc
    Shape {
        id: bgArc
        anchors.fill: parent
        layer.enabled: true
        layer.samples: 4 // Antialiasing

        ShapePath {
            fillColor: "transparent"
            strokeColor: "#333333"
            strokeWidth: 20
            capStyle: ShapePath.RoundCap

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

    // Value Arc
    Shape {
        id: valueArc
        anchors.fill: parent
        layer.enabled: true
        layer.samples: 4

        ShapePath {
            fillColor: "transparent"
            strokeColor: {
                var speedPercent = Math.min(animatedSpeed, maxSpeed) / maxSpeed;
                if (speedPercent < 0.5) return Style.primary;  // Cyan
                else if (speedPercent < 0.8) return Style.secondary; // Purple
                else return Style.critical; // Red
            }
            strokeWidth: 20
            capStyle: ShapePath.RoundCap

            PathAngleArc {
                centerX: root.width / 2
                centerY: root.height / 2
                radiusX: root.width / 2 - 20
                radiusY: root.height / 2 - 20
                startAngle: 135
                sweepAngle: 270 * (Math.min(animatedSpeed, maxSpeed) / maxSpeed)
            }
            
            Behavior on strokeColor { ColorAnimation { duration: 200 } }
        }
    }

    // Digital Readout
    Column {
        anchors.centerIn: parent
        
        Text {
            text: animatedSpeed.toFixed(0)
            color: Style.textPrimary
            font.pixelSize: Style.fontSizeHuge
            font.bold: true
            font.family: Style.monoFont  // Monospace to prevent jitter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        
        Text {
            text: metric ? "km/h" : "mph"
            color: Style.textSecondary
            font.pixelSize: Style.fontSizeMedium
            font.family: Style.fontFamily
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
