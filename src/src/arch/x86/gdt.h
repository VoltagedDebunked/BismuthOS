#ifndef GDT_H
#define GDT_H

#include <cstdint>

// Segment Descriptor structure
struct GDTEntry {
    uint16_t limit_low;     // Lower 16 bits of segment limit
    uint16_t base_low;      // Lower 16 bits of segment base address
    uint8_t base_middle;    // Next 8 bits of segment base address
    uint8_t access;         // Access flags
    uint8_t granularity;    // Granularity flags
    uint8_t base_high;      // Upper 8 bits of segment base address
};

// Global Descriptor Table structure
struct GDTDescriptor {
    uint16_t size;          // Size of GDT
    uint32_t offset;        // Offset of GDT in memory
};

// Initialize the Global Descriptor Table (GDT)
void initializeGDT();

// Load the Global Descriptor Table (GDT)
void loadGDT(const GDTDescriptor& gdtDescriptor);

#endif
