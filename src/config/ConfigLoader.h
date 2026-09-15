#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <string>

#include "../../include/common/RadarConfig.h"

class ConfigLoader {
public:

    static RadarConfig loadConfig(
        const std::string& filename
    );
};

#endif