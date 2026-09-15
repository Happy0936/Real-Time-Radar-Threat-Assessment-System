#ifndef DECISION_ENGINE_H
#define DECISION_ENGINE_H

#include <string>

class DecisionEngine {
public:
    std::string makeDecision(const std::string& threatLevel);
};

#endif