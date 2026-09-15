#ifndef RADAR_SIMULATOR_H
#define RADAR_SIMULATOR_H

#include <vector>

#include "../../include/common/Target.h"

class RadarSimulator {

private:

    double noiseStdDev;

public:

    RadarSimulator(double noiseStdDev = 15.0);

    std::vector<Target> generateTargets();
};

#endif