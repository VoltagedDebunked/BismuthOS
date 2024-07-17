#include "shell.h"
#include "filesystem.h"
#include "security.h"
#include "gpu.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <functional>

FileSystem fileSystem;

void clearCommand(const std::vector<std::string>& args) {
    // Code to delete directory or file at the specified path
    if (args.size() < 2) {
        std::cout << "Usage: clear [directory or file]\n";
        return;
    }
    std::string path = args[1];
    if (fileSystem.deleteFile(path)) {
        std::cout << "Deleted: " << path << std::endl;
    } else {
        std::cout << "Failed to delete: " << path << std::endl;
    }
}

void makeCommand(const std::vector<std::string>& args) {
    // Code to create a directory
    if (args.size() < 2) {
        std::cout << "Usage: make [directory]\n";
        return;
    }
    std::string dirName = args[1];
    if (fileSystem.createFile(dirName)) {
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cout << "Failed to create directory: " << dirName << std::endl;
    }
}

void showCommand(const std::vector<std::string>& args) {
    // Code to show all directories
    std::vector<std::string> files = fileSystem.listFiles("/");
    std::cout << "Directories:\n";
    for (const auto& file : files) {
        std::cout << file << "\n";
    }
}

void helpCommand(const std::vector<std::string>& args) {
    // Code to display help information
    std::cout << "BismuthOS Shell\n";
    std::cout << "Available commands:\n";
    std::cout << "  clear [directory or file] - Deletes a directory or file.\n";
    std::cout << "  make [directory] - Creates a new directory.\n";
    std::cout << "  show - Shows all directories.\n";
    std::cout << "  help - Displays this help message.\n";
    std::cout << "  prev [file] - Preview the contents of a text-based file.\n";
    std::cout << "  print [text] - Print some text to the console.\n";
    std::cout << "  exit - Exits the shell.\n";
    std::cout << "  rst - Restarts the OS.\n";
    std::cout << "  sd - Shuts down the OS.\n";
    std::cout << "  slp - Enters sleep mode.\n";
}

void prevCommand(const std::vector<std::string>& args) {
    // Code to preview contents of a text-based file
    if (args.size() < 2) {
        std::cout << "Usage: prev [file]\n";
        return;
    }
    std::string fileName = args[1];
    // Code to read and display the contents of the file
    std::string content = fileSystem.readFile(fileName);
    std::cout << "Preview of file '" << fileName << "':\n";
    std::cout << content << "\n";
}

void printCommand(const std::vector<std::string>& args) {
    // Code to print text to console
    for (size_t i = 1; i < args.size(); ++i) {
        std::cout << args[i] << " ";
    }
    std::cout << "\n";
}

void exitCommand(const std::vector<std::string>& args) {
    // Code to exit the shell
    std::cout << "Exiting shell\n";
    // Additional cleanup or shutdown procedures if necessary
    exit(0); // Terminate the program
}

void restartOSCommand(const std::vector<std::string>& args) {
    // Code to restart the OS
    std::cout << "Restarting OS\n";
    // Additional procedures for restarting the OS if necessary
}

void shutdownOSCommand(const std::vector<std::string>& args) {
    // Code to shutdown the OS
    std::cout << "Shutting down OS\n";
    // Additional procedures for shutting down the OS if necessary
}

void sleepModeCommand(const std::vector<std::string>& args) {
    // Code to enter sleep mode
    std::cout << "Entering sleep mode\n";
    // Additional procedures for entering sleep mode if necessary
}

void startShell() {
    fileSystem.initialize();
    std::string username;
    std::string password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (!authenticateUser(username, password)) {
        std::cout << "Authentication failed.\n";
        return;
    }

    std::cout << "Authentication successful.\n";

    std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> commands;
    commands["clear"] = clearCommand;
    commands["make"] = makeCommand;
    commands["show"] = showCommand;
    commands["help"] = helpCommand;
    commands["prev"] = prevCommand;
    commands["print"] = printCommand;
    commands["exit"] = exitCommand;
    commands["rst"] = restartOSCommand;
    commands["sd"] = shutdownOSCommand;
    commands["slp"] = sleepModeCommand;

    std::string input;
    while (true) {
        std::cout << "bismuth> ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::vector<std::string> args;
        std::string word;
        while (iss >> word) {
            args.push_back(word);
        }
        if (args.empty()) continue;

        const std::string& command = args[0];
        if (command == "exit") break;

        auto it = commands.find(command);
        if (it != commands.end()) {
            it->second(args);
        } else {
            std::cout << "Unknown command: " << command << "\n";
        }
    }
}

