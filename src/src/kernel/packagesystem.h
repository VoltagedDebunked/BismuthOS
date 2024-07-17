#ifndef PACKAGESYSTEM_H
#define PACKAGESYSTEM_H

#include <string>
#include <unordered_map>

class PackageSystem {
public:
    static PackageSystem& getInstance() {
        static PackageSystem instance;
        return instance;
    }

    void importPackage(const std::string& packageName);
    void runPackage(const std::string& packageName);

private:
    PackageSystem() {}
    std::unordered_map<std::string, void (*)()> packages;
};

#endif // PACKAGESYSTEM_H
