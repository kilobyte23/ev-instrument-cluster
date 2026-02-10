pragma Singleton
import QtQuick

QtObject {
    // Color Palette (Cyberpunk / Premium EV)
    // Deepest Black for OLED screens
    property color background: "#050505" 
    property color backgroundSecondary: "#1A1A1A"
    
    // Main Accents - Electric & Neon
    property color primary: "#00F3FF" // Electric Cyan (Speed, Normal Mode)
    property color secondary: "#BD00FF" // Neon Purple (Nav, Media)
    property color accent: "#00FF9D" // Toxic Green (Eco, Regen)
    
    // Status Colors
    property color safe: "#00FF9D" // Green
    property color warning: "#FFD600" // Bumblebee Yellow
    property color danger: "#FF003C" // Cyber Red
    property color critical: "#FF003C"
    
    // Text
    property color textPrimary: "#FFFFFF"
    property color textSecondary: "#808080"
    property color textMuted: "#404040"
    
    // Gradients / Special
    property color gradientStart: "#2C3E50"
    property color gradientEnd: "#000000"
    
    // Fonts
    property string fontFamily: "Inter"
    property string monoFont: "monospace"  // For numbers to prevent jitter
    
    // Font Sizes (Matching UI Spec)
    property int fontSizeHero: 120        // Hero numbers (Speed, Battery % in 4W)
    property int fontSizeHero2W: 200      // Hero for 2-Wheeler (Speed)
    property int fontSizePrimary: 72      // Primary data (Power, Range)
    property int fontSizeSecondary: 36    // Secondary data (Trip, Temp)
    property int fontSizeLabel: 18        // Labels
    property int fontSizeStatus: 16       // Status text
    
    // Legacy font sizes (for backward compatibility during transition)
    property int fontSizeSmall: 14
    property int fontSizeMedium: 24
    property int fontSizeLarge: 48
    property int fontSizeExtraLarge: 72
    property int fontSizeHuge: 120
    
    // Spacing (8px Grid System)
    property int spacing8: 8
    property int spacing16: 16
    property int spacing24: 24
    property int spacing32: 32
    property int spacing48: 48
    
    // Component Sizes (4-Wheeler Layout)
    property int topBarHeight: 72
    property int bottomBarHeight: 144
    property int gaugeWidth: 360
    property int gaugeHeight: 504
    property int centerWidth: 1200
    
    // Component Sizes (2-Wheeler Layout)
    property int topBarHeight2W: 60
    property int bottomBarHeight2W: 60
    property int speedSectionHeight2W: 300
    property int batterySectionHeight2W: 60
    
    // Icon Sizes
    property int iconSmall: 24
    property int iconMedium: 48
    property int iconLarge: 64
    property int iconHero: 96
    
    // Legacy layout (for backward compatibility)
    property int cornerRadius: 16
    property int spacing: 24
    
    // Glow/Shadow
    property color glowColor: "#4000F3FF"
}
