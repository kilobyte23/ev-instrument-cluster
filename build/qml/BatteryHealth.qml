import QtQuick

Item {
    id: root
    width: 300
    height: 200
    
    property real soh: 98.5 // %
    
    Column {
        anchors.centerIn: parent
        spacing: 10
        
        Text {
            text: "Battery Health"
            color: "#888"
            font.pixelSize: 18
        }
        
        Text {
            text: root.soh.toFixed(1) + "%"
            color: "#00E676"
            font.pixelSize: 48
            font.bold: true
        }
        
        Text {
            text: "Excellent Condition"
            color: "white"
            font.pixelSize: 16
        }
    }
}
