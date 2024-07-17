#ifndef DEVMODE_H
#define DEVMODE_H

#include <fstream> // For file operations

inline void devmode() {
    // Enable developer mode
    std::ofstream devFile("developer_mode.txt");
    if (devFile.is_open()) {
        devFile << "Developer mode enabled!" << std::endl;
        devFile.close();
    } else {
        std::cerr << "Error: Unable to enable developer mode." << std::endl;
    }
}

#endif // DEVMODE_H
