#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include "SystemInfo.hpp"

class Display {
    // Build a textual progress bar using the requested width.
    static std::string getProgressBar(float percentage, int width = 50);
public:
    void printDashboard(const SystemInfo& sys);
};

#endif