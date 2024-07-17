#include "window.h"
#include "graphics.h"

void drawWindow(int x, int y, int width, int height, uint32_t color, const char* title) {
    drawRectangle(x, y, width, height, color);
    drawRectangle(x, y, width, 20, 0x0000FF); // Blue title bar
    drawText(x + 5, y + 5, title, 0xFFFFFF); // White text for title
    drawRectangle(x + width - 20, y, 20, 20, 0xFF0000); // Red close button
    drawText(x + width - 15, y + 5, "X", 0xFFFFFF); // White "X" for close button
}

void drawIcon(int x, int y, const char* label) {
    drawRectangle(x, y, 32, 32, 0x808080); // Gray square for icon
    drawText(x, y + 40, label, 0x000000); // Black text for label
}
