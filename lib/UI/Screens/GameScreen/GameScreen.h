#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <Screens/Screen.h>
#include <Game.h>
#include <InputManager.h>
#include <SoundManager.h>
#include <ScreenManager.h>

class GameScreen : public Screen {
public:
    GameScreen(Game *_game, InputManager* _inputManager, SoundManager* _soundManager, Display *_display, ScreenManager *_screenManager) : 
    inputManager(_inputManager),
    soundManager(_soundManager),
    display(_display),
    screenManager(_screenManager),
    game(_game) {
        game->init();
    }

    void update() override
    {
        game->update();
        if(game->isFinished())
        {
            
        }
    }

    void render(Display& display) override
    {
        game->render(display);
    }
     
private:
    Game *game;
    InputManager *inputManager;
    SoundManager *soundManager;
    Display *display;
    ScreenManager *screenManager;
};

#endif