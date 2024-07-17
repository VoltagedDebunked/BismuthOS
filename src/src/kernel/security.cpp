#include "security.h"
#include <unordered_map>
#include <memory.h>

static std::unordered_map<std::string, std::string> users = {
    {"admin", "password"},
    {"user", "userpass"}
};

bool authenticateUser(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}

bool changePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword) {
    auto it = users.find(username);
    if (it != users.end() && it->second == oldPassword) {
        it->second = newPassword;
        return true;
    }
    return false;
}

#include "memory.h"
#include "security.h"

void initializeSecurity() {
    initializeMemory();
}
