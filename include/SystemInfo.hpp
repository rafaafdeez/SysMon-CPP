#ifndef SYSTEMINFO_HPP
#define SYSTEMINFO_HPP

#include <iostream>
#include <vector>

class SystemInfo {
private:
    std::vector<long> previousCpuValues; // CPU counters from the previous sample.
    float cpu_usage;
    float mem_usage;

public:
    SystemInfo();
    void refresh();
    
    // Accessors for the latest resource utilization values.
    float getCpuUsage() const;
    float getMemUsage() const;
};

#endif