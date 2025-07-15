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
        void drawFilledRect(int x, int y, int width, int height, uint16_t color);
        void update();
        TFT_eSPI& getTFT();
        int getWidth() const { return SCREEN_WIDTH; }
        int getHeight() const { return SCREEN_HEIGHT; }
    private:
        TFT_eSPI tft;
        static const int SCREEN_WIDTH = 480;
        static const int SCREEN_HEIGHT = 320;
};

#endif