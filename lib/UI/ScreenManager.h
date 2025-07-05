#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <IScreen.h>

class ScreenManager
{
public:
    void setScreen(IScreen* screen)
    {
        delete currentScreen;
        currentScreen = screen;
    }

    void draw(Display& display)
    {
        if(currentScreen)
        {
            currentScreen->draw(display);
        }
    }

    void update(unsigned long deltaTime)
    {
        if(currentScreen)
        {
            currentScreen->update(deltaTime);
        }
    }
    
    void handleInput();    
    
    ~ScreenManager()
    {
        delete currentScreen;
    }
private:
    IScreen *currentScreen = nullptr;
}

#endif