#ifndef SCREEN_H
#define SCREEN_H

#include <Display.h>

class Screen{
public:
    virtual void update() = 0;
    virtual void render(Display *display) {};
    virtual ~Screen() {};
protected:
    bool needsRedraw = true;
};

#endif