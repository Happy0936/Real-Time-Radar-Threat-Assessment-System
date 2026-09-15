#include <iostream>
#include <vector>
#include <cassert>

#include "../include/common/Target.h"
#include "../src/detection/TargetDetector.h"

int main() {

    TargetDetector detector;

    // Test targets
    std::vector<Target> targets = {

        {101, 1000.0, 100.0, 0.0, false},  // Inside range
        {102, 2500.0, 50.0, 0.0, false},   // Inside range
        {103, 5000.0, 20.0, 0.0, false}    // Outside range
    };

    double radarRange = 3000.0;

    // Run detection
    std::vector<Target> detected =
        detector.detectTargets(targets, radarRange);

    // We expect only 2 targets
    assert(detected.size() == 2);

    // Check target IDs
    assert(detected[0].id == 101);
    assert(detected[1].id == 102);

    std::cout << "Detection Test Passed!" << std::endl;

    return 0;
}