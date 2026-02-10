# Linux (Ubuntu/Debian) Setup Guide

This guide covers setup, fresh re-installation, and troubleshooting.

## 🎯 Quick Start: Fresh Download & Build

**Use this if you already have the system set up but want to delete everything and start fresh with the latest code.**

### 1. Stop Everything
First, make sure no old processes are running in the background.

```bash
pkill -f ev-cluster
pkill -f ev_simulator
```

### 2. Remove Old Repository
Delete the existing folder completely.

```bash
cd ~  # Go to home directory (or wherever you cloned it)
rm -rf ev-instrument-cluster
```

### 3. Clone Fresh Repository
Download the latest version of the code.

```bash
git clone https://github.com/kilobyte23/ev-instrument-cluster.git
cd ev-instrument-cluster
```

### 4. Build from Scratch
Create a clean build directory and compile.

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

### 5. Run it!
**Terminal 1:** Start the Simulator
```bash
# From project root
python3 tools/ev_simulator.py
```

**Terminal 2:** Start the Cluster
```bash
# From build directory
./ev-cluster
```

---

## 📦 First-Time System Setup (Only needed once)

If this is a brand new machine, install these dependencies first:

```bash
sudo apt update
sudo apt install build-essential cmake git python3 python3-pip

# Qt6 Libraries (Core, GUI, QML, SQL, Location)
sudo apt install qt6-base-dev qt6-declarative-dev qt6-base-dev-tools \
    qt6-location-dev qt6-positioning-dev qt6-lottie-dev libqt6sql6-sqlite

# Optional: Fonts
sudo apt install fonts-inter || echo "Skipping font install"
```

---

## 🛠️ Troubleshooting

### "Failed to bind port 5555"
This means an old version is still running in the background.
**Fix:** Run `pkill -f ev-cluster` and `pkill -f ev_simulator`.

### "Qt6 package not found"
Ensure `qt6-base-dev` is installed. If installed via online installer, use:
```bash
cmake -DCMAKE_PREFIX_PATH=~/Qt/6.x.x/gcc_64 ..
```

### Clear Database
To reset all trip history and settings:
```bash
rm ~/.local/share/ev-cluster/ev_cluster.db
```
