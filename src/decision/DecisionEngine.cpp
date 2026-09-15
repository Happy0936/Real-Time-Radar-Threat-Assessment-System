#include "DecisionEngine.h"

std::string DecisionEngine::makeDecision(
    const std::string& threatLevel
) {

    if (threatLevel == "HIGH") {
        return "PRIORITY RESPONSE";
    }

    if (threatLevel == "MEDIUM") {
        return "CONTINUE TRACKING";
    }

    return "MONITOR";
}