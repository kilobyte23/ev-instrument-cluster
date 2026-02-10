import socket
import json
import time
import math
import random
from abc import ABC, abstractmethod
from enum import Enum
import threading
try:
    import tkinter as tk
    from tkinter import ttk
    HAS_GUI = True
except ImportError:
    HAS_GUI = False
    print("Warning: tkinter not available. Running without GUI.")


class VehicleType(Enum):
    TWO_WHEELER = "2W"
    FOUR_WHEELER = "4W"


class DrivingScenario(ABC):
    """Base class for all driving scenarios"""
    
    def __init__(self, name, description, duration=300):
        self.name = name
        self.description = description
        self.duration = duration  # seconds
        self.elapsed_time = 0.0
        
    @abstractmethod
    def get_target_speed(self, t):
        """Get target speed at time t (seconds)"""
        pass
    
    @abstractmethod
    def get_power_range(self):
        """Get typical power range for this scenario (min, max) in kW"""
        pass
    
    @abstractmethod
    def get_acceleration_rate(self):
        """Get max acceleration rate in km/h per second"""
        pass
    
    def get_drive_mode(self):
        """Get drive mode name"""
        return "Normal"
    
    def update(self, dt):
        """Update scenario state"""
        self.elapsed_time += dt
        
    def is_complete(self):
        """Check if scenario is complete"""
        return self.elapsed_time >= self.duration
    
    def reset(self):
        """Reset scenario"""
        self.elapsed_time = 0.0


class CityCommuteScenario(DrivingScenario):
    """Urban driving with traffic lights - gentle and smooth"""
    
    def __init__(self):
        super().__init__("City Commute", "Urban driving with traffic lights", 300)
        self.cycle_time = 50.0  # Total cycle time
        self.stop_duration = 12.0  # Stop at lights
        self.cruise_duration = 25.0  # Cruising time
        
    def get_target_speed(self, t):
        t_in_cycle = t % self.cycle_time
        
        if t_in_cycle < self.stop_duration:
            # Stopped at traffic light
            return 0.0
        elif t_in_cycle < self.stop_duration + 8:
            # Gentle acceleration from stop
            accel_time = t_in_cycle - self.stop_duration
            return 45.0 * min(1.0, accel_time / 8.0)
        elif t_in_cycle < self.stop_duration + self.cruise_duration:
            # Steady cruising
            return 45.0
        else:
            # Gentle deceleration to stop
            decel_time = self.cycle_time - t_in_cycle
            return max(0, 45.0 * (decel_time / 10.0))
    
    def get_power_range(self):
        return (5, 25)
    
    def get_acceleration_rate(self):
        return 2.5  # km/h per second - gentle
    
    def get_drive_mode(self):
        return "Normal"


class HighwayCruiseScenario(DrivingScenario):
    """Steady motorway driving with minimal variations"""
    
    def __init__(self):
        super().__init__("Highway Cruise", "Steady motorway driving", 300)
        self.cruise_speed = 95.0
        self.variation_time = 0.0
        
    def get_target_speed(self, t):
        if t < 20:
            # Very gradual acceleration to highway speed
            return self.cruise_speed * min(1.0, t / 20.0)
        else:
            # Steady cruise with minimal natural variation
            variation = 0.8 * math.sin(t * 0.05)  # Very subtle
            return self.cruise_speed + variation
    
    def get_power_range(self):
        return (18, 28)
    
    def get_acceleration_rate(self):
        return 0.5  # Very gradual
    
    def get_drive_mode(self):
        return "Normal"


class EcoModeScenario(DrivingScenario):
    """Efficient, smooth driving for maximum range"""
    
    def __init__(self):
        super().__init__("Eco Mode", "Efficient smooth driving", 300)
        self.target = 60.0
        
    def get_target_speed(self, t):
        if t < 25:
            # Very gentle acceleration
            return self.target * min(1.0, t / 25.0)
        else:
            # Very steady cruising
            return self.target
    
    def get_power_range(self):
        return (3, 15)
    
    def get_acceleration_rate(self):
        return 1.5  # Very gentle
    
    def get_drive_mode(self):
        return "Eco"


class SpiritedDriveScenario(DrivingScenario):
    """Enthusiastic but controlled driving"""
    
    def __init__(self):
        super().__init__("Spirited Drive", "Enthusiastic but controlled", 300)
        self.phase_time = 35.0
        
    def get_target_speed(self, t):
        t_in_phase = t % self.phase_time
        
        if t_in_phase < 10:
            # Moderate acceleration
            return 110.0 * min(1.0, t_in_phase / 10.0)
        elif t_in_phase < 22:
            # Sustain high speed steadily
            return 110.0
        else:
            # Controlled deceleration
            decel_progress = (t_in_phase - 22) / 13.0
            return 110.0 * (1 - decel_progress * 0.7)
    
    def get_power_range(self):
        return (15, 55)
    
    def get_acceleration_rate(self):
        return 5.0  # Moderate
    
    def get_drive_mode(self):
        return "Sport"


