#include "Display.hpp"
#include <iomanip>

std::string Display::getProgressBar(float percentage, int width) {
    std::string bar = "[";
    // Determine how many cells should represent the current percentage.
    int filled = (percentage / 100.0f) * width;
    
    for (int i = 0; i < width; ++i) {
        if (i < filled) {
            bar += "|"; // Filled cell.
        } else {
            bar += " "; // Empty cell.
        }
    }
    bar += "]";
    return bar;
}

void Display::printDashboard(const SystemInfo& info) {
    // Refresh the terminal before drawing the next snapshot.
    std::cout << "\033[2J\033[1;1H"; 
    
    std::cout << "=================================================================\n";
    std::cout << "                       SYSTEM MONITOR                           \n";
    std::cout << "=================================================================\n\n";
    
    // Display CPU utilization with one decimal place and a progress bar.
    std::cout << " CPU: " << std::fixed << std::setprecision(1) << info.getCpuUsage() << "%\t" 
              << getProgressBar(info.getCpuUsage()) << "\n\n";
    
    // Display memory utilization with one decimal place and a progress bar.
    std::cout << " RAM: " << std::fixed << std::setprecision(1) << info.getMemUsage() << "%\t" 
              << getProgressBar(info.getMemUsage()) << "\n\n";
              
    std::cout << "=================================================================\n";
}