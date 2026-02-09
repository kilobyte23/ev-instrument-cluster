import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

Item {
    id: root
    width: 600
    height: 480

    property real userLat: 28.6139
    property real userLon: 77.2090
    property real vehicleHeading: 0

    // Filters
    property bool showCCS: true
    property bool showType2: true

    Plugin {
        id: mapPlugin
        name: "osm" // OpenStreetMap
        
        // Use offline tiles if available, or caching
        PluginParameter { name: "osm.mapping.offline.directory"; value: "assets/maps/tiles" }
        PluginParameter { name: "osm.mapping.highdpi_tiles"; value: true }
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(userLat, userLon)
        zoomLevel: 15
        tilt: 45 // 3D perspective
        bearing: vehicleHeading
        
        color: "#1a1a1a" // Dark background for gaps
        
        // Copyright notice required by OSM
        Text {
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            text: "© OpenStreetMap contributors"
            font.pixelSize: 10
            color: "#888"
            z: 100
        }

        // Vehicle Marker (Center)
        MapQuickItem {
            id: vehicleMarker
            coordinate: QtPositioning.coordinate(userLat, userLon)
            anchorPoint.x: markerImage.width / 2
            anchorPoint.y: markerImage.height / 2
            
            sourceItem: Image {
                id: markerImage
                width: 32
                height: 32
                source: "qrc:/assets/icons/navigation_arrow.svg" // We need to create this later or use a shape
                
                // Fallback shape if icon missing
                Rectangle {
                    visible: markerImage.status !== Image.Ready
                    width: 20
                    height: 30
                    color: "#2979FF"
                    radius: 5
                    
                    // Direction arrow
                    Rectangle {
                        width: 10; height: 10
                        color: "white"
                        rotation: 45
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                        anchors.topMargin: 5
                    }
                }
            }
        }
        
        // Range Circle
        MapCircle {
            center: QtPositioning.coordinate(userLat, userLon)
            radius: VehicleData.estimatedRange * 1000 // Convert km to meters
            color: "#1000E676" // Transparent green
            border.color: "#00E676"
            border.width: 1
            opacity: 0.5
        }
        
        // Mock Route (Energy Optimized)
        MapPolyline {
            line.width: 5
            line.color: "#2979FF"
            path: [
                { latitude: 28.6139, longitude: 77.2090 },
                { latitude: 28.6150, longitude: 77.2095 },
                { latitude: 28.6200, longitude: 77.2100 },
                { latitude: 28.6250, longitude: 77.2150 }
            ]
        }
        
        // Dynamic Charging Stations from Model
        MapItemView {
            model: ListModel {
                id: stationModel
                ListElement { lat: 28.6150; lon: 77.2100; type: "CCS"; pwr: 50; ver: true }
                ListElement { lat: 28.6120; lon: 77.2050; type: "Type2"; pwr: 11; ver: false }
                ListElement { lat: 28.6200; lon: 77.2150; type: "CCS"; pwr: 150; ver: true }
            }
            
            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(lat, lon)
                anchorPoint.x: 10
                anchorPoint.y: 20
                visible: (type === "CCS" && showCCS) || (type === "Type2" && showType2)
                
                sourceItem: ChargingStationMarker {
                    verified: ver
                    power: pwr
                }
            }
        }
    }
    
    // Filter Controls Overlay
    Row {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
        spacing: 10
        
        Button {
            text: "CCS"
            checkable: true
            checked: showCCS
            onClicked: showCCS = checked
            height: 30
            background: Rectangle { 
                color: parent.checked ? "#2979FF" : "#333"
                radius: 4
            }
            contentItem: Text { text: parent.text; color: "white"; anchors.centerIn: parent }
        }
        
        Button {
            text: "Type 2"
            checkable: true
            checked: showType2
            onClicked: showType2 = checked
            height: 30
            background: Rectangle { 
                color: parent.checked ? "#2979FF" : "#333"
                radius: 4
            }
            contentItem: Text { text: parent.text; color: "white"; anchors.centerIn: parent }
        }
    }
    
    // Efficiency Overlay used to be here, but now it's part of the route logic implicitly visually
    
    // Zoom Controls
    Column {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20
        anchors.bottomMargin: 40
        spacing: 10
        
        Button {
            text: "+"
            width: 40
            height: 40
            onClicked: map.zoomLevel += 1
            background: Rectangle { color: "#333"; radius: 4 }
            contentItem: Text { text: "+"; color: "white"; anchors.centerIn: parent }
        }
        
        Button {
            text: "-"
            width: 40
            height: 40
            onClicked: map.zoomLevel -= 1
            background: Rectangle { color: "#333"; radius: 4 }
            contentItem: Text { text: "-"; color: "white"; anchors.centerIn: parent }
        }
    }
}
