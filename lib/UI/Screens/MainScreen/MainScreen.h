#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <InputManager.h>
#include <SoundManager.h>
#include <Display.h>
#include <ScreenManager.h>
#include <Screens/GameScreen/GameScreen.h>

class MainScreen : public Screen {
public:
    MainScreen(InputManager* _inputManager, SoundManager* _soundManager, Display *_display, ScreenManager *_screenManager) :
        inputManager(_inputManager),
        soundManager(_soundManager), 
        display(_display), 
        screenManager(_screenManager) {}

    void update() override;
    void render(Display &display) override;

private:
    InputManager *inputManager;
    SoundManager *soundManager;
    Display *display;
    ScreenManager *screenManager;
    int selected = 0;
    static const int gameCount = 2;
};

#endif