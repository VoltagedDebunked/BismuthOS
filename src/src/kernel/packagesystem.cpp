#include "packagesystem.h"
#include <iostream>

// Include package headers
#include "../packages/linuxdistroimport/linuxdistroimport.h"
#include "../packages/devmode/devmode.h"

PackageSystem& PackageSystem::getInstance() {
    static PackageSystem instance;
    return instance;
}

void PackageSystem::importPackage(const std::string& packageName) {
    // Register packages here
    if (packageName == "linuxdistroimport") {
        packages[packageName] = linuxdistroimport;
    } else if (packageName == "devmode") {
        packages[packageName] = devmode;
    } else {
        std::cout << "Error: Package '" << packageName << "' not found." << std::endl;
    }
}

void PackageSystem::runPackage(const std::string& packageName) {
    if (packages.find(packageName) != packages.end()) {
        packages[packageName]();
    } else {
        std::cout << "Error: Package '" << packageName << "' not found." << std::endl;
    }
}
