#ifndef LINUXDISTROIMPORT_H
#define LINUXDISTROIMPORT_H

#include <cstdlib> // For system()

inline void linuxdistroimport() {
    // Import a Linux distribution as Docker container
    system("docker pull <linux_distro_image>");
    std::cout << "Linux distro imported as Docker successfully!" << std::endl;
}

#endif // LINUXDISTROIMPORT_H
