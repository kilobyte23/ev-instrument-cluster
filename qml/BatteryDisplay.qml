import QtQuick
import QtQuick.Shapes

Item {
    id: root
    property real soc: 50 // %
    property real range: 100 // km
    property bool charging: false

    width: 200
    height: 100

    // Battery Icon
    Rectangle {
        id: batteryBody
        width: 60
        height: 30
        color: "transparent"
        border.color: "white"
        border.width: 2
        radius: 4
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        
        // Terminal
        Rectangle {
            width: 4
            height: 12
            color: "white"
            anchors.left: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 2
        }

        // Fill
        Rectangle {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 4
            width: (parent.width - 8) * (soc / 100)
            color: {
                if (soc < 20) return "#FF1744" // Red
                if (soc < 50) return "#FFC400" // Yellow
                return "#00E676" // Green
            }
            radius: 1
        }
        
        // Charging bolt overlay?
        Text {
            visible: charging
            text: "⚡"
            color: "white"
            anchors.centerIn: parent
            font.pixelSize: 20
        }
    }

    Text {
        id: socText
        text: soc.toFixed(0) + "%"
        color: "white"
        font.pixelSize: 24
        font.bold: true
        anchors.top: batteryBody.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 5
    }

    Text {
        text: range.toFixed(0) + " km"
        color: "#BBBBBB"
        font.pixelSize: 18
        anchors.top: socText.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 2
    }
}