class MixedUrbanHighwayScenario(DrivingScenario):
    """Realistic daily commute with urban and highway segments"""
    
    def __init__(self):
        super().__init__("Mixed Urban/Highway", "Realistic daily commute", 300)
        self.segment_duration = 50.0
        
    def get_target_speed(self, t):
        t_in_segment = t % self.segment_duration
        
        if t_in_segment < 25:
            # Urban segment - steady 40 km/h
            if t_in_segment < 3:
                return 40.0 * (t_in_segment / 3.0)
            else:
                return 40.0
        else:
            # Highway segment - transition and maintain 90
            highway_time = t_in_segment - 25
            if highway_time < 8:
                # Transition from urban to highway
                progress = highway_time / 8.0
                return 40.0 + (50.0 * progress)
            else:
                return 90.0
    
    def get_power_range(self):
        return (5, 30)
    
    def get_acceleration_rate(self):
        return 3.0
    
    def get_drive_mode(self):
        return "Normal"


class ChargingScenario(DrivingScenario):
    """Realistic charging scenario with different power levels"""
    
    def __init__(self, charge_power_kw=150.0):
        mode_name = "DC Fast Charge"
        if charge_power_kw < 2.0:
            mode_name = "AC Level 1 Charge"
        elif charge_power_kw < 20.0:
            mode_name = "AC Level 2 Charge"
            
        super().__init__(mode_name, f"Charging at {charge_power_kw} kW", 3600)
        self.charge_power = charge_power_kw
        
    def get_target_speed(self, t):
        return 0.0  # Vehicle must be stopped
    
    def get_power_range(self):
        return (-self.charge_power, -self.charge_power)
    
    def get_acceleration_rate(self):
        return 0.0
    
    def get_drive_mode(self):
        return "Park"

    def get_charge_power(self):
        return self.charge_power




class AggressiveDriverScenario(DrivingScenario):
    """Dangerous driving: rapid bursts to 160+ km/h, hard braking, erratic"""
    
    def __init__(self):
        super().__init__("Aggressive Driver", "Reckless high-speed driving with hard braking", 300)
    
    def get_target_speed(self, t):
        cycle = t % 40
        if cycle < 8:
            return 160 + 20 * math.sin(t * 0.5)  # Wild burst to 160-180
        elif cycle < 12:
            return 20  # Slam brakes
        elif cycle < 20:
            return 140 + 10 * math.sin(t * 0.8)
        elif cycle < 25:
            return 5  # Emergency stop
        elif cycle < 35:
            return 130 + 30 * math.sin(t * 0.3)
        else:
            return 60  # Brief calm
    
    def get_power_range(self):
        return (50, 200)
    
    def get_acceleration_rate(self):
        return 12.0  # Very aggressive accel
    
    def get_drive_mode(self):
        return "Sport"
    
    def update(self, dt):
        super().update(dt)
        # Trigger ABS and TC intermittently during hard braking
    
    def apply_initial_state(self, sim):
        sim.seatbelt_warning = True  # Driver didn't buckle up
        sim.soc = 80.0


class BatteryOverheatScenario(DrivingScenario):
    """Battery temperature rises dangerously during moderate driving"""
    
    def __init__(self):
        super().__init__("Battery Overheat", "Battery thermal runaway risk", 300)
        self._overheat_started = False
    
    def get_target_speed(self, t):
        # Moderate highway speed — the heat comes from the battery, not driving
        return 80 + 10 * math.sin(t * 0.15)
    
    def get_power_range(self):
        return (15, 40)
    
    def get_acceleration_rate(self):
        return 3.0
    
    def apply_initial_state(self, sim):
        sim.battery_temp = 38.0  # Start already warm
        sim.soc = 60.0

    def update(self, dt):
        super().update(dt)
        self._overheat_started = self.elapsed_time > 5

    def get_temp_boost(self):
        """Extra heat injected per update tick"""
        if not self._overheat_started:
            return 0.0
        # Ramp: 0.3°C/s initially, accelerating
        t = self.elapsed_time - 5
        return 0.3 + min(t * 0.005, 0.5)  # Caps at 0.8°C/s


class MotorOverheatScenario(DrivingScenario):
    """Sustained hill climb causing motor overheat"""
    
    def __init__(self):
        super().__init__("Motor Overheat", "Sustained hill climb overheating motor", 300)
    
    def get_target_speed(self, t):
        # Steady climb speed with occasional terrain changes
        return 60 + 5 * math.sin(t * 0.1)
    
    def get_power_range(self):
        return (40, 100)  # High sustained load
    
    def get_acceleration_rate(self):
        return 2.0
    
    def get_drive_mode(self):
        return "Sport"
    
    def apply_initial_state(self, sim):
        sim.motor_temp = 60.0  # Already warm from driving
        sim.soc = 70.0
    
    def get_temp_boost(self):
        """Extra motor heat per update tick"""
        if self.elapsed_time < 3:
            return 0.0
        t = self.elapsed_time - 3
        return 0.4 + min(t * 0.003, 0.3)  # Ramps to 0.7°C/s


