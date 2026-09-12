# SysMon-CPP: Lightweight Linux System Monitor

A lightweight, Object-Oriented system resource monitor for Linux environments, written entirely in modern C++.

This project demonstrates low-level system interaction by parsing kernel data directly from the `/proc` virtual filesystem, built with a clean, modular architecture suitable for performance-critical environments.

![SysMon-CPP Screenshot](docs/screenshot.png)
_(Note: Create a `docs` folder in your repo, take a screenshot of your terminal showing the ASCII bars, name it screenshot.png and put it there, then delete this italic note)_

## Features

- **Real-Time Telemetry:** Calculates precise CPU load (delta between clock ticks) and RAM utilization.
- **Zero Dependencies:** Relies purely on the Linux standard library and `/proc` pseudo-files (`/proc/stat`, `/proc/meminfo`).
- **OOP Architecture:** Separation of concerns using a simplified Model-View-Controller (MVC) approach.
- **CLI UI:** Custom ASCII progress bars and terminal ANSI escape codes for a flicker-free dashboard experience.

## Tech Stack

- **Language:** C++17
- **Build System:** CMake
- **Target OS:** Linux (Arch / EndeavourOS tested)

## Architecture

The codebase is strictly separated into focused classes:

- `Parser`: The data extraction layer. Handles file I/O operations and safely parses raw system jiffies and memory blocks.
- `SystemInfo`: The state management layer. Stores historical data to calculate deltas and utilization percentages.
- `Display`: The presentation layer. Renders the data into visual terminal elements.

## Build and Installation

To compile the project from source, ensure you have `cmake` and a C++ compiler (`gcc`/`g++`) installed.

```bash
# 1. Clone the repository
git clone [https://github.com/YOUR-USERNAME/SysMon-CPP.git](https://github.com/YOUR-USERNAME/SysMon-CPP.git)
cd SysMon-CPP

# 2. Create the build directory
mkdir build && cd build

# 3. Configure and compile
cmake ..
make

# 4. (Optional) Install globally to use via terminal or application launcher
sudo make install
```
