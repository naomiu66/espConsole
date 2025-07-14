#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <InputManager.h>
#include <SoundManager.h>
#include <Display.h>
#include <ScreenManager.h>
#include <Screens/SnakeGameScreen/SnakeGameScreen.h>
#include <Screens/PongGameScreen/PongGameScreen.h>
#include <Screens/Screen.h>
#include <string>
#include <SnakeGame/SnakeGame.h>
#include <PongGame/PongGame.h>
#include <functional>

class MainScreen : public Screen {
public:
    MainScreen(InputManager* _inputManager, SoundManager* _soundManager, Display *_display, ScreenManager *_screenManager) :
        inputManager(_inputManager),
        soundManager(_soundManager), 
        display(_display), 
        screenManager(_screenManager) {}

    void update() override;
    void render(Display *display) override;

private:
    InputManager *inputManager;
    SoundManager *soundManager;
    Display *display;
    ScreenManager *screenManager;
    int selected = 0;
    bool needsRedraw = true;

    struct MenuItem {
        const char* name;
        std::function<Screen*(InputManager*, SoundManager*, Display*, ScreenManager*)> createScreen;
    };

    static const MenuItem menuItems[];
    static const int menuItemCount;
};

#endif