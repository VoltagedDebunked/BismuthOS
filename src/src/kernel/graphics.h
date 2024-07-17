#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

void initializeGraphics();
void clearScreen(uint32_t color);
void drawPixel(int x, int y, uint32_t color);
void drawRectangle(int x, int y, int width, int height, uint32_t color);
void drawText(int x, int y, const char* text, uint32_t color);
void drawIcon(int x, int y, const char* label);

#endif // GRAPHICS_H
