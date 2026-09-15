#include <iostream>
#include <cassert>

#include "../include/common/Target.h"
#include "../include/common/RadarConfig.h"
#include "../src/threat/ThreatAssessment.h"

int main() {

    // Test configuration
    RadarConfig config;

    config.highThreatDistance = 1000.0;
    config.highThreatVelocity = 80.0;
    config.mediumThreatDistance = 2000.0;

    ThreatAssessment assessment(config);


    // ========================================
    // HIGH threat
    // ========================================

    Target highTarget = {
        101,
        800.0,
        110.0,
        800.0,
        true
    };

    assert(
        assessment.calculateThreat(highTarget) == "HIGH"
    );


    // ========================================
    // MEDIUM threat
    // ========================================

    Target mediumTarget = {
        102,
        1500.0,
        60.0,
        1500.0,
        true
    };

    assert(
        assessment.calculateThreat(mediumTarget) == "MEDIUM"
    );


    // ========================================
    // LOW threat
    // ========================================

    Target lowTarget = {
        103,
        2500.0,
        30.0,
        2500.0,
        true
    };

    assert(
        assessment.calculateThreat(lowTarget) == "LOW"
    );


    std::cout << "Threat Assessment Test Passed!"
              << std::endl;

    return 0;
}