import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "."

Item {
    id: root
    width: 600
    height: 480
    
    Rectangle {
        anchors.fill: parent
        color: Style.background
    }
    
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 40
        spacing: 20
        
        Text {
            text: "SETTINGS"
            font.family: Style.fontFamily
            font.pixelSize: 32
            color: Style.textPrimary
            font.bold: true
        }
        
        TabBar {
            id: bar
            width: parent.width
            TabButton { text: "Display" }
            TabButton { text: "Vehicle" }
            TabButton { text: "Navigation" }
            TabButton { text: "System" }
        }
        
        StackLayout {
            currentIndex: bar.currentIndex
            Layout.fillWidth: true
            Layout.fillHeight: true
            
            // Display Settings
            ColumnLayout {
                spacing: 20
                RowLayout {
                    Text { text: "Theme Mode"; color: "white"; font.pixelSize: 18 }
                    ComboBox { model: ["Auto", "Day", "Night"] }
                }
                RowLayout {
                    Text { text: "Brightness"; color: "white"; font.pixelSize: 18 }
                    Slider { value: 0.8 }
                }
            }
            
            // Vehicle Settings
            ColumnLayout {
                spacing: 20
                CheckBox { text: "Regenerative Braking (One-Pedal)"; checked: true }
                CheckBox { text: "Speed Limit Warning"; checked: false }
            }
            
            // Navigation
            Item { Text { text: "Map Options"; color: "white" } }
            
            // System
            Item { Text { text: "Version 1.0.0 (Phase 1)"; color: "gray" } }
        }
        
        Button {
            text: "Close"
            onClicked: root.visible = false
        }
    }
}