class DegradedBatteryScenario(DrivingScenario):
    """Old battery with low SoH — reduced range, warning flags"""
    
    def __init__(self):
        super().__init__("Degraded Battery", "Aged battery with low health", 300)
    
    def get_target_speed(self, t):
        # Normal city driving
        cycle = t % 50
        if cycle < 15:
            return 50
        elif cycle < 20:
            return 0
        elif cycle < 35:
            return 60
        else:
            return 30
    
    def get_power_range(self):
        return (5, 25)
    
    def get_acceleration_rate(self):
        return 3.0

    def apply_initial_state(self, sim):
        sim.soh = 65.0  # Low health — triggers warning overlay
        sim.soc = 55.0
        sim.battery_temp = 28.0


class CriticalLowBatteryScenario(DrivingScenario):
    """Driving at high speed with critically low battery"""
    
    def __init__(self):
        super().__init__("Critical Low Battery", "Low battery at highway speed", 180)
    
    def get_target_speed(self, t):
        # Start fast, gradually forced to slow as battery dies
        if t < 60:
            return 100  # Still pushing hard
        elif t < 120:
            return 70  # Realizing the problem
        else:
            return 40  # Turtle mode
    
    def get_power_range(self):
        return (20, 60)
    
    def get_acceleration_rate(self):
        return 4.0

    def apply_initial_state(self, sim):
        sim.soc = 8.0  # Critically low!
        sim.soh = 92.0
        sim.battery_temp = 26.0


class HVSystemFaultScenario(DrivingScenario):
    """HV isolation fault during highway driving — limp mode"""
    
    def __init__(self):
        super().__init__("HV System Fault", "HV isolation failure mid-drive", 180)
        self._fault_triggered = False
    
    def get_target_speed(self, t):
        if t < 30:
            return 90  # Normal cruising
        elif t < 35:
            return 90  # Fault happens at t=30
        elif t < 60:
            return 30  # Limp mode — max 30 km/h
        else:
            return 0  # Pull over and stop
    
    def get_power_range(self):
        return (5, 30)
    
    def get_acceleration_rate(self):
        return 2.0
    
    def get_drive_mode(self):
        return "Normal"
    
    def update(self, dt):
        super().update(dt)
        if self.elapsed_time >= 30 and not self._fault_triggered:
            self._fault_triggered = True
    
    def is_fault_active(self):
        return self._fault_triggered

    def apply_initial_state(self, sim):
        sim.soc = 60.0
        sim.battery_temp = 25.0

    def reset(self):
        super().reset()
        self._fault_triggered = False


class PhysicsEngine:
    """Realistic EV physics calculations with smooth behavior"""
    
    def __init__(self, vehicle_type, battery_capacity_kwh):
        self.vehicle_type = vehicle_type
        self.battery_capacity = battery_capacity_kwh
        
        # Vehicle-specific parameters
        if vehicle_type == VehicleType.FOUR_WHEELER:
            self.mass = 1800  # kg
            self.max_power = 150  # kW (typical EV)
            self.drag_coefficient = 0.28
            self.frontal_area = 2.3  # m²
            self.rpm_factor = 45  # Simplified: RPM = speed * factor
            self.max_rpm = 6000
        else:  # TWO_WHEELER
            self.mass = 150
            self.max_power = 15
            self.drag_coefficient = 0.6
            self.frontal_area = 0.5
            self.rpm_factor = 60
            self.max_rpm = 9000
            
        self.air_density = 1.225  # kg/m³
        self.rolling_resistance = 0.01
        
    def calculate_power_consumption(self, speed_kmh, is_accelerating=False, accel_amount=0):
        """Calculate realistic power consumption based on speed"""
        if speed_kmh < 0.5:
            return 1.0  # Stable idle power
            
        speed_ms = speed_kmh / 3.6
        
        # Aerodynamic drag power: P = 0.5 * ρ * Cd * A * v³
        drag_power = 0.5 * self.air_density * self.drag_coefficient * \
                     self.frontal_area * (speed_ms ** 3) / 1000
        
        # Rolling resistance power
        rolling_power = self.rolling_resistance * self.mass * 9.81 * speed_ms / 1000
        
        # Base power consumption
        base_power = drag_power + rolling_power
        
        # Add power for acceleration
        if is_accelerating and accel_amount > 0:
            accel_power = min(accel_amount * 5, 30)  # Cap acceleration power
            return min(base_power + accel_power, self.max_power)
        
        # Power ranges by speed (realistic EV consumption)
        if speed_kmh < 40:
            power = base_power * 1.8 + 8.5  # Stable low speed power
        elif speed_kmh < 80:
            power = base_power * 1.6 + 18.5  # Stable medium speed
        else:
            power = base_power * 1.5 + 35.0  # Stable high speed
            
        return min(power, self.max_power)
    
    def calculate_regen_power(self, speed_kmh, decel_rate):
        """Calculate regenerative braking power - stronger at higher speeds"""
        if decel_rate <= 0 or speed_kmh < 3:
            return 0.0
            
        # Regen is proportional to speed and decel rate
        # Stronger at higher speeds, weaker near stop
        speed_factor = min(speed_kmh / 100.0, 1.0)
        base_regen = decel_rate * 2.5 * speed_factor
        
        # Typical regen range: 5-15 kW
        regen_power = min(base_regen, 15.0)
        return max(regen_power, 2.0) if regen_power > 1 else 0
    
    def calculate_motor_rpm(self, speed_kmh):
        """Simplified realistic RPM calculation"""
        if speed_kmh < 0.1:
            return 0
        return min(speed_kmh * self.rpm_factor, self.max_rpm)


class EVSimulator:
    """Enhanced EV Simulator with ultra-smooth realistic behavior"""
    
    def __init__(self, config_path='../config/vehicle.json'):
        # Load vehicle configuration
        try:
            with open(config_path, 'r') as f:
                config = json.load(f)
                self.battery_capacity = config['battery_capacity_kwh']
                self.max_charge_power = config.get('max_charge_power_kw', 150)
                self.max_regen_power = config.get('max_regen_power_kw', 100)
        except:
            print("Warning: Could not load vehicle.json, using defaults")
            self.battery_capacity = 65.0
            self.max_charge_power = 150
            self.max_regen_power = 100
        
        # Determine vehicle type
        self.vehicle_type = VehicleType.FOUR_WHEELER if self.battery_capacity > 10 else VehicleType.TWO_WHEELER
        
        # Initialize physics engine
        self.physics = PhysicsEngine(self.vehicle_type, self.battery_capacity)
        
        # State variables - smooth EV behavior
        self.soc = 85.0  # %
        self.soh = 100.0  # %
        self.speed = 0.0  # km/h
        self.target_speed = 0.0
        self.power = 0.0  # kW
        self.motor_rpm = 0.0
        self.battery_temp = 22.0  # °C (cool start)
        self.motor_temp = 30.0  # °C
        self.battery_voltage = 350.0  # V
        self.battery_current = 0.0  # A
        self.range = 400.0  # km
        self.odometer = 0.0  # km
        self.trip_distance = 0.0  # km (resettable trip)
        self.efficiency = 0.0  # Wh/km
        self.charging = False
        self.drive_mode = "Normal"
        self.ready = True
        
        # Warning / fault state variables
        self.hv_fault = False
        self.motor_fault = False
        self.abs_active = False
        self.tc_active = False
        self.seatbelt_warning = False
        
        # Smoothing variables
        self.prev_speed = 0.0
        self.prev_power = 0.0
        self.prev_motor_temp = 30.0
        self.prev_battery_temp = 22.0
        
        # GPS
        self.lat = 28.6139
        self.lon = 77.2090
        self.heading = 0.0
        self.path_angle = 0.0
        
        # Scenario
        self.current_scenario = None
        self.max_accel_rate = 3.0
        
    def set_scenario(self, scenario):
        """Set and start a driving scenario"""
        self.current_scenario = scenario
        self.current_scenario.reset()
        self.drive_mode = scenario.get_drive_mode()
        self.max_accel_rate = scenario.get_acceleration_rate()
        # Reset charging flag when switching to driving scenario
        if not isinstance(scenario, ChargingScenario):
            self.charging = False
        # Reset fault flags
        self.hv_fault = False
        self.motor_fault = False
        self.abs_active = False
        self.tc_active = False
        self.seatbelt_warning = False
        # Apply scenario-specific initial state
        if hasattr(scenario, 'apply_initial_state'):
            scenario.apply_initial_state(self)
        
    def smooth_transition(self, current, target, rate, dt):
        """Smooth transition between values"""
        diff = target - current
        max_change = rate * dt
        
        if abs(diff) <= max_change:
            return target
        else:
            return current + (max_change if diff > 0 else -max_change)
    
    def update(self, dt):
        """Update simulation with ultra-smooth transitions"""
        # Update scenario if active
        if self.current_scenario:
            self.current_scenario.update(dt)
            self.target_speed = self.current_scenario.get_target_speed(
                self.current_scenario.elapsed_time
            )
            
        # Limp mode capping for HV System Fault
        if isinstance(self.current_scenario, HVSystemFaultScenario):
            self.hv_fault = self.current_scenario.is_fault_active()
            if self.hv_fault:
                self.target_speed = min(self.target_speed, 30.0)
                self.motor_fault = True  # Show motor fault too during HV fault
        
        # ABS/TC flags for Aggressive Driver
        if isinstance(self.current_scenario, AggressiveDriverScenario):
            # Trigger ABS during hard deceleration
            if is_decelerating and decel_rate > 8.0:
                self.abs_active = True
            else:
                self.abs_active = False
            
            # Trigger TC during hard acceleration
            speed_accel = (self.speed - self.prev_speed) / dt if dt > 0 else 0
            if is_accelerating and speed_accel > 10.0:
                self.tc_active = True
            else:
                self.tc_active = False
        else:
            self.abs_active = False
            self.tc_active = False
        
        # CRITICAL: Smooth speed transition (no sudden jumps)
        speed_diff = self.target_speed - self.speed
        
        # Determine if accelerating or decelerating
        is_accelerating = speed_diff > 0.5
        is_decelerating = speed_diff < -0.5
        
        # Apply smooth acceleration/deceleration
        if is_accelerating:
            accel_rate = min(self.max_accel_rate, 5.0)
            self.speed = self.smooth_transition(self.speed, self.target_speed, accel_rate, dt)
        elif is_decelerating:
            decel_rate = min(self.max_accel_rate * 1.5, 6.0)  # Slightly faster decel
            self.speed = self.smooth_transition(self.speed, self.target_speed, decel_rate, dt)
        else:
            # Micro-adjustments
            self.speed = self.smooth_transition(self.speed, self.target_speed, 1.0, dt)
        
        self.speed = max(0, self.speed)
        
        # Calculate deceleration rate for regen
        decel_rate = max(0, (self.prev_speed - self.speed) / (dt if dt > 0 else 0.1))
        
        # Calculate motor RPM smoothly
        target_rpm = self.physics.calculate_motor_rpm(self.speed)
        self.motor_rpm = self.smooth_transition(self.motor_rpm, target_rpm, 500, dt)
        
        # Power consumption calculation
        if isinstance(self.current_scenario, ChargingScenario):
            self.charging = True
            self.drive_mode = "Park"
            self.speed = 0.0  # Enforce stopped
            self.motor_rpm = 0.0
            
            # Realistic charging curve tapering
            # Full power up to 80%, then taper linearly to ~10% power at 100%
            base_power = self.current_scenario.get_charge_power()
            if self.soc >= 100.0:
                # Fully charged, stop
                target_power = 0.0
            elif self.soc > 80.0:
                # Taper: from 100% power at 80% SoC to 10% power at 100% SoC
                taper_factor = 1.0 - 0.9 * ((self.soc - 80.0) / 20.0)
                target_power = -base_power * max(0.1, taper_factor)
            else:
                target_power = -base_power
            
            # Smoothly ramp up/down charging power
            self.power = self.smooth_transition(self.power, target_power, 20, dt)
            
            # Add energy
            energy_added = abs(self.power) * (dt / 3600.0)
            self.soc += (energy_added / self.battery_capacity) * 100.0
            
            # Heat generation (I^2*R logic simplified)
            heat_factor = abs(self.power) / 10.0
            self.battery_temp += 0.05 * heat_factor * dt
            
            # Active thermal management cooling
            if self.battery_temp > 35.0:
                self.battery_temp -= 0.1 * dt
                
        elif self.charging:
             # Legacy or manual charging flag
            self._update_charging(dt)
        elif is_decelerating and decel_rate > 0.5:
            # Regenerative braking
            regen_power = self.physics.calculate_regen_power(self.speed, decel_rate)
            target_power = -min(regen_power, self.max_regen_power)
            
            # Smooth power transition
            self.power = self.smooth_transition(self.power, target_power, 15, dt)
            
            # Add energy back to battery (gradual)
            if self.power < 0:
                energy_recovered = abs(self.power) * (dt / 3600.0) * 0.75  # 75% efficiency
                soc_increase = (energy_recovered / self.battery_capacity) * 100.0
                self.soc += soc_increase
                
            # Minimal battery heating during regen
            self.battery_temp += 0.05 * dt
        elif self.speed > 0.5:
            # Normal driving power consumption
            accel_amount = max(0, self.speed - self.prev_speed) / dt if dt > 0 else 0
            target_power = self.physics.calculate_power_consumption(
                self.speed, is_accelerating, accel_amount
            )
            
            # Smooth power ramping (2-4 second transitions)
            self.power = self.smooth_transition(self.power, target_power, 10, dt)
            
            # Consume battery smoothly
            energy_used = self.power * (dt / 3600.0)
            soc_decrease = (energy_used / self.battery_capacity) * 100.0
            self.soc -= soc_decrease
            
            # Gradual motor temp increase
            temp_increase = (self.power / self.physics.max_power) * 0.4 * dt
            self.motor_temp += temp_increase
            
            # Gradual battery temp increase (slower)
            if self.power > 20:
                self.battery_temp += 0.15 * dt
                
        # Scenario-specific temperature boosts (Overheat scenarios)
        if hasattr(self.current_scenario, 'get_temp_boost'):
            boost = self.current_scenario.get_temp_boost()
            if isinstance(self.current_scenario, BatteryOverheatScenario):
                self.battery_temp += boost * dt
            elif isinstance(self.current_scenario, MotorOverheatScenario):
                self.motor_temp += boost * dt
        else:
            # Idle
            target_power = 1.0  # Stable idle power
            self.power = self.smooth_transition(self.power, target_power, 2, dt)
            
        # Temperature cooling (very gradual)
        if self.power < 10:
            # Motor cooling
            ambient = 25.0
            cooling_rate = 0.15 * dt
            if self.motor_temp > ambient:
                self.motor_temp -= cooling_rate
                
            # Battery cooling (slower)
            battery_ambient = 22.0
            if self.battery_temp > battery_ambient:
                self.battery_temp -= 0.08 * dt
        
        
        # Clamp temperatures (wide limits to allow overheat scenarios)
        self.motor_temp = max(20.0, min(150.0, self.motor_temp)) # Allow higher for failure simulation
        self.battery_temp = max(15.0, min(90.0, self.battery_temp))
        
        # CRITICAL: Thermal Shutdown Logic
        if self.motor_temp > 130.0 or self.battery_temp > 70.0:
            self.hv_fault = True
            self.motor_fault = True
            
        # CRITICAL: SoC Clamping & Dead Battery
        if self.soc <= 0.0:
            self.soc = 0.0
            self.power = 0.0
            self.target_speed = 0.0
            self.speed = self.smooth_transition(self.speed, 0.0, 2.0, dt) # Coast to stop
        elif self.soc > 100.0:
            self.soc = 100.0
            
        # CRITICAL: Prevent Infinite Regen (Overcharging)
        if self.soc >= 100.0 and self.power < 0:
            self.power = 0.0 # Cut regen/charging at 100%
            
        # CRITICAL: Fault Enforcement
        if self.hv_fault:
            self.power = 0.0
            self.target_speed = 0.0
            # Mechanical brakes or coasting
            self.speed = self.smooth_transition(self.speed, 0.0, 3.0, dt)
        elif self.motor_fault:
             # Limp Mode
            self.max_power = 20.0 # Severely limited power
            self.target_speed = min(self.target_speed, 30.0)

        # Update odometer and trip distance
        if self.speed > 0:
            distance_km = self.speed * (dt / 3600.0)
            self.odometer += distance_km
            self.trip_distance += distance_km
        
        # Battery voltage (smooth)
        target_voltage = 320 + (self.soc / 100.0) * 80  # 320-400V
        self.battery_voltage = self.smooth_transition(
            self.battery_voltage, target_voltage, 5, dt
        )
        
        # Battery current
        if abs(self.battery_voltage) > 1:
            self.battery_current = (self.power * 1000.0) / self.battery_voltage
        
        # SOH degradation (extremely slow)
        self.soh -= 0.0000005 * dt
        
        # Clamp SoC
        self.soc = max(0.0, min(100.0, self.soc))
        
        # Calculate range and efficiency
        if self.speed > 1 and self.power > 0:
            # Wh/km efficiency
            self.efficiency = (self.power * 1000) / max(self.speed, 1)
            # Remaining range
            remaining_kwh = (self.soc / 100.0) * self.battery_capacity
            self.range = (remaining_kwh * 1000) / max(self.efficiency, 100)
        else:
            # Default efficiency when not moving
            self.efficiency = 165  # Wh/km typical
            self.range = ((self.soc / 100.0) * self.battery_capacity * 1000) / self.efficiency
        
        # Update GPS (smooth circular path)
        if self.speed > 0:
            radius = 0.015
            self.path_angle += (self.speed / 3600.0) * 0.08
            self.lat = 28.6139 + radius * math.sin(self.path_angle)
            self.lon = 77.2090 + radius * math.cos(self.path_angle)
            self.heading = (self.path_angle * 180 / math.pi) % 360
        
        # Store previous values
        self.prev_speed = self.speed
        self.prev_power = self.power
        
    def _update_charging(self, dt):
        """Update charging state"""
        charge_power = min(self.max_charge_power, 150)
        energy_added = charge_power * (dt / 3600.0)
        self.soc += (energy_added / self.battery_capacity) * 100.0
        self.power = -charge_power
        self.battery_temp += 0.2 * dt
        self.motor_temp -= 0.1 * dt  # Motor cools while charging
        
    def get_data(self):
        """Get current state as dictionary"""
        return {
            'speed': round(self.speed, 2),
            'soc': round(self.soc, 2),
            'soh': round(self.soh, 2),
            'power': round(self.power, 2),
            'motor_rpm': round(self.motor_rpm, 0),
            'battery_voltage': round(self.battery_voltage, 1),
            'battery_current': round(self.battery_current, 1),
            'battery_temp': round(self.battery_temp, 1),
            'motor_temp': round(self.motor_temp, 1),
            'range': round(self.range, 1),
            'odometer': round(self.odometer * 1000, 1),
            'trip_distance_a': round(self.trip_distance, 2),
            'efficiency': round(self.efficiency, 0),
            'ready': self.ready,
            'charging': self.charging,
            'drive_mode': self.drive_mode,
            'lat': round(self.lat, 6),
            'lon': round(self.lon, 6),
            'heading': round(self.heading, 1),
            'next_turn_dist': "500m",
            # Auto-computed warning flags from physical state
            'bms_warning': self.battery_temp > 45 or self.soc < 5 or self.soh < 75,
            'hv_warning': self.hv_fault,
            'temp_warning': self.battery_temp > 42 or self.motor_temp > 75,
            'motor_fault': self.motor_temp > 85 or self.motor_fault,
            'reduced_power': (self.battery_temp > 45 or self.motor_temp > 80
                              or self.soc < 10 or self.hv_fault),
            'abs': self.abs_active,
            'tc': self.tc_active,
            'seatbelt': self.seatbelt_warning,
        }


