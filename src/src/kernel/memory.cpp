#include "memory.h"

#include <cstdlib>

#define PAGE_SIZE 4096
#define TOTAL_MEMORY 0x2000000000 // 512GB

MemoryManager::MemoryManager() : page_directory(nullptr), first_page_table(nullptr) {
    initializeMemory();
}

MemoryManager::~MemoryManager() {
    cleanup();
}

void MemoryManager::initializeMemory() {
    page_directory = reinterpret_cast<uint32_t*>(malloc(1024 * sizeof(uint32_t)));
    first_page_table = reinterpret_cast<uint32_t*>(malloc(1024 * sizeof(uint32_t)));

    if (!page_directory || !first_page_table) {
        // Handle memory allocation failure
        return;
    }

    initializePageDirectory();
    initializeFirstPageTable();

    enablePaging();
}

void MemoryManager::initializePageDirectory() {
    for (uint32_t i = 0; i < 1024; i++) {
        page_directory[i] = 0x00000002;
    }
}

void MemoryManager::initializeFirstPageTable() {
    for (uint32_t i = 0; i < 1024; i++) {
        first_page_table[i] = (i * PAGE_SIZE) | 3;
    }

    page_directory[0] = reinterpret_cast<uint32_t>(first_page_table) | 3;
}

void MemoryManager::enablePaging() {
    asm volatile("mov %0, %%cr3" : : "r" (page_directory));
    asm volatile("mov %cr0, %eax");
    asm volatile("or $0x80000000, %eax");
    asm volatile("mov %eax, %cr0");
}

void MemoryManager::cleanup() {
    if (page_directory) {
        free(page_directory);
        page_directory = nullptr;
    }

    if (first_page_table) {
        free(first_page_table);
        first_page_table = nullptr;
    }
}
