#include "Parser.hpp"

#include <fstream>
#include <sstream>
#include <string>

float Parser::getMemoryUtilization() {
    std::ifstream file("/proc/meminfo");
    std::string line;
    std::string key;

    long totalMemoryKb = 0;
    long availableMemoryKb = 0;

    // Parse the kernel-provided memory counters line by line.
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            iss >> key; // Read the counter name at the start of the line.
            
            if (key == "MemTotal:") {
                iss >> totalMemoryKb;
            } else if (key == "MemAvailable:") {
                iss >> availableMemoryKb;
            }
        }
        file.close();
    }

    // Avoid division by zero if the counters could not be read.
    if (totalMemoryKb == 0) return 0.0f;

    long usedMemoryKb = totalMemoryKb - availableMemoryKb;
    return 100.0f * (static_cast<float>(usedMemoryKb) / static_cast<float>(totalMemoryKb));
}

std::vector<long> Parser::getCpuValues() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::vector<long> cpuValues;
    
    // The first line contains the aggregate counters for all CPUs.
    if (file.is_open() && std::getline(file, line)) {
        std::istringstream iss(line);
        std::string cpuLabel;
        
        iss >> cpuLabel; // Read and discard the leading "cpu" label.
        
        long value;
        // Store every numeric counter from the line.
        while (iss >> value) {
            cpuValues.push_back(value);
        }
        file.close();
    }
    return cpuValues;
}