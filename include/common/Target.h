#ifndef TARGET_H
#define TARGET_H

struct Target {

    int id;

    // Raw sensor measurement
    double distance;

    // Target velocity
    double velocity;

    // Kalman filtered distance
    double filteredDistance;

    bool detected;
};

#endif