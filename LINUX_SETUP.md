# Linux (Ubuntu/Debian) Setup Guide

This guide will help you set up the development environment for the EV Instrument Cluster on an Ubuntu System.

## 1. Install Dependencies

You need a C++ compiler, CMake, and the Qt6 development libraries.

```bash
sudo apt update
sudo apt install build-essential cmake git

# Install Qt6 Core, GUI, QML, and Quick controls
sudo apt install qt6-base-dev qt6-declarative-dev qt6-base-dev-tools

# Install Qt6 Location & Positioning (Important for Maps)
sudo apt install qt6-location-dev qt6-positioning-dev qt6-lottie-dev

# Install Python for the Signal Simulator
sudo apt install python3
```

*Note: If your Ubuntu version is older (e.g., 20.04), you might need to add a backports PPA or install Qt6 from the official installer to get a recent enough version.*

## 2. Clone the Repository

```bash
git clone https://github.com/kilobyte23/ev-instrument-cluster.git
cd ev-instrument-cluster
```

## 3. Build the Application

We use CMake to build the project.

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

## 4. Run the Simulator (Terminal 1)

The instrument cluster needs data to display anything meaningful. Run the Python simulator first.

```bash
# In a new terminal window, from the project root:
python3 tools/ev_simulator.py
```

*   **Controls**: Use `W/S` for speed, `1/2` for turn signals, `C` for charge mode.
*   **Note**: The simulator sends data over UDP loopback (127.0.0.1).

## 5. Run the Cluster (Terminal 2)

```bash
# From the build directory:
./ev-cluster
```

## Troubleshooting

*   **"Qt6 package not found"**: Ensure `qt6-base-dev` is installed. You may need to set `CMAKE_PREFIX_PATH` if you installed Qt via the online installer:
    ```bash
    cmake -DCMAKE_PREFIX_PATH=~/Qt/6.7.0/gcc_64 ..
    ```
*   **"Map not loading"**: Ensure you have an internet connection for the initial OSM tile download.
*   **"Plugin 's' not found"**: If you see QML errors about missing modules, maximize the window or check if `libqt6qml*` packages are all installed.
