#ifndef SHELL_H
#define SHELL_H

#include <vector>
#include <string>

class Shell {
public:
    static void clear(const std::vector<std::string>& args);
    static void make(const std::vector<std::string>& args);
    static void show(const std::vector<std::string>& args);
    static void help(const std::vector<std::string>& args);
    static void prev(const std::vector<std::string>& args);
    static void print(const std::vector<std::string>& args);
    static void exit(const std::vector<std::string>& args);
    static void restartOS(const std::vector<std::string>& args);
    static void shutdownOS(const std::vector<std::string>& args);
    static void sleepMode(const std::vector<std::string>& args);
};

#endif // SHELL_H
