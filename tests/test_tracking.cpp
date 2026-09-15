#include <iostream>
#include <vector>
#include <cassert>

#include "../include/common/Target.h"
#include "../src/tracking/KalmanTracker.h"

int main() {

    KalmanTracker tracker;

    // First radar measurement
    std::vector<Target> cycle1 = {
        {101, 1000.0, 100.0, 0.0, true},
        {102, 2000.0, 50.0, 0.0, true}
    };

    std::vector<Target> result1 =
        tracker.update(cycle1);

    // First observation should initialize the tracks
    assert(result1.size() == 2);
    assert(result1[0].id == 101);
    assert(result1[1].id == 102);

    // Second radar measurement
    std::vector<Target> cycle2 = {
        {101, 990.0, 100.0, 0.0, true},
        {102, 1995.0, 50.0, 0.0, true}
    };

    std::vector<Target> result2 =
        tracker.update(cycle2);

    // Both targets should still be tracked
    assert(result2.size() == 2);

    // Filtered distance should be available
    assert(result2[0].filteredDistance > 0);
    assert(result2[1].filteredDistance > 0);

    std::cout << "Tracking Test Passed!" << std::endl;

    return 0;
}