import QtQuick
import QtQuick.Layouts
import QtQuick.Shapes

Item {
    id: root
    width: 800
    height: 480
    
    Rectangle {
        anchors.fill: parent
        color: "#1a1a1a"
    }
    
    ColumnLayout {
        anchors.centerIn: parent
        spacing: 30
        
        Text {
            text: "CHARGING ACTIVE"
            color: "#00E676"
            font.pixelSize: 48
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }
        
        // Large Battery Graphic
        Item {
            width: 300
            height: 150
            Layout.alignment: Qt.AlignHCenter
            
            Rectangle {
                width: 280
                height: 120
                anchors.centerIn: parent
                color: "transparent"
                border.color: "white"
                border.width: 4
                radius: 10
                
                Rectangle {
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.margins: 10
                    width: (parent.width - 20) * (VehicleData.batterySoc / 100)
                    color: "#00E676"
                    radius: 5
                    
                    // animated gradient or pulse
                    SequentialAnimation on opacity {
                        loops: Animation.Infinite
                        NumberAnimation { from: 0.8; to: 1.0; duration: 1000 }
                        NumberAnimation { from: 1.0; to: 0.8; duration: 1000 }
                    }
                }
            }
            // Terminal
            Rectangle {
                width: 15; height: 50
                anchors.left: parent.right
                anchors.leftMargin: -10 // overlap
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                radius: 2
            }
        }
        
        Text {
            text: VehicleData.batterySoc.toFixed(0) + "%"
            color: "white"
            font.pixelSize: 64
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }
        
        // Stats Grid
        GridLayout {
            columns: 2
            rowSpacing: 20
            columnSpacing: 50
            Layout.alignment: Qt.AlignHCenter
            
            Text { text: "Power:"; color: "#888"; font.pixelSize: 24 }
            Text { text: Math.abs(VehicleData.powerOutput).toFixed(1) + " kW"; color: "white"; font.pixelSize: 24 }
            
            Text { text: "Voltage:"; color: "#888"; font.pixelSize: 24 }
            Text { text: VehicleData.batteryVoltage.toFixed(0) + " V"; color: "white"; font.pixelSize: 24 }
            
            Text { text: "Current:"; color: "#888"; font.pixelSize: 24 }
            Text { text: VehicleData.batteryCurrent.toFixed(1) + " A"; color: "white"; font.pixelSize: 24 }
            
            Text { text: "Time to Full:"; color: "#888"; font.pixelSize: 24 }
            Text { text: Math.floor(VehicleData.timeToFull / 60) + "h " + (VehicleData.timeToFull % 60) + "m"; color: "white"; font.pixelSize: 24 }
        }
    }
}
