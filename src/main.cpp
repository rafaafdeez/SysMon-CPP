#include "SystemInfo.hpp"
#include "Display.hpp"
#include <unistd.h>

int main() {
    SystemInfo systemInfo;
    Display display;

    while (true) {
        sleep(1); 
        systemInfo.refresh();
        display.printDashboard(systemInfo);
    }
    return 0;
}