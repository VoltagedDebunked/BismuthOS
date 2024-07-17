#include "UI.h"
#include "graphics.h"
#include "window.h"

void initializeUI() {
    initializeGraphics();
}

void drawUI() {
    clearScreen(0x87CEEB); // Clear screen with light blue (sky blue) for the desktop background

    // Draw desktop icons
    drawIcon(50, 50, "My Computer");
    drawIcon(150, 50, "Recycle Bin");
    drawIcon(50, 150, "Text Editor");
    drawIcon(150, 150, "Calculator");

    // Draw example windows for pre-installed apps
    drawWindow(300, 200, 400, 300, 0xFFFFFF, "Text Editor");
    drawWindow(750, 200, 200, 150, 0xFFFFFF, "Calculator");
}
