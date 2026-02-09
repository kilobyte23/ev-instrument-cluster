import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "."

Rectangle {
    id: root
    width: 350
    height: 480
    color: "#EE000000" // Semi-transparent black
    border.color: Style.secondary
    border.width: 1
    radius: 10
    visible: false // Hidden by default

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 10
        
        Text {
            text: "DEV SIMULATOR"
            color: Style.primary
            font.bold: true
            font.pixelSize: 18
            Layout.alignment: Qt.AlignHCenter
        }

        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            
            ColumnLayout {
                width: parent.width
                spacing: 15
                
                // Speed Control
                Label { text: "Speed: " + speedSlider.value.toFixed(0) + " km/h"; color: "white" }
                Slider {
                    id: speedSlider
                    from: 0; to: 200
                    value: VehicleData.speed
                    onMoved: VehicleData.speed = value
                    Layout.fillWidth: true
                }
                
                // RPM Control
                Label { text: "Motor RPM: " + rpmSlider.value.toFixed(0); color: "white" }
                Slider {
                    id: rpmSlider
                    from: 0; to: 12000
                    value: VehicleData.motorRpm
                    onMoved: VehicleData.motorRpm = value
                    Layout.fillWidth: true
                }

                // Power/Regen
                Label { text: "Power: " + powerSlider.value.toFixed(0) + " kW"; color: "white" }
                Slider {
                    id: powerSlider
                    from: -50; to: 150
                    value: VehicleData.powerOutput
                    onMoved: VehicleData.powerOutput = value
                    Layout.fillWidth: true
                }

                // SoC Control
                Label { text: "Battery SoC: " + socSlider.value.toFixed(0) + "%"; color: "white" }
                Slider {
                    id: socSlider
                    from: 0; to: 100
                    value: VehicleData.batterySoc
                    onMoved: VehicleData.batterySoc = value
                    Layout.fillWidth: true
                }
                
                // Temp Control
                Label { text: "Battery Temp: " + tempSlider.value.toFixed(0) + "°C"; color: "white" }
                Slider {
                    id: tempSlider
                    from: -20; to: 80
                    value: VehicleData.batteryTemp
                    onMoved: VehicleData.batteryTemp = value
                    Layout.fillWidth: true
                }

                // Boolean Toggles
                RowLayout {
                    CheckBox { text: "Charging"; checked: VehicleData.chargingActive; onToggled: VehicleData.chargingActive = checked }
                    CheckBox { text: "Ready"; checked: VehicleData.readyToDrive; onToggled: VehicleData.readyToDrive = checked }
                }
                
                RowLayout {
                    CheckBox { text: "Left Turn"; checked: VehicleData.leftTurnSignal; onToggled: VehicleData.leftTurnSignal = checked }
                    CheckBox { text: "Right Turn"; checked: VehicleData.rightTurnSignal; onToggled: VehicleData.rightTurnSignal = checked }
                }
                
                RowLayout {
                    CheckBox { text: "Door Ajar"; checked: VehicleData.doorAjar; onToggled: VehicleData.doorAjar = checked }
                    CheckBox { text: "Seatbelt"; checked: VehicleData.seatbeltWarning; onToggled: VehicleData.seatbeltWarning = checked }
                }
                
                Button {
                    text: "Toggle Night Mode"
                    onClicked: VehicleData.nightMode = !VehicleData.nightMode
                    Layout.fillWidth: true
                }
                
                Button {
                    text: "Close Simulator"
                    onClicked: root.visible = false
                    Layout.fillWidth: true
                }
            }
        }
    }
}
