#ifndef NETWORKCLIENT_HPP
#define NETWORKCLIENT_HPP

#include "SystemMetrics.hpp"
#include <string>

class NetworkClient {
public:
    // Empty constructor for now. Initialization can be added here if needed in the future.
    // TCP conection managed on demand in sendPayload() to avoid keeping the socket open unnecessarily.
    NetworkClient()=default;
    
    // El método recibe los datos y se encarga de todo el proceso de red
    void sendPayload(const SystemMetrics& metrics);
};

#endif