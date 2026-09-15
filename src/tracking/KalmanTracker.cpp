#include "KalmanTracker.h"

KalmanTracker::KalmanTracker() {
}

std::vector<Target> KalmanTracker::update(
    const std::vector<Target>& targets
) {

    std::vector<Target> trackedTargets;

    const double dt = 0.1;

    for (const Target& target : targets) {

        TrackState& state = tracks[target.id];

        // ========================================
        // INITIALIZATION
        // ========================================

        if (!state.initialized) {

            state.distance = target.distance;
            state.velocity = target.velocity;

            state.positionVariance = 100.0;
            state.velocityVariance = 25.0;

            state.positionProcessNoise = 1.0;
            state.velocityProcessNoise = 0.5;

            state.measurementNoise = 225.0;

            state.initialized = true;

        } else {

            // ========================================
            // 1. PREDICTION
            // ========================================

            double predictedDistance =
                state.distance -
                state.velocity * dt;

            double predictedVelocity =
                state.velocity;

            // Increase uncertainty because
            // the system is predicting forward
            double predictedPositionVariance =
                state.positionVariance +
                state.positionProcessNoise;

            double predictedVelocityVariance =
                state.velocityVariance +
                state.velocityProcessNoise;


            // ========================================
            // 2. MEASUREMENT
            // ========================================

            double measuredDistance =
                target.distance;

            double measuredVelocity =
                target.velocity;


            // ========================================
            // 3. KALMAN GAIN
            // ========================================

            double positionGain =
                predictedPositionVariance /
                (
                    predictedPositionVariance +
                    state.measurementNoise
                );

            double velocityGain =
                predictedVelocityVariance /
                (
                    predictedVelocityVariance +
                    state.measurementNoise
                );


            // ========================================
            // 4. CORRECTION
            // ========================================

            state.distance =
                predictedDistance +
                positionGain *
                (measuredDistance - predictedDistance);

            state.velocity =
                predictedVelocity +
                velocityGain *
                (measuredVelocity - predictedVelocity);


            // ========================================
            // 5. UPDATE UNCERTAINTY
            // ========================================

            state.positionVariance =
                (1.0 - positionGain) *
                predictedPositionVariance;

            state.velocityVariance =
                (1.0 - velocityGain) *
                predictedVelocityVariance;
        }


        // ========================================
        // CREATE TRACKED TARGET
        // ========================================

        Target trackedTarget = target;

        trackedTarget.filteredDistance =
            state.distance;

        trackedTarget.velocity =
            state.velocity;

        trackedTargets.push_back(trackedTarget);
    }

    return trackedTargets;
}