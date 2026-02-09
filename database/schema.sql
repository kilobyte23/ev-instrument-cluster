CREATE TABLE IF NOT EXISTS trips (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    start_time INTEGER,
    end_time INTEGER,
    distance_km REAL,
    energy_kwh REAL,
    avg_speed_kmh REAL
);

CREATE TABLE IF NOT EXISTS charging_logs (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    timestamp INTEGER,
    plug_in_soc REAL,
    unplug_soc REAL,
    energy_added_kwh REAL,
    max_power_kw REAL,
    location_lat REAL,
    location_lon REAL
);
