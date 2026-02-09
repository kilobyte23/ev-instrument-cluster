import socket
import json
import time
import math
import random

class EVSimulator:
    def __init__(self):
        self.soc = 80.0  # %
        self.speed = 0.0  # km/h
        self.target_speed = 0.0
        self.power = 0.0  # kW
        self.battery_temp = 25.0  # °C
        self.motor_temp = 30.0
        self.range = 350.0 # km
        self.odometer = 12050.0 # km
        self.charging = False
        self.drive_mode = "Normal"
        
        # GPS Simulation
        self.lat = 28.6139
        self.lon = 77.2090
        self.heading = 0.0
        self.path_angle = 0.0

        
    def update(self, dt):
        # Simulate power consumption
        if self.speed > 0:
            # Base consumption + speed factor (drag is cubic, simplified here)
            consumption = 2.0 + (self.speed / 100.0) ** 3 * 20.0  # kW
            
            # Simple regen simulation when slowing down (mock logic)
            # In a real sim, we'd look at acceleration/brake input
            
            # Decrease SoC based on power used
            # Assuming 75kWh battery for 4-wheeler, or 3.5kWh for 2-wheeler
            # Let's assume 4-wheeler 60kWh for this sim
            battery_capacity_kwh = 60.0
            
            energy_used_kwh = consumption * (dt / 3600.0)
            self.soc -= (energy_used_kwh / battery_capacity_kwh) * 100.0
            self.power = consumption
            
            # Increase temp slightly
            self.motor_temp += 0.05 * dt
        else:
            self.power = -2.0  # Idle usage
            # Cool down
            self.motor_temp -= 0.02 * dt
            
        # Simulate charging
        if self.charging:
            charge_power = 11.0 # kW
            energy_added = charge_power * (dt / 3600.0)
            self.soc += (energy_added / 60.0) * 100.0
            self.power = -charge_power # Negative power means input
            self.battery_temp += 0.01 * dt
        else:
            self.battery_temp -= 0.005 * dt

        # Clamp values
        self.soc = max(0.0, min(100.0, self.soc))
        self.motor_temp = max(20.0, min(90.0, self.motor_temp))
        self.battery_temp = max(20.0, min(45.0, self.battery_temp))
        
        # Update Range based on SoC and Efficiency
        efficiency = 0.15 + (0.05 if self.speed > 80 else 0) # kWh/km
        self.range = (self.soc / 100.0) * 77.4 / efficiency
        
        # Simulate GPS Movement (Circular Path)
        if self.speed > 0:
            # Move in a circle (0.01 degrees radius approx 1km)
            radius = 0.02
            self.path_angle += (self.speed / 3600.0) * 0.1 # Move angle based on speed
            self.lat = 28.6139 + radius * math.sin(self.path_angle)
            self.lon = 77.2090 + radius * math.cos(self.path_angle)
            self.heading = (self.path_angle * 180 / math.pi) % 360

    def set_speed(self, target_speed):
        # Simple lerp for smooth speed change simulation
        diff = target_speed - self.speed
        self.speed += diff * 0.1

    def toggle_charging(self):
        self.charging = not self.charging
        print(f"Charging: {self.charging}")

    def send_data(self, sock, addr):
        data = {
            'speed': round(self.speed, 1),
            'soc': round(self.soc, 1),
            'power': round(self.power, 1),
            'battery_voltage': round(350 + (self.soc/100)*50, 1),
            'battery_current': round(self.power * 1000 / 350, 1),
            'battery_temp': round(self.battery_temp, 1),
            'motor_temp': round(self.motor_temp, 1),
            'range': round(self.range, 1),
            'ready': True,
            'charging': self.charging,
            'drive_mode': self.drive_mode,
            
            # GPS
            'lat': self.lat,
            'lon': self.lon,
            'heading': self.heading,
            
            # Simulated Indicators
            'left_signal': int(time.time()) % 2 == 0 if self.speed < 20 else False,
            'hv_warning': self.soc < 5,
            'bms_warning': self.battery_temp > 40,
            
            # Standard Indicators (Random toggles for demo)
            'abs': False,
            'tc': False,
            'seatbelt': self.speed > 10 and self.speed < 15, # Mock warning
            'door_ajar': self.speed == 0 and int(time.time()) % 10 == 0,
            'parking': self.speed == 0,
            'low_12v': False,
            
            # Charging
            'time_to_full': int((100 - self.soc) * 60 / 10) if self.charging else 0, # Approx minutes
            
            # Nav
            'next_turn_dist': "500m"
        }
        json_data = json.dumps(data).encode()
        try:
            sock.sendto(json_data, addr)
        except Exception as e:
            print(f"Error sending: {e}")

# Run simulation
if __name__ == "__main__":
    sim = EVSimulator()
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    dest_addr = ('localhost', 5555)
    
    print("EV Simulator running on localhost:5555...")
    print("Commands: w=accelerate, s=brake, c=charge, q=quit")

    # Non-blocking input handling would be better, but for simplicity:
    # We will just run an auto-loop.
    
    target_speed = 0
    try:
        while True:
            # Randomly fluctuate target speed to make it interesting
            if random.random() < 0.05:
                target_speed = random.randint(0, 120)
            
            sim.set_speed(target_speed)
            sim.update(0.1)
            sim.send_data(sock, dest_addr)
            time.sleep(0.1)
    except KeyboardInterrupt:
        print("Simulator stopped.")
