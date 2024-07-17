#include "filesystem.h"
#include <algorithm>

void FileSystem::initialize() {
    files.clear();
    directories.clear();
}

bool FileSystem::createFile(const std::string& path) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
        return file.name == path;
    });
    if (it != files.end()) return false; // File already exists

    files.push_back({path, ""});
    return true;
}

bool FileSystem::writeFile(const std::string& path, const std::string& data) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
        return file.name == path;
    });
    if (it == files.end()) return false; // File does not exist

    it->data = data;
    return true;
}

std::string FileSystem::readFile(const std::string& path) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
        return file.name == path;
    });
    if (it == files.end()) return ""; // File does not exist

    return it->data;
}

bool FileSystem::deleteFile(const std::string& path) {
    auto it = std::remove_if(files.begin(), files.end(), [&](const File& file) {
        return file.name == path;
    });
    if (it == files.end()) return false; // File does not exist

    files.erase(it, files.end());
    return true;
}

std::vector<std::string> FileSystem::listFiles(const std::string& directory) {
    std::vector<std::string> fileList;
    for (const auto& file : files) {
        if (file.name.find(directory) == 0) {
            fileList.push_back(file.name);
        }
    }
    return fileList;
}

bool FileSystem::createDirectory(const std::string& directory) {
    auto it = std::find_if(directories.begin(), directories.end(), [&](const Directory& dir) {
        return dir.name == directory;
    });
    if (it != directories.end()) return false; // Directory already exists

    directories.push_back({directory});
    return true;
}

bool FileSystem::removeDirectory(const std::string& directory) {
    auto it = std::remove_if(directories.begin(), directories.end(), [&](const Directory& dir) {
        return dir.name == directory;
    });
    if (it == directories.end()) return false; // Directory does not exist

    directories.erase(it, directories.end());
    return true;
}

std::vector<std::string> FileSystem::listDirectories(const std::string& directory) {
    std::vector<std::string> dirList;
    for (const auto& dir : directories) {
        if (dir.name.find(directory) == 0) {
            dirList.push_back(dir.name);
        }
    }
    return dirList;
}
