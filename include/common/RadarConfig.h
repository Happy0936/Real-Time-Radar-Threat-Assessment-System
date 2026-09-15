#ifndef RADAR_CONFIG_H
#define RADAR_CONFIG_H

struct RadarConfig {

    // Radar settings
    double detectionRange;
    double noiseStdDev;

    // Threat assessment settings
    double highThreatDistance;
    double highThreatVelocity;
    double mediumThreatDistance;

    // Processing settings
    int processingCycles;
};

#endif