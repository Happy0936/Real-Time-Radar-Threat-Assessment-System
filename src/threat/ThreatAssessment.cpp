#include "ThreatAssessment.h"

ThreatAssessment::ThreatAssessment(
    const RadarConfig& config
)
    : config(config) {
}

std::string ThreatAssessment::calculateThreat(
    const Target& target
) {

    // Use Kalman-filtered distance
    double distance =
        target.filteredDistance;

    // HIGH threat condition
    if (
        distance < config.highThreatDistance &&
        target.velocity > config.highThreatVelocity
    ) {

        return "HIGH";
    }

    // MEDIUM threat condition
    if (
        distance < config.mediumThreatDistance &&
        target.velocity > 50.0
    ) {

        return "MEDIUM";
    }

    return "LOW";
}