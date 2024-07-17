#include "devmode.h"
#include <iostream>
#include <fstream> // For file operations

void devmode() {
    // Enable developer mode
    std::ofstream devFile("developer_mode.txt");
    if (devFile.is_open()) {
        devFile << "Developer mode enabled!" << std::endl;
        devFile.close();
    } else {
        std::cerr << "Error: Unable to enable developer mode." << std::endl;
    }
}
