#include <iostream>
#include <cassert>

#include "../src/decision/DecisionEngine.h"

int main() {

    DecisionEngine engine;

    assert(
        engine.makeDecision("HIGH") == "PRIORITY RESPONSE"
    );

    assert(
        engine.makeDecision("MEDIUM") == "CONTINUE TRACKING"
    );

    assert(
        engine.makeDecision("LOW") == "MONITOR"
    );

    std::cout << "Decision Engine Test Passed!"
              << std::endl;

    return 0;
}