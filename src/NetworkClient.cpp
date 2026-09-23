#include "NetworkClient.h"
#include <iostream>
#include <chrono>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void NetworkClient::sendPayload(const SystemMetrics& metrics) {
    // Generate a timestamp for the payload
    auto now = std::chrono::system_clock::now();
    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();

    // Format the payload as a JSON string
    std::string json_payload = "{\n"
                               "  \"sequence_num\": 1,\n"
                               "  \"timestamp\": " + std::to_string(timestamp) + ",\n"
                               "  \"cpu_percent\": " + std::to_string(metrics.cpuValue) + ",\n"
                               "  \"ram_used_mb\": " + std::to_string(metrics.memValue) + "\n"
                               "}";

    // Create a TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "[NetworkClient] Error creating socket\n";
        return;
    }

    // Configure the server address
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Try to connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "[NetworkClient] Error connecting to server\n";
        close(sock);
        return;
    
    // Send the JSON payload if the connection is successful
    } else {
        send(sock, json_payload.c_str(), json_payload.length(), 0);
    }

    // Close the socket after sending the payload
    close(sock);
}