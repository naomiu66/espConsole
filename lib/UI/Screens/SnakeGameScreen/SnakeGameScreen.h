#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <Screens/Screen.h>
#include <Game.h>
#include <SnakeGame/SnakeGame.h>
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
        game->init(display);
    }

    void update() override
    {
        game->update();
        if(game->isFinished())
        {
            
        }
    }

    void render(Display* display) override
    {
    }
     
private:
    Game *game;
    InputManager *inputManager;
    SoundManager *soundManager;
    Display *display;
    ScreenManager *screenManager;
};

#endif