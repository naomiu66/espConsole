#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <Screens/Screen.h>
#include <Display.h>
#include <StateManager.h>

class ScreenManager
{
public:
    ScreenManager(Display *_display, StateManager *_stateManager) : display(_display), stateManager(_stateManager) {}


    void setScreen(Screen *_screen)
    {
        delete screen;
        screen = _screen;
    }
    void update()
    {
        if(screen)
        {
            screen->update();
        }
    }

    void render()
    {
        if(screen && display)
        {
            screen->render(display);
        }
    }

private:
    Screen *screen = nullptr;
    Display *display;
    StateManager *stateManager;
};

#endif