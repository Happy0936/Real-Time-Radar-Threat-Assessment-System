#ifndef THREAT_ASSESSMENT_H
#define THREAT_ASSESSMENT_H

#include <string>

#include "../../include/common/Target.h"
#include "../../include/common/RadarConfig.h"

class ThreatAssessment {

private:

    RadarConfig config;

public:

    ThreatAssessment(
        const RadarConfig& config
    );

    std::string calculateThreat(
        const Target& target
    );
};

#endif