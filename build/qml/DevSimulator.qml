import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "."

Window {
    id: root
    width: 350
    height: 600
    title: "Dev Simulator"
    color: "#222" // Solid dark background for separate window
    signal bikeModeToggled(bool active)

    visible: true 
    flags: Qt.Window | Qt.WindowStaysOnTopHint

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
                // Vehicle Type Toggle
                RowLayout {
                    Label { text: "Type:"; color: "white" }
                    RadioButton { 
                        text: "Car (4W)"
                        checked: true
                        onCheckedChanged: if(checked) bikeModeToggled(false)
                        palette.windowText: "white"
                    }
                    RadioButton { 
                        text: "Bike (2W)"
                        onCheckedChanged: if(checked) bikeModeToggled(true)
                        palette.windowText: "white"
                    }
                }
                
                // Odometer
                Label { text: "Odometer: " + odoSlider.value.toFixed(0) + " km"; color: "white" }
                Slider {
                    id: odoSlider
                    from: 0; to: 100000
                    value: VehicleData.odometer
                    onMoved: VehicleData.odometer = value
                    Layout.fillWidth: true
                }
                
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
                    value: VehicleData.batteryTempAvg
                    onMoved: VehicleData.batteryTempAvg = value
                    Layout.fillWidth: true
                }
                
                // Motor Temp Control
                Label { text: "Motor Temp: " + motorTempSlider.value.toFixed(0) + "°C"; color: "white" }
                Slider {
                    id: motorTempSlider
                    from: 0; to: 120
                    value: VehicleData.motorTemp
                    onMoved: VehicleData.motorTemp = value
                    Layout.fillWidth: true
                }
                
                // Battery Health (SOH)
                Label { text: "Battery Health (SOH): " + sohSlider.value.toFixed(0) + "%"; color: "white" }
                Slider {
                    id: sohSlider
                    from: 50; to: 100
                    value: VehicleData.batterySoh
                    onMoved: VehicleData.batterySoh = value
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
                    CheckBox { text: "Door Ajar / Side Stand"; checked: VehicleData.doorAjar; onToggled: VehicleData.doorAjar = checked }
                    CheckBox { text: "Seatbelt"; checked: VehicleData.seatbeltWarning; onToggled: VehicleData.seatbeltWarning = checked }
                }
                
                RowLayout {
                    CheckBox { text: "High Beam"; checked: VehicleData.highBeam; onToggled: VehicleData.highBeam = checked }
                    CheckBox { text: "Parking Brake"; checked: VehicleData.parkingBrake; onToggled: VehicleData.parkingBrake = checked }
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
