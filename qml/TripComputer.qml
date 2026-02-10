import QtQuick
import QtQuick.Layouts
import "."

Item {
    id: root
    width: 250
    height: 120

    property real odometer: 0
    property real tripA: 0
    property real efficiency: 15.5 // Wh/km

    Rectangle {
        anchors.fill: parent
        color: "#111111"
        radius: 8
        border.color: "#333333"
        opacity: 0.8
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 5

        Text {
            text: "ODOMETER"
            color: "#888888"
            font.pixelSize: 10
            font.bold: true
        }

        Text {
            text: odometer.toFixed(1) + " km"
            color: "white"
            font.pixelSize: 18
            font.family: Style.monoFont
            horizontalAlignment: Text.AlignLeft
            Layout.bottomMargin: 10
            Layout.preferredWidth: 120  // Fixed width
        }

        RowLayout {
            Layout.fillWidth: true
            
            ColumnLayout {
                Layout.preferredWidth: 80  // Fixed width
                Text { text: "TRIP A"; color: "#888888"; font.pixelSize: 10 }
                Text { 
                    text: tripA.toFixed(1) + " km"
                    color: "white"
                    font.pixelSize: 14
                    font.family: Style.monoFont
                }
            }
            
            Item { Layout.fillWidth: true } // Spacer
            
            ColumnLayout {
                Layout.preferredWidth: 100  // Fixed width
                Text { text: "AVG"; color: "#888888"; font.pixelSize: 10 }
                Text { 
                    text: efficiency.toFixed(1) + " Wh/km"
                    color: "white"
                    font.pixelSize: 14
                    font.family: Style.monoFont
                }
            }
        }
    }
}
