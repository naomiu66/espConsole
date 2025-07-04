#include "Display.h"

void Display::init()
{
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
}

void Display::clear()
{
    tft.fillScreen(TFT_BLACK);
}

TFT_eSPI& Display::getTFT()
{
    return this->tft;
}

void Display::drawText(int x, int y, const char* text, uint8_t size, uint16_t color)
{
    tft.setCursor(x, y);
    tft.setTextSize(size);
    tft.setTextColor(color);
    tft.print(text);
}

void Display::drawPixel(int x, int y, uint16_t color)
{
    tft.drawPixel(x, y, color);
}

void Display::update()
{
    // TODO update
}

