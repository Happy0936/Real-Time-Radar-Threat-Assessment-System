#ifndef TARGET_DETECTOR_H
#define TARGET_DETECTOR_H

#include <vector>
#include "../../include/common/Target.h"

class TargetDetector {
public:
    std::vector<Target> detectTargets(
        const std::vector<Target>& targets,
        double maximumRange
    );
};

#endif