#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>

class Parser {
public:
    // Return the percentage of physical memory currently in use (0.0 to 100.0).
    static float getMemoryUtilization();

    // Return the aggregate CPU counters reported by the Linux kernel.
    static std::vector<long> getCpuValues();
};

#endif