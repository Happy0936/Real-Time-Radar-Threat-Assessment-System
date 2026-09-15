#include "ConfigLoader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

RadarConfig ConfigLoader::loadConfig(
    const std::string& filename
) {

    RadarConfig config{};

    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error(
            "Could not open configuration file: " + filename
        );
    }

    std::string line;

    while (std::getline(file, line)) {

        std::size_t colon = line.find(':');

        if (colon == std::string::npos) {
            continue;
        }

        std::string key =
            line.substr(0, colon);

        std::string value =
            line.substr(colon + 1);

        // Remove quotes from key
        key.erase(
            std::remove(key.begin(), key.end(), '"'),
            key.end()
        );

        // Remove comma and quotes from value
        value.erase(
            std::remove(value.begin(), value.end(), ','),
            value.end()
        );

        value.erase(
            std::remove(value.begin(), value.end(), '"'),
            value.end()
        );

        std::stringstream ss(value);


        // ========================================
        // Radar Configuration
        // ========================================

        if (key.find("radar_range") != std::string::npos) {

            ss >> config.detectionRange;
        }

        else if (
            key.find("noise_std_dev") != std::string::npos
        ) {

            ss >> config.noiseStdDev;
        }

        else if (
            key.find("processing_cycles") != std::string::npos
        ) {

            ss >> config.processingCycles;
        }


        // ========================================
        // Threat Configuration
        // ========================================

        else if (
            key.find("high_threat_distance")
            != std::string::npos
        ) {

            ss >> config.highThreatDistance;
        }

        else if (
            key.find("high_threat_velocity")
            != std::string::npos
        ) {

            ss >> config.highThreatVelocity;
        }

        else if (
            key.find("medium_threat_distance")
            != std::string::npos
        ) {

            ss >> config.mediumThreatDistance;
        }
    }


    return config;
}