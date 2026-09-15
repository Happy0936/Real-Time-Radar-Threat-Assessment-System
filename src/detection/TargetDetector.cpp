#include "TargetDetector.h"

std::vector<Target> TargetDetector::detectTargets(
    const std::vector<Target>& targets,
    double maximumRange
) {

    std::vector<Target> detectedTargets;

    for (const Target& target : targets) {

        if (target.distance <= maximumRange) {

            Target detectedTarget = target;
            detectedTarget.detected = true;

            detectedTargets.push_back(detectedTarget);
        }
    }

    return detectedTargets;
}