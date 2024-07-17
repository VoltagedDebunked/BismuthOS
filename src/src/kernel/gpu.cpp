#include "gpu.h"
#include <stdint.h>
#include <stdlib.h>

extern "C" uint32_t* framebuffer;
extern "C" int screenWidth;
extern "C" int screenHeight;

void initializeGPU() {
    framebuffer = reinterpret_cast<uint32_t*>(0xA0000);
    screenWidth = 1024; 
    screenHeight = 768; 
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

void drawLine(int x0, int y0, int x1, int y1, uint32_t color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        drawPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void drawCircle(int x0, int y0, int radius, uint32_t color) {
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 + y, y0 + x, color);
        drawPixel(x0 - y, y0 + x, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 - x, y0 - y, color);
        drawPixel(x0 - y, y0 - x, color);
        drawPixel(x0 + y, y0 - x, color);
        drawPixel(x0 + x, y0 - y, color);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

void drawText(int x, int y, const char* text, uint32_t color) {
    while (*text) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (true) { 
                    drawPixel(x + j, y + i, color);
                }
            }
        }
        x += 8; 
        ++text;
    }
}
