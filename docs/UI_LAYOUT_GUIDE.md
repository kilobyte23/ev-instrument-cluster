# EV INSTRUMENT CLUSTER - UI LAYOUT SPECIFICATION

**Purpose:** Provide clear, structured guidance for UI organization to ensure consistency, readability, and professional appearance.

---

## CORE DESIGN PRINCIPLES

### 1. Information Hierarchy
- Most critical info = largest, center position
- Secondary info = medium size, flanking positions
- Tertiary info = small, bottom/corners
- Warnings = overlay, attention-grabbing

### 2. Visual Balance
- Symmetrical layout for stability
- Consistent spacing and alignment
- Grouped related information
- Clear visual separation between zones

### 3. Glanceability
- Driver should understand status in < 2 seconds
- High contrast for readability
- Minimal text, maximum iconography
- Progressive disclosure (details on demand)

### 4. Screen Real Estate Zones
```
┌─────────────────────────────────────────┐
│  TOP BAR (Status & Indicators)          │ 10% height
├─────────────────────────────────────────┤
│          │                   │          │
│   LEFT   │   CENTER (HERO)   │  RIGHT   │ 70% height
│  GAUGE   │                   │  GAUGE   │
│          │                   │          │
├─────────────────────────────────────────┤
│  BOTTOM BAR (Secondary Info)            │ 20% height
└─────────────────────────────────────────┘
```

---

## LAYOUT TEMPLATES

### Template 1: DUAL GAUGE LAYOUT (Default for E-4Wheeler)

**Dimensions:** 1920x720px (16:3 aspect ratio)

```
┌─────────────────────────────────────────────────────────────────┐
│  [READY] ECO    12:34 PM    SUN FEB 9    28°C    [WiFi][BT]    │ 72px
├─────────────────────────────────────────────────────────────────┤
│         │                                         │             │
│  SPEED  │          BATTERY STATUS                 │   POWER     │
│         │                                         │             │
│   85    │          ████████████░░░░               │   -15.2     │ 504px
│         │                                         │             │
│  km/h   │      82%              Range: 328 km     │    kW       │
│         │                                         │             │
│  [○]    │   [Battery Icon with Charge Level]     │   [⚡]       │
│         │                                         │             │
├─────────────────────────────────────────────────────────────────┤
│  Trip: 45.2km  │  Avg: 142Wh/km  │  Temp: 28°C  │  ⚠️🔋⚡      │ 144px
└─────────────────────────────────────────────────────────────────┘
```

**Zone Breakdown:**

**TOP BAR (72px height):**
- Left: Drive status & mode
- Center: Time, date, ambient temp
- Right: Connectivity icons
- Background: Semi-transparent dark (#000000 @ 80%)
- Text: White, 18-24px font

**LEFT GAUGE (360x504px):**
- Primary: Speed (digital)
- Font: Bold, 120px
- Unit: 32px below number
- Style: Circular arc gauge (optional analog)
- Color: White text, blue accent

**CENTER SECTION (1200x504px):**
- Battery percentage: 96px bold font
- Progress bar: 60px height, rounded corners
- Range display: 48px font
- Battery icon: 200x200px, dynamic fill
- Background gradient based on SoC:
  - >50%: Green tint
  - 20-50%: Yellow tint
  - <20%: Red tint

**RIGHT GAUGE (360x504px):**
- Primary: Power output
- Font: Bold, 96px
- Bi-directional indicator
- Color coding:
  - Negative (regen): Green
  - 0-20kW: Blue
  - 20-50kW: Yellow
  - >50kW: Red

**BOTTOM BAR (144px height):**
- 4 equal sections
- Each section: Icon + Value + Label
- Font: 24px value, 16px label
- Right-most: Warning icons (48x48px each)

---

### Template 2: E-2WHEELER LAYOUT (Compact)

**Dimensions:** 1024x600px (common for scooter displays)

```
┌───────────────────────────────────────────────────┐
│  [READY]  ECO MODE        12:34      ⚡🔋        │ 60px
├───────────────────────────────────────────────────┤
│                                                   │
│                   SPEED                           │
│                     45                            │ 300px
│                   km/h                            │
│                                                   │
│     Battery: 67%  ████████░░░  Range: 28km       │
│                                                   │
├───────────────────────────────────────────────────┤
│              [MINI MAP - 30% height]              │ 180px
│           Nearest charger: 2.3 km                 │
├───────────────────────────────────────────────────┤
│  -2.5kW  │  32°C  │  Trip: 5km  │  45Wh/km       │ 60px
└───────────────────────────────────────────────────┘
```

**Design Notes:**
- Simplified, larger fonts for rider glance
- Speed dominates center (200px font)
- Battery status always visible
- Mini-map for basic navigation
- Minimal bottom info (4 items max)

---

## COLOR PALETTE

### Primary Colors:
```
Background:     #000000 (Pure Black for OLED)
Primary Text:   #FFFFFF (White)
Secondary Text: #AAAAAA (Light Gray)
Disabled:       #666666 (Dark Gray)
```

### Accent Colors by Theme:

**ECO Theme:**
```
Primary:   #00FF88 (Bright Green)
Secondary: #00CC66 (Dark Green)
Warning:   #FFD700 (Gold)
Danger:    #FF4444 (Red)
```

**SPORT Theme:**
```
Primary:   #FF3366 (Hot Pink/Red)
Secondary: #FF6600 (Orange)
Warning:   #FFCC00 (Amber)
Danger:    #FF0000 (Pure Red)
```

---

## SPACING & GRID

### 8px Grid System:
```
All elements align to 8px grid
Padding: 16px, 24px, 32px
Margins: 16px, 32px, 48px
Icon sizes: 24px, 48px, 64px, 96px
```

### Component Spacing:
```
Between sections:    32-48px
Between elements:    16-24px
Within component:    8-16px
Edge padding:        24-32px
```

---

## IMPLEMENTATION RULES

### DO:
✅ Keep speed and battery always visible
✅ Use consistent positioning across screens
✅ Group related information together
✅ Maintain visual hierarchy (size = importance)
✅ Use whitespace generously
✅ Align elements to grid
✅ Keep critical warnings centered and large
✅ Use icons with text labels

### DON'T:
❌ Scatter information randomly
❌ Use more than 3 font sizes per screen
❌ Mix different alignment styles
❌ Crowd the interface
❌ Use tiny fonts (<16px for secondary info)
❌ Hide critical information in submenus
❌ Use low-contrast color combinations
