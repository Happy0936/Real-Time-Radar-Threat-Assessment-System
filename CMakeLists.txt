cmake_minimum_required(VERSION 3.10)

project(RealTimeRadarThreatSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========================================
# Main Application
# ========================================

add_executable(radar_system

    src/main.cpp

    src/radar/RadarSimulator.cpp

    src/detection/TargetDetector.cpp

    src/tracking/KalmanTracker.cpp

    src/threat/ThreatAssessment.cpp

    src/decision/DecisionEngine.cpp

    src/config/ConfigLoader.cpp
)

target_include_directories(radar_system PRIVATE
    include
    src
)


# ========================================
# Tests
# ========================================

add_executable(test_detection
    tests/test_detection.cpp
    src/detection/TargetDetector.cpp
)

target_include_directories(test_detection PRIVATE
    include
    src
)


add_executable(test_tracking
    tests/test_tracking.cpp
    src/tracking/KalmanTracker.cpp
)

target_include_directories(test_tracking PRIVATE
    include
    src
)


add_executable(test_threat
    tests/test_threat.cpp
    src/threat/ThreatAssessment.cpp
)

target_include_directories(test_threat PRIVATE
    include
    src
)


add_executable(test_decision
    tests/test_decision.cpp
    src/decision/DecisionEngine.cpp
)

target_include_directories(test_decision PRIVATE
    include
    src
)