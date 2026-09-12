#include "SystemInfo.hpp"
#include <Parser.hpp>

SystemInfo::SystemInfo() : cpu_usage(0.0f), mem_usage(0.0f) {
    // Establish a baseline for the first CPU utilization calculation.
    previousCpuValues = Parser::getCpuValues();
}

void SystemInfo::refresh(){
    // Read the latest memory utilization.
    mem_usage = Parser::getMemoryUtilization();

    // Compare the current CPU counters with the previous sample.
    std::vector<long> currentCpuValues = Parser::getCpuValues();

    long previousIdle = previousCpuValues[3] + previousCpuValues[4];
    long currentIdle = currentCpuValues[3] + currentCpuValues[4];

    long previousTotal = 0, currentTotal = 0;
    for (size_t i = 0; i < 8; i++) {
        previousTotal += previousCpuValues[i];
        currentTotal += currentCpuValues[i];
    }
    
    long totalDifference = currentTotal - previousTotal;
    long idleDifference = currentIdle - previousIdle;
    
    cpu_usage = 100.0f * (totalDifference - idleDifference) / totalDifference;

    // Keep this sample as the baseline for the next refresh.
    previousCpuValues = currentCpuValues;
}

float SystemInfo::getCpuUsage() const { return cpu_usage; }
float SystemInfo::getMemUsage() const { return mem_usage; }