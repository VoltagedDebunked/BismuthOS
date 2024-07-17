#include "graphics.h"
#include "graphics_config.h"
#include <cstdlib>

extern "C" uint32_t* framebuffer;

void initializeGraphics() {
    configureScreen();
    framebuffer = reinterpret_cast<uint32_t*>(0xA0000); // Example address for the framebuffer
}

void clearScreen(uint32_t color) {
    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            framebuffer[y * screenWidth + x] = color;
        }
    }
}

void drawPixel(int x, int y, uint32_t color) {
    if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight) {
        framebuffer[y * screenWidth + x] = color;
    }
}

void drawRectangle(int x, int y, int width, int height, uint32_t color) {
    for (int dy = 0; dy < height; ++dy) {
        for (int dx = 0; dx < width; ++dx) {
            drawPixel(x + dx, y + dy, color);
        }
    }
}

void drawText(int x, int y, const char* text, uint32_t color) {
    // Simplified placeholder for text drawing
    while (*text) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (true) { // Simplified condition for placeholder
                    drawPixel(x + j, y + i, color);
                }
            }
        }
        x += 8; // Move to the next character position
        ++text;
    }
}

void drawIcon(int x, int y, const char* label) {
    drawRectangle(x, y, 32, 32, 0x808080); // Gray square for icon
    drawText(x, y + 40, label, 0x000000); // Black text for label
}
