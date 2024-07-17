#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <vector>

class FileSystem {
public:
    void initialize();
    bool createFile(const std::string& path);
    bool writeFile(const std::string& path, const std::string& data);
    std::string readFile(const std::string& path);
    bool deleteFile(const std::string& path);
    std::vector<std::string> listFiles(const std::string& directory);

    // Directory functionalities
    bool createDirectory(const std::string& directory);
    bool removeDirectory(const std::string& directory);
    std::vector<std::string> listDirectories(const std::string& directory);

private:
    struct File {
        std::string name;
        std::string data;
    };

    struct Directory {
        std::string name;
    };

    std::vector<File> files;
    std::vector<Directory> directories;
};

#endif // FILESYSTEM_H
