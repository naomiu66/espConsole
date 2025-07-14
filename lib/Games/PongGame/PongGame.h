#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <Game.h>

class PongGame : public Game {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render(Display &display) = 0;
    virtual ~Game() = default;
    virtual bool isFinished() = 0;
private:
}

#endif