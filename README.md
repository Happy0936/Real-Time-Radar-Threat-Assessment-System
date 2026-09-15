# Real-Time Radar Threat Assessment System

A **C++17-based real-time radar simulation system** designed to demonstrate target detection, tracking, threat assessment, and decision-making concepts for embedded and real-time software applications.

## Overview

This project simulates a radar processing pipeline where sensor measurements are generated with noise, detected targets are tracked using a Kalman-style filter, and each target is classified into different threat levels.

The system demonstrates concepts commonly used in **real-time and embedded software development**:

* C++17
* Real-time processing loop
* Sensor simulation
* Target detection
* Kalman filtering
* Threat assessment
* Decision logic
* Configuration management
* CSV data logging
* Unit testing
* Python-based visualization

## System Architecture

```text
┌─────────────────────┐
│   Radar Simulator   │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Target Detection   │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Kalman Tracking    │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│ Threat Assessment   │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│   Decision Engine   │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│    CSV Logging      │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│ Python Visualization│
└─────────────────────┘
```

## Key Features

### 1. Radar Simulation

Generates multiple simulated targets with:

* Distance
* Velocity
* Sensor noise
* Target movement

### 2. Target Detection

Filters targets based on the configured radar detection range.

### 3. Kalman Tracking

Tracks target distance and velocity while reducing the effect of measurement noise.

Each target maintains its own tracking state.

### 4. Threat Assessment

Targets are classified into three threat levels:

* **HIGH**
* **MEDIUM**
* **LOW**

Classification is based on configurable distance and velocity thresholds.

### 5. Decision Engine

The system generates a corresponding decision based on the assessed threat level.

| Threat Level | Decision          |
| ------------ | ----------------- |
| HIGH         | PRIORITY RESPONSE |
| MEDIUM       | CONTINUE TRACKING |
| LOW          | MONITOR           |

### 6. External Configuration

System parameters are stored in:

```text
config/radar_config.json
```

Configurable parameters include:

* Radar range
* Sensor noise
* Processing cycles
* High-threat distance
* High-threat velocity
* Medium-threat distance

### 7. CSV Logging

Each processing cycle is stored in:

```text
data/radar_log.csv
```

Example:

```csv
cycle,target_id,raw_distance,filtered_distance,velocity,threat,decision
1,101,845.612,845.612,110,HIGH,PRIORITY RESPONSE
1,102,2429.23,2429.23,35,LOW,MONITOR
1,103,1481.14,1481.14,60,MEDIUM,CONTINUE TRACKING
```

### 8. Python Visualization

The logged radar data can be visualized using Python.

The dashboard provides:

* Radar target view
* Current target status
* Threat summary
* Filtered distance tracking

## Project Structure

```text
Real-Time-Radar-Threat-Assessment-System/
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
    └── sample_targets.csv
```

## Technologies

### Programming Languages

* **C++17**
* **Python**

### C++ Concepts

* Object-Oriented Programming
* STL
* Vectors
* Hash Maps
* File I/O
* Modular architecture
* Exception handling
* Unit testing

### Algorithms

* Target detection
* Kalman-style tracking
* Rule-based threat assessment
* Decision logic

### Tools

* CMake
* MinGW/GCC
* Git
* GitHub
* VS Code

## How to Build

### Requirements

* C++17 compatible compiler
* CMake
* MinGW/GCC

### Build

From the project root:

```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
```

## Run the Application

```bash
./build/radar_system.exe
```

The application runs the configured number of radar processing cycles and generates a radar processing log.

## Run Tests

### Detection Test

```bash
./build/test_detection.exe
```

### Tracking Test

```bash
./build/test_tracking.exe
```

### Threat Assessment Test

```bash
./build/test_threat.exe
```

### Decision Engine Test

```bash
./build/test_decision.exe
```

Expected results:

```text
Detection Test Passed!
Tracking Test Passed!
Threat Assessment Test Passed!
Decision Engine Test Passed!
```

## Run Visualization

Install the required Python packages:

```bash
pip install pandas matplotlib
```

Then run:

```bash
python python/visualize.py
```

The dashboard displays the latest target status, threat levels, and filtered target-distance trends.

## Sample Processing Flow

```text
Sensor Measurement
        │
        ▼
     Detection
        │
        ▼
     Tracking
        │
        ▼
Threat Classification
        │
        ▼
      Decision
        │
        ▼
      Logging
```

## Engineering Focus

This project focuses on software engineering concepts relevant to **embedded and real-time systems**:

* Modular C++ architecture
* Deterministic processing flow
* Sensor-data processing
* State-based target tracking
* Configuration-driven behavior
* Real-time processing cycles
* Automated testing
* Data logging
* Visualization and analysis

## Learning Outcomes

Through this project, the following concepts are demonstrated:

* Designing modular C++ applications
* Working with real-time processing loops
* Processing noisy sensor measurements
* Maintaining state for tracked objects
* Implementing filtering techniques
* Building rule-based decision systems
* Writing unit tests for C++ modules
* Using CMake for project builds
* Logging and analyzing system data

## Disclaimer

This project is an **educational radar simulation**. It does not interface with real radar hardware and does not implement operational weapon-control or electronic-warfare functionality.
