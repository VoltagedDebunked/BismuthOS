#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>

class MemoryManager {
public:
    MemoryManager();
    ~MemoryManager();

    // Function to initialize memory
    void initializeMemory();

    // Function to set up paging
    void setupPaging();

private:
    // Private member variables
    uint32_t* page_directory;
    uint32_t* first_page_table;

    // Private member functions
    void initializePageDirectory();
    void initializeFirstPageTable();
    void enablePaging();
    void cleanup();
};

#endif // MEMORY_H
