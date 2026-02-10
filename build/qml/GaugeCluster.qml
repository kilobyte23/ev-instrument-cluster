import QtQuick
import QtQuick.Layouts

Item {
    id: root
    
    // Bindings to VehicleData
    property real speed: VehicleData.speed
    property real power: VehicleData.powerOutput
    
    RowLayout {
        anchors.fill: parent
        spacing: 40
        
        // Power Meter
        PowerMeter {
            Layout.alignment: Qt.AlignVCenter
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.25
        }
        
        // Speedometer
        Speedometer {
            Layout.alignment: Qt.AlignVCenter
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.4
            speed: root.speed
        }
    }
}
