#ifndef ISCREEN_H
#define ISCREEN_H

#include <Display.h>
#include <Button.h>

class IScreen
{
public:
    virtual ~IScreen() = default;

    virtual draw(Display& display) = 0;

    virtual update(unsigned long deltaTime) = 0;

    virtual handleInput() = 0;
}

#endif