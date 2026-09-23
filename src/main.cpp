#include "SystemInfo.hpp"
#include "Display.hpp"
#include "SystemMetrics.hpp"
#include <unistd.h>
#include <NetworkClient.h>

int main() {
    SystemInfo systemInfo;
    Display display;
    NetworkClient networkClient;

    while (true) {
        sleep(1);

        systemInfo.refresh();
        display.printDashboard(systemInfo);

        // Send the latest metrics to the network client.
        networkClient.sendPayload({systemInfo.getCpuUsage(), systemInfo.getMemUsage()});
    }
    return 0;
}