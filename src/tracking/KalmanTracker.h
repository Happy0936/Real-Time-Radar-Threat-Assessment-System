#ifndef KALMAN_TRACKER_H
#define KALMAN_TRACKER_H

#include <vector>
#include <unordered_map>

#include "../../include/common/Target.h"

class KalmanTracker {

private:

    struct TrackState {

        // State estimate
        double distance;
        double velocity;

        // State uncertainty
        double positionVariance;
        double velocityVariance;

        // Process noise
        double positionProcessNoise;
        double velocityProcessNoise;

        // Measurement noise
        double measurementNoise;

        bool initialized;
    };

    std::unordered_map<int, TrackState> tracks;

public:

    KalmanTracker();

    std::vector<Target> update(
        const std::vector<Target>& targets
    );
};

#endif