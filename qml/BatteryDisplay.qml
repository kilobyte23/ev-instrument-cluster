import QtQuick
import QtQuick.Shapes
import "."

Item {
    id: root
    property real soc: 50 // %
    property real range: 100 // km
    property bool charging: false
    
    // Animated SoC for smooth transitions
    property real animatedSoc: 0

    width: 200
    height: 100
    
    // Smooth SoC animation
    Behavior on animatedSoc {
        NumberAnimation {
            duration: 800
            easing.type: Easing.OutCubic
        }
    }
    
    onSocChanged: {
        animatedSoc = soc
    }
    
    Component.onCompleted: {
        animatedSoc = soc
    }

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

        // Fill with smooth animation
        Rectangle {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 4
            width: (parent.width - 8) * (animatedSoc / 100)
            color: {
                if (animatedSoc < 20) return "#FF1744" // Red
                if (animatedSoc < 50) return "#FFC400" // Yellow
                return "#00E676" // Green
            }
            radius: 1
            
            // Smooth color transitions
            Behavior on color {
                ColorAnimation {
                    duration: 400
                    easing.type: Easing.InOutQuad
                }
            }
        }
        
        // Charging bolt overlay with pulse
        Text {
            visible: charging
            text: "⚡"
            color: "white"
            anchors.centerIn: parent
            font.pixelSize: 20
            
            // Pulse animation when charging
            SequentialAnimation on scale {
                running: charging
                loops: Animation.Infinite
                NumberAnimation { to: 1.3; duration: 600; easing.type: Easing.InOutSine }
                NumberAnimation { to: 1.0; duration: 600; easing.type: Easing.InOutSine }
            }
            
            SequentialAnimation on opacity {
                running: charging
                loops: Animation.Infinite
                NumberAnimation { to: 0.5; duration: 600 }
                NumberAnimation { to: 1.0; duration: 600 }
            }
        }
    }

    Text {
        id: socText
        text: Math.round(animatedSoc) + "%"
        color: "white"
        font.pixelSize: 24
        font.bold: true
        font.family: Style.monoFont
        horizontalAlignment: Text.AlignHCenter
        width: 70  // Fixed width to prevent shift
        anchors.top: batteryBody.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 5
    }

    Text {
        text: range.toFixed(0) + " km"
        color: "#BBBBBB"
        font.pixelSize: 18
        font.family: Style.monoFont
        horizontalAlignment: Text.AlignHCenter
        width: 90  // Fixed width to prevent shift
        anchors.top: socText.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 2
    }
}