class SimulatorController:
    """Controls scenario execution and data transmission"""
    
    def __init__(self, simulator, sock, dest_addr):
        self.simulator = simulator
        self.sock = sock
        self.dest_addr = dest_addr
        self.running = False
        self.paused = False
        self.current_scenario_name = "Idle"
        
    def start_scenario(self, scenario):
        """Start a driving scenario"""
        self.simulator.set_scenario(scenario)
        self.current_scenario_name = scenario.name
        self.running = True
        self.paused = False
        
    def pause(self):
        """Pause current scenario"""
        self.paused = True
        
    def resume(self):
        """Resume paused scenario"""
        self.paused = False
        
    def stop(self):
        """Stop current scenario"""
        self.running = False
        self.paused = False
        self.simulator.current_scenario = None
        self.simulator.target_speed = 0
        self.current_scenario_name = "Idle"
        
    def update_and_send(self, dt):
        """Update simulator and send data"""
        if not self.paused:
            self.simulator.update(dt)
        
        # Send data
        data = self.simulator.get_data()
        json_data = json.dumps(data).encode()
        try:
            self.sock.sendto(json_data, self.dest_addr)
        except Exception as e:
            pass  # Silently handle send errors
            
    def get_status(self):
        """Get current status string"""
        if not self.running:
            return "Idle"
        elif self.paused:
            return f"{self.current_scenario_name} (Paused)"
        else:
            elapsed = self.simulator.current_scenario.elapsed_time if self.simulator.current_scenario else 0
            return f"{self.current_scenario_name} - {int(elapsed)}s"


