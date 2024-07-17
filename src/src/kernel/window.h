#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

void drawWindow(int x, int y, int width, int height, uint32_t color, const char* title);
void drawIcon(int x, int y, const char* label);

#endif // WINDOW_H
