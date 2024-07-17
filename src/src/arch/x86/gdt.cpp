#include "gdt.h"
#include <stdint.h>

struct GDTEntry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct GDTPtr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

GDTEntry gdt[3];
GDTPtr gdt_ptr;

extern "C" void load_gdt(GDTPtr*);

void init_gdt() {
    gdt_ptr.limit = (sizeof(GDTEntry) * 3) - 1;
    gdt_ptr.base = (uint32_t)&gdt;

    gdt[0] = { 0, 0, 0, 0, 0, 0 }; // Null segment
    gdt[1] = { 
        .limit_low = 0xFFFF,
        .base_low = 0,
        .base_middle = 0,
        .access = 0x9A,
        .granularity = 0xCF,
        .base_high = 0
    }; // Code segment
    gdt[2] = { 
        .limit_low = 0xFFFF,
        .base_low = 0,
        .base_middle = 0,
        .access = 0x92,
        .granularity = 0xCF,
        .base_high = 0
    }; // Data segment

    load_gdt(&gdt_ptr);
}