class SimulatorGUI:
    """Tkinter GUI for scenario control"""
    
    def __init__(self, controller):
        self.controller = controller
        self.root = tk.Tk()
        self.root.title("EV Drive Simulator - Realistic Physics")
        self.root.geometry("550x450")
        
        # Scenario definitions
        self.scenarios = {
            "City Commute": CityCommuteScenario(),
            "Highway Cruise": HighwayCruiseScenario(),
            "Eco Mode": EcoModeScenario(),
            "Spirited Drive": SpiritedDriveScenario(),
            "Mixed Urban/Highway": MixedUrbanHighwayScenario(),
            "AC Charge (Level 1)": ChargingScenario(1.4),
            "AC Charge (Level 2)": ChargingScenario(7.2),
            "DC Fast Charge": ChargingScenario(150.0),
            "─── Edge Cases ───": None,
            "Aggressive Driver": AggressiveDriverScenario(),
            "Battery Overheat": BatteryOverheatScenario(),
            "Motor Overheat": MotorOverheatScenario(),
            "Degraded Battery": DegradedBatteryScenario(),
            "Critical Low Battery": CriticalLowBatteryScenario(),
            "HV System Fault": HVSystemFaultScenario(),
        }
        
        self._create_widgets()
        
    def _create_widgets(self):
        # Title
        title = tk.Label(self.root, text="EV Drive Simulator", font=("Arial", 18, "bold"))
        title.pack(pady=10)
        
        subtitle = tk.Label(self.root, text="Ultra-Smooth Realistic EV Behavior", 
                           font=("Arial", 10), fg="#666")
        subtitle.pack()
        
        # Scenario selector
        selector_frame = tk.Frame(self.root)
        selector_frame.pack(pady=15)
        
        tk.Label(selector_frame, text="Select Scenario:", font=("Arial", 12)).pack(side=tk.LEFT, padx=5)
        
        self.scenario_var = tk.StringVar(value="City Commute")
        scenario_dropdown = ttk.Combobox(
            selector_frame, 
            textvariable=self.scenario_var,
            values=list(self.scenarios.keys()),
            state="readonly",
            width=22,
            font=("Arial", 11)
        )
        scenario_dropdown.pack(side=tk.LEFT, padx=5)
        
        # Buttons
        button_frame = tk.Frame(self.root)
        button_frame.pack(pady=10)
        
        self.start_btn = tk.Button(
            button_frame, 
            text="▶ Simulate Drive", 
            command=self._start_simulation,
            bg="#4CAF50",
            fg="white",
            font=("Arial", 12, "bold"),
            padx=15,
            pady=8
        )
        self.start_btn.grid(row=0, column=0, padx=5, pady=5)
        
        self.pause_btn = tk.Button(
            button_frame,
            text="⏸ Pause",
            command=self._toggle_pause,
            bg="#FF9800",
            fg="white",
            font=("Arial", 12, "bold"),
            padx=15,
            pady=8,
            state=tk.DISABLED
        )
        self.pause_btn.grid(row=0, column=1, padx=5, pady=5)
        
        self.stop_btn = tk.Button(
            button_frame,
            text="⏹ Stop",
            command=self._stop_simulation,
            bg="#F44336",
            fg="white",
            font=("Arial", 12, "bold"),
            padx=15,
            pady=8,
            state=tk.DISABLED
        )
        self.stop_btn.grid(row=0, column=2, padx=5, pady=5)
        
        # Status display
        status_frame = tk.LabelFrame(self.root, text="Status", font=("Arial", 12, "bold"), padx=10, pady=10)
        status_frame.pack(pady=10, padx=20, fill=tk.BOTH, expand=True)
        
        self.status_label = tk.Label(status_frame, text="Idle", font=("Arial", 14, "bold"), fg="#2196F3")
        self.status_label.pack(pady=5)
        
        # Real-time data display
        data_frame = tk.Frame(status_frame)
        data_frame.pack(pady=5)
        
        # Left column
        left_col = tk.Frame(data_frame)
        left_col.grid(row=0, column=0, padx=15)
        
        self.speed_label = tk.Label(left_col, text="Speed: 0 km/h", font=("Arial", 11))
        self.speed_label.pack(anchor=tk.W, pady=2)
        
        self.power_label = tk.Label(left_col, text="Power: 0 kW", font=("Arial", 11))
        self.power_label.pack(anchor=tk.W, pady=2)
        
        self.soc_label = tk.Label(left_col, text="SoC: 85%", font=("Arial", 11))
        self.soc_label.pack(anchor=tk.W, pady=2)
        
        self.rpm_label = tk.Label(left_col, text="RPM: 0", font=("Arial", 11))
        self.rpm_label.pack(anchor=tk.W, pady=2)
        
        # Right column
        right_col = tk.Frame(data_frame)
        right_col.grid(row=0, column=1, padx=15)
        
        self.temp_label = tk.Label(right_col, text="Motor: 30°C", font=("Arial", 11))
        self.temp_label.pack(anchor=tk.W, pady=2)
        
        self.batt_temp_label = tk.Label(right_col, text="Battery: 22°C", font=("Arial", 11))
        self.batt_temp_label.pack(anchor=tk.W, pady=2)
        
        self.range_label = tk.Label(right_col, text="Range: 400 km", font=("Arial", 11))
        self.range_label.pack(anchor=tk.W, pady=2)
        
        self.eff_label = tk.Label(right_col, text="Efficiency: 165 Wh/km", font=("Arial", 11))
        self.eff_label.pack(anchor=tk.W, pady=2)
        
        # Update display periodically
        self._update_display()
        
    def _start_simulation(self):
        scenario_name = self.scenario_var.get()
        scenario = self.scenarios.get(scenario_name)
        
        if scenario is None:
            return  # Safety for separator or invalid selection
            
        scenario.reset()
        self.controller.start_scenario(scenario)
        
        self.start_btn.config(state=tk.DISABLED)
        self.pause_btn.config(state=tk.NORMAL, text="⏸ Pause")
        self.stop_btn.config(state=tk.NORMAL)
        
    def _toggle_pause(self):
        if self.controller.paused:
            self.controller.resume()
            self.pause_btn.config(text="⏸ Pause")
        else:
            self.controller.pause()
            self.pause_btn.config(text="▶ Resume")
            
    def _stop_simulation(self):
        self.controller.stop()
        
        self.start_btn.config(state=tk.NORMAL)
        self.pause_btn.config(state=tk.DISABLED, text="⏸ Pause")
        self.stop_btn.config(state=tk.DISABLED)
        
    def _update_display(self):
        """Update status display"""
        self.status_label.config(text=self.controller.get_status())
        
        # Update data labels with color coding
        sim = self.controller.simulator
        self.speed_label.config(text=f"Speed: {sim.speed:.1f} km/h")
        
        # Color code power (green = regen, red = consumption)
        power_color = "#4CAF50" if sim.power < 0 else "#333"
        self.power_label.config(
            text=f"Power: {sim.power:+.1f} kW",
            fg=power_color
        )
        
        self.soc_label.config(text=f"SoC: {sim.soc:.1f}%")
        self.temp_label.config(text=f"Motor: {sim.motor_temp:.1f}°C")
        self.batt_temp_label.config(text=f"Battery: {sim.battery_temp:.1f}°C")
        self.rpm_label.config(text=f"RPM: {sim.motor_rpm:.0f}")
        self.range_label.config(text=f"Range: {sim.range:.0f} km")
        self.eff_label.config(text=f"Efficiency: {sim.efficiency:.0f} Wh/km")
        
        # Schedule next update
        self.root.after(100, self._update_display)
        
    def run(self):
        """Start GUI main loop"""
        self.root.mainloop()


