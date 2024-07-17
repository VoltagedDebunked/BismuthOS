#include "linuxdistroimport.h"
#include <iostream>
#include <cstdlib> // For system()

void linuxdistroimport() {
    // Import a Linux distribution as Docker container
    system("docker pull <linux_distro_image>");
    std::cout << "Linux distro imported as Docker successfully!" << std::endl;
}
