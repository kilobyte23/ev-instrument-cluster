import QtQuick
import QtQuick.Shapes

Item {
    id: root
    width: 300
    height: 150
    
    property var historyData: [15, 18, 14, 16, 20, 15, 12, 18, 22, 19] // Wh/km or kWh/100km
    property real maxVal: 30
    property real minVal: 0

    Rectangle {
        anchors.fill: parent
        color: "#111111"
        radius: 8
        border.color: "#333333"
    }

    Text {
        text: "Consumption (last 10km)"
        color: "#888888"
        font.pixelSize: 12
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
    }

    Shape {
        anchors.fill: parent
        anchors.margins: 15
        anchors.topMargin: 30

        ShapePath {
            strokeColor: "#00E676"
            strokeWidth: 2
            fillColor: "#3300E676"
            startX: 0
            startY: root.height - 45 // Bottom
            
            // Path logic would go here dynamically based on historyData
            // For now, let's just draw a Mockup curve
            PathLine { x: 0; y: 50 }
            PathCubic { control1X: 50; control1Y: 10; control2X: 100; control2Y: 80; x: 150; y: 40 }
            PathCubic { control1X: 200; control1Y: 0; control2X: 250; control2Y: 60; x: 270; y: 30 }
            PathLine { x: 270; y: root.height - 45 }
            PathLine { x: 0; y: root.height - 45 }
        }
    }
}
