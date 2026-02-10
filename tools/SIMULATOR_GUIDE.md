# EV Drive Simulator - Quick Start Guide

## Running the Simulator

### Prerequisites
- Python 3 with tkinter (included with most Python installations)
- EV instrument cluster application running

### Launch Steps

1. **Start the EV Cluster:**
   ```bash
   cd /Users/mohithavala/.gemini/antigravity/scratch/ev-instrument-cluster/build
   ./ev-cluster
   ```

2. **Start the Simulator:**
   ```bash
   cd /Users/mohithavala/.gemini/antigravity/scratch/ev-instrument-cluster/tools
   python3 ev_simulator.py
   ```

3. **A GUI window will appear** with scenario controls

## Using the GUI

### Scenario Selection
Choose from 6 realistic driving scenarios:

- **City Commute** - Stop-and-go traffic (20-60 km/h)
- **Highway Cruise** - Steady high-speed (100-120 km/h)
- **Aggressive Driving** - Rapid acceleration (0-140 km/h)
- **Eco Mode** - Efficient gentle driving (55-70 km/h)
- **Mountain Drive** - Hills with regenerative braking
- **Track Day** - Maximum performance (60-160 km/h)

### Controls

1. **Select Scenario** from dropdown
2. **Click "▶ Simulate Drive"** to start
3. **Watch the cluster UI** for realistic animations
4. **Use Controls:**
   - ⏸ **Pause** - Freeze simulation
   - ▶ **Resume** - Continue from pause
   - ⏹ **Stop** - Return to idle

### Real-Time Display

The GUI shows live parameters:
- Speed (km/h)
- Power (kW) - negative values = regeneration/charging
- State of Charge (%)
- Motor Temperature (°C)
- Motor RPM
- Estimated Range (km)

## What to Observe in the Cluster

✅ **Speed gauge** animates smoothly
✅ **Power meter** shows consumption (positive) and regeneration (negative)
✅ **RPM gauge** scales with speed automatically
✅ **Battery SoC** decreases during driving, increases during braking
✅ **Temperatures** rise with load, cool during idle
✅ **Range** updates based on current efficiency
✅ **Drive mode** changes per scenario (Eco/Normal/Sport/Sport+)

## Physics Features

### Regenerative Braking
- Appears as **negative power** values
- **Battery SoC increases** during deceleration
- Most visible in **City Commute** and **Mountain Drive** scenarios

### Temperature Dynamics
- Motor temp rises with power consumption
- Gradual cooling during low power/idle
- **Track Day** may trigger thermal warnings (>100°C)

### Power Consumption
- Increases exponentially with speed (aerodynamic drag)
- **Eco Mode** uses least power
- **Track Day** uses most power

## Troubleshooting

**GUI doesn't appear:**
```bash
# Check if tkinter is installed
python3 -m tkinter
# Should open a test window
```

**No data in cluster:**
- Ensure cluster is running first
- Check simulator shows "Sending data to localhost:5555"
- Both applications must be running simultaneously

**Simulator crashes:**
- Check Python version: `python3 --version` (needs 3.6+)
- Ensure vehicle.json exists in ../config/

## Advanced Usage

### Switching Scenarios Mid-Drive
1. Click **Stop**
2. Select new scenario
3. Click **Simulate Drive**

### Observing Specific Physics
- **Regen braking**: Select City Commute, watch power go negative during stops
- **Temperature effects**: Select Track Day, monitor motor temp rise
- **Efficiency comparison**: Run Eco vs Aggressive, compare battery drain

## Vehicle Configuration

The simulator reads from `config/vehicle.json`:
```json
{
    "battery_capacity_kwh": 77.4,
    "max_charge_power_kw": 250,
    "max_regen_power_kw": 150
}
```

- Battery > 10 kWh = 4-wheeler mode
- Battery ≤ 10 kWh = 2-wheeler mode

## Stopping the Simulator

- Close the GUI window, or
- Press `Ctrl+C` in the terminal
