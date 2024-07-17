#ifndef SECURITY_H
#define SECURITY_H

#include <string>

bool authenticateUser(const std::string& username, const std::string& password);
bool changePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword);


void initializeSecurity() {
}
#endif // SECURITY_H

