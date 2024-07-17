#ifndef GPU_H
#define GPU_H

void initializeGPU();
void clearScreen(uint32_t color);
void drawPixel(int x, int y, uint32_t color);
void drawRectangle(int x, int y, int width, int height, uint32_t color);
void drawLine(int x0, int y0, int x1, int y1, uint32_t color);
void drawCircle(int x, int y, int radius, uint32_t color);
void drawText(int x, int y, const char* text, uint32_t color);

#endif // GPU_H