def simulation_loop(controller):
    """Main simulation loop - 200ms updates for smooth behavior"""
    while True:
        controller.update_and_send(0.2)  # 200ms update interval
        time.sleep(0.2)


if __name__ == "__main__":
    print("=" * 65)
    print("EV Drive Simulator - Ultra-Smooth Realistic Behavior")
    print("=" * 65)
    
    # Initialize components
    simulator = EVSimulator()
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    dest_addr = ('localhost', 5555)
    controller = SimulatorController(simulator, sock, dest_addr)
    
    print(f"\nVehicle Type: {simulator.vehicle_type.value}")
    print(f"Battery Capacity: {simulator.battery_capacity} kWh")
    print(f"Max Power: {simulator.physics.max_power} kW")
    print(f"Update Rate: 200ms (5 Hz) for smooth transitions")
    print(f"\nSending data to localhost:5555...")
    
    # Start simulation thread
    sim_thread = threading.Thread(target=simulation_loop, args=(controller,), daemon=True)
    sim_thread.start()
    
    if HAS_GUI:
        print("\nLaunching GUI... Select a scenario and watch smooth EV behavior!\n")
        gui = SimulatorGUI(controller)
        gui.run()
    else:
        print("\nGUI not available. Running with basic simulation...")
        try:
            while True:
                time.sleep(1)
        except KeyboardInterrupt:
            print("\nSimulator stopped.")
