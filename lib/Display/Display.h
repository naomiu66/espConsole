#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>

class Display
{
    public:
        void init();
        void clear();
        void drawText(int x, int y, const char* text, uint8_t size = 2, uint16_t color = TFT_WHITE);
        void drawPixel(int x, int y, uint16_t color);
        void drawRect(int x, int y, int width, int height, uint16_t color);
        void update();
        TFT_eSPI& getTFT();
    private:
        TFT_eSPI tft;
};

#endif