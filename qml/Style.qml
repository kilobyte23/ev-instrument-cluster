pragma Singleton
import QtQuick

QtObject {
    // Color Palette (Ather/Ola inspired: High Contrast, Neon)
    property color background: "#121212" // Deep dark grey, not pure black
    property color backgroundSecondary: "#1E1E1E"
    
    // Accents
    property color primary: "#00E676" // Ather Greenish / Eco
    property color secondary: "#2979FF" // Tech Blue
    property color danger: "#FF3D00" // Alert Orange
    property color critical: "#FF1744" // Error Red
    property color warning: "#FFC107" // Warning Yellow
    
    // Text
    property color textPrimary: "#FFFFFF"
    property color textSecondary: "#B0B0B0"
    property color textMuted: "#666666"
    
    // Gradients / Special
    property color regenColor: "#00E676"
    property color powerColor: "#FF9100"
    
    // Fonts
    property string fontFamily: "Inter"
    property int fontSizeSmall: 14
    property int fontSizeMedium: 24
    property int fontSizeLarge: 48
    property int fontSizeHuge: 96
    
    // Layout
    property int cornerRadius: 12
    property int spacing: 20
}
