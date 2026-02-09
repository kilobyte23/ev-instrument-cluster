import QtQuick

Item {
    id: root
    width: 20
    height: 20
    
    property bool verified: false
    property real power: 22 // kW

    Rectangle {
        width: 20
        height: 20
        radius: 10
        color: verified ? "#00E676" : "#FF9100"
        border.color: "white"
        border.width: 2
        
        Text {
            anchors.centerIn: parent
            text: "⚡"
            font.pixelSize: 12
            color: "black"
        }
        
        Rectangle {
            anchors.top: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            width: 2
            height: 5
            color: "white"
        }
    }
}
