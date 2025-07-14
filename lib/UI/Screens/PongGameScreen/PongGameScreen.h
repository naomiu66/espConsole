#ifndef PONG_GAME_SCREEN_H
#define PONG_GAME_SCREEN_H

#include <InputManager.h>
#include <SoundManager.h>
#include <Display.h>
#include <ScreenManager.h>
#include <Screens/Screen.h>
#include <PongGame/PongGame.h>
#include <Game.h>

class PongGameScreen : public Screen {
public:
    PongGameScreen(InputManager* _inputManager, SoundManager* _soundManager, Display *_display, ScreenManager *_screenManager) :
        inputManager(_inputManager),
        soundManager(_soundManager),
        display(_display),
        screenManager(_screenManager)
    {
        game = new PongGame();
        game->init(display);
    }

    void update() override
    {
        game->update();
        if(game->isFinished())
        {
            // Handle game over logic here
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