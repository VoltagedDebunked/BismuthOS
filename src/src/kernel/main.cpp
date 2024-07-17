#include "ui.h"
extern "C" void kernel_entry() {
    initializeUI();
    drawUI();
    while (1) {
        asm volatile ("hlt");
    }
}
