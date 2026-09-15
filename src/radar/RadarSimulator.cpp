#include "RadarSimulator.h"

#include <random>

RadarSimulator::RadarSimulator(double noiseStdDev)
    : noiseStdDev(noiseStdDev) {
}

std::vector<Target> RadarSimulator::generateTargets() {

    static double distance101 = 850.0;
    static double distance102 = 2400.0;
    static double distance103 = 1500.0;
    static double distance104 = 5000.0;

    // Random noise generator
    static std::default_random_engine generator(
        std::random_device{}()
    );

    std::normal_distribution<double> noise(
    0.0, noiseStdDev
);

    std::vector<Target> targets;

    // Raw noisy radar measurements
    targets.push_back({
        101,
        distance101 + noise(generator),
        110.0,
        0.0,
        true
    });

    targets.push_back({
        102,
        distance102 + noise(generator),
        35.0,
        0.0,
        true
    });

    targets.push_back({
        103,
        distance103 + noise(generator),
        60.0,
        0.0,
        true
    });

    targets.push_back({
        104,
        distance104 + noise(generator),
        20.0,
        0.0,
        true
    });

    // Simulate actual target movement
    distance101 -= 11.0;
    distance102 -= 3.5;
    distance103 -= 6.0;
    distance104 -= 2.0;

    return targets;
}