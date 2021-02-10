#pragma once

#include <string>

struct Config {
    int fps = 60;
    std::string windowTitle = "village";
};

inline const Config& config()
{
    static Config config;
    return config;
}
