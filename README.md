# Real-Time Radar Threat Assessment System

A C++ based real-time radar simulation system designed to demonstrate
target detection, tracking, threat assessment, and decision-making
for embedded and real-time software applications.

## Overview

This project simulates a radar processing pipeline where sensor
measurements are generated with noise, detected targets are tracked
using a Kalman filter, and each target is classified into different
threat levels.

The system demonstrates concepts commonly used in real-time and
embedded software development:

- C++17
- Real-time processing loop
- Sensor simulation
- Target detection
- Kalman filtering
- Threat assessment
- Decision logic
- Configuration management
- CSV data logging
- Unit testing
- Python-based visualization

## System Architecture

```text
Radar Simulator
      |
      v
Target Detection
      |
      v
Kalman Tracking
      |
      v
Threat Assessment
      |
      v
Decision Engine
      |
      v
CSV Logging
      |
      v
Python Visualization


Key Features
1. Radar Simulation

Generates multiple simulated targets with:

Distance
Velocity
Sensor noise
Target movement
2. Target Detection

Filters targets based on the configured radar detection range.

3. Kalman Tracking

Tracks target distance and velocity while reducing the effect of
measurement noise.

Each target maintains its own tracking state.

4. Threat Assessment

Targets are classified into:

HIGH
MEDIUM
LOW

based on configurable distance and velocity thresholds.

5. Decision Engine

The system generates a corresponding decision:

Threat	Decision
HIGH	PRIORITY RESPONSE
MEDIUM	CONTINUE TRACKING
LOW	MONITOR
6. External Configuration

System parameters are stored in:

config/radar_config.json

Example parameters include:

Radar range
Sensor noise
Processing cycles
High-threat distance
High-threat velocity
Medium-threat distance
7. CSV Logging

Each processing cycle is stored in:

data/radar_log.csv

Example:

cycle,target_id,raw_distance,filtered_distance,velocity,threat,decision
1,101,845.612,845.612,110,HIGH,PRIORITY RESPONSE
1,102,2429.23,2429.23,35,LOW,MONITOR
1,103,1481.14,1481.14,60,MEDIUM,CONTINUE TRACKING
8. Python Visualization

The logged data can be visualized using Python.

The dashboard provides:

Radar target view
Current target status
Threat summary
Filtered distance tracking
Project Structure
Real-Time-Radar-Threat-System/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── src/
│   ├── main.cpp
│   │
│   ├── radar/
│   │   ├── RadarSimulator.cpp
│   │   └── RadarSimulator.h
│   │
│   ├── detection/
│   │   ├── TargetDetector.cpp
│   │   └── TargetDetector.h
│   │
│   ├── tracking/
│   │   ├── KalmanTracker.cpp
│   │   └── KalmanTracker.h
│   │
│   ├── threat/
│   │   ├── ThreatAssessment.cpp
│   │   └── ThreatAssessment.h
│   │
│   ├── decision/
│   │   ├── DecisionEngine.cpp
│   │   └── DecisionEngine.h
│   │
│   └── config/
│       ├── ConfigLoader.cpp
│       └── ConfigLoader.h
│
├── include/
│   └── common/
│       ├── Target.h
│       └── RadarConfig.h
│
├── tests/
│   ├── test_detection.cpp
│   ├── test_tracking.cpp
│   ├── test_threat.cpp
│   └── test_decision.cpp
│
├── python/
│   └── visualize.py
│
├── config/
│   └── radar_config.json
│
└── data/
    ├── sample_targets.csv
    └── radar_log.csv
Technologies
Programming Languages
C++17
Python
C++ Concepts
Object-Oriented Programming
STL
Vectors
Hash Maps
File I/O
Modular architecture
Exception handling
Unit testing
Algorithms
Target detection
Kalman filtering
Rule-based threat assessment
Decision logic
Tools
CMake
MinGW/GCC
Git
GitHub
VS Code
How to Build
Requirements
C++17 compatible compiler
CMake
MinGW/GCC
Build

From the project root:

cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
Run the Application
./build/radar_system.exe

The application runs the configured number of radar processing
cycles and generates:

data/radar_log.csv
Run Tests
Detection Test
./build/test_detection.exe
Tracking Test
./build/test_tracking.exe
Threat Assessment Test
./build/test_threat.exe
Decision Engine Test
./build/test_decision.exe

All tests should report successful execution.

Run Visualization

Install the required Python packages:

pip install pandas matplotlib

Then run:

python python/visualize.py
Sample Processing Flow
Sensor Measurement
       |
       v
Detection
       |
       v
Tracking
       |
       v
Threat Classification
       |
       v
Decision
       |
       v
Logging
Engineering Focus

This project focuses on software engineering concepts relevant to
embedded and real-time systems:

Modular C++ architecture
Deterministic processing flow
Sensor-data processing
State-based target tracking
Configuration-driven behavior
Real-time processing cycles
Automated testing
Data logging
Visualization and analysis
Disclaimer

This project is an educational radar simulation. It does not
interface with real radar hardware or implement operational
weapon-control or electronic-warfare functionality.