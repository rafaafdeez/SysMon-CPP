cmake_minimum_required(VERSION 3.10)
project(SystemMonitor VERSION 1.0)

# Use the C++17 language standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Build the monitor executable from all application sources.
add_executable(SysMon-CPP 
    src/main.cpp 
    src/SystemInfo.cpp 
    src/Parser.cpp 
    src/Display.cpp
    src/NetworkClient.cpp
)

# --- Installation rules ---

# Install the executable in the system binary directory.
install(TARGETS SysMon-CPP  DESTINATION bin)

# Install the desktop entry for graphical application menus.
install(FILES SysMon-CPP.desktop DESTINATION share/applications)