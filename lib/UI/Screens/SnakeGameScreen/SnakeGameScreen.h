#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <Screens/Screen.h>
#include <Game.h>
#include <SnakeGame/SnakeGame.h>
#include <ButtonEvent.h>
#include <Display.h>
#include <InputManager.h>
#include <SoundManager.h>
#include <ScreenManager.h>

class SnakeGameScreen : public Screen {
public:
    SnakeGameScreen(InputManager* _inputManager, SoundManager* _soundManager, Display *_display, ScreenManager *_screenManager) : 
    inputManager(_inputManager),
    soundManager(_soundManager),
    display(_display),
    screenManager(_screenManager)
    {
        game = new SnakeGame();
        display->clear();
        game->init(display);
    }

    void update() override;

    void render(Display* display) override;
     
private:
    SnakeGame *game;
    InputManager *inputManager;
    SoundManager *soundManager;
    Display *display;
    ScreenManager *screenManager;

    void redrawField(Display *display);
    void redrawFood(Display *display);
    void drawSnake(Display *display);
    void drawScore(Display *display);
};

#endif