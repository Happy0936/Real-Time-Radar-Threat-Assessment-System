#include <iostream>
#include <vector>
#include <fstream>

#include "../include/common/Target.h"
#include "../include/common/RadarConfig.h"

#include "config/ConfigLoader.h"
#include "radar/RadarSimulator.h"
#include "detection/TargetDetector.h"
#include "tracking/KalmanTracker.h"
#include "threat/ThreatAssessment.h"
#include "decision/DecisionEngine.h"

int main() {

    // ========================================
    // Load Configuration
    // ========================================

    RadarConfig config;

    try {

        config = ConfigLoader::loadConfig(
            "config/radar_config.json"
        );

    }
    catch (const std::exception& error) {

        std::cerr << "Configuration Error: "
                  << error.what()
                  << "\n";

        return 1;
    }


    // ========================================
    // Initialize System Components
    // ========================================

    RadarSimulator radar(config.noiseStdDev);
    TargetDetector detector;
    KalmanTracker tracker;
    ThreatAssessment threatAssessment(config);
    DecisionEngine decisionEngine;


    // ========================================
    // Initialize CSV Logger
    // ========================================

    std::ofstream logFile(
        "data/radar_log.csv"
    );

    if (!logFile.is_open()) {

        std::cerr << "Error: Could not open "
                  << "data/radar_log.csv\n";

        return 1;
    }

    // CSV header
    logFile << "cycle,target_id,raw_distance,"
            << "filtered_distance,velocity,"
            << "threat,decision\n";


    // ========================================
    // System Information
    // ========================================

    std::cout << "========================================\n";
    std::cout << " REAL-TIME RADAR THREAT ASSESSMENT\n";
    std::cout << "========================================\n";

    std::cout << "Radar Range      : "
              << config.detectionRange
              << " m\n";

    std::cout << "Noise Std Dev    : "
              << config.noiseStdDev
              << " m\n";

    std::cout << "Processing Cycles: "
              << config.processingCycles
              << "\n";

    std::cout << "Logging          : ENABLED\n";


    // ========================================
    // Real-Time Processing Loop
    // ========================================

    for (
        int cycle = 1;
        cycle <= config.processingCycles;
        cycle++
    ) {

        std::cout << "\n========== RADAR CYCLE "
                  << cycle
                  << " ==========\n";


        // 1. Generate radar targets
        std::vector<Target> radarTargets =
            radar.generateTargets();


        // 2. Detect targets
        std::vector<Target> detectedTargets =
            detector.detectTargets(
                radarTargets,
                config.detectionRange
            );


        // 3. Track targets
        std::vector<Target> trackedTargets =
            tracker.update(detectedTargets);


        // 4. Threat assessment + decision
        for (const Target& target : trackedTargets) {

            std::string threat =
                threatAssessment.calculateThreat(target);

            std::string decision =
                decisionEngine.makeDecision(threat);


            // ========================================
            // Console Output
            // ========================================

            std::cout << "Target ID : "
                      << target.id
                      << "\n";

            std::cout << "Raw Distance      : "
                      << target.distance
                      << " m\n";

            std::cout << "Filtered Distance : "
                      << target.filteredDistance
                      << " m\n";

            std::cout << "Velocity  : "
                      << target.velocity
                      << " m/s\n";

            std::cout << "Threat    : "
                      << threat
                      << "\n";

            std::cout << "Decision  : "
                      << decision
                      << "\n";


            // ========================================
            // CSV Logging
            // ========================================

            logFile << cycle << ","
                    << target.id << ","
                    << target.distance << ","
                    << target.filteredDistance << ","
                    << target.velocity << ","
                    << threat << ","
                    << decision
                    << "\n";


            std::cout << "----------------------------------------\n";
        }
    }


    // ========================================
    // Close Log File
    // ========================================

    logFile.close();

    std::cout << "\nRadar processing completed.\n";
    std::cout << "Log saved to: data/radar_log.csv\n";

    return 0;
}