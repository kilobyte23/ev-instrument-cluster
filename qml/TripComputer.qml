import QtQuick
import QtQuick.Layouts

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
            Layout.bottomMargin: 10
        }

        RowLayout {
            Layout.fillWidth: true
            
            ColumnLayout {
                Text { text: "TRIP A"; color: "#888888"; font.pixelSize: 10 }
                Text { text: tripA.toFixed(1) + " km"; color: "white"; font.pixelSize: 14 }
            }
            
            Item { Layout.fillWidth: true } // Spacer
            
            ColumnLayout {
                Text { text: "AVG"; color: "#888888"; font.pixelSize: 10 }
                Text { text: efficiency.toFixed(1) + " Wh/km"; color: "white"; font.pixelSize: 14 }
            }
        }
    }
}
