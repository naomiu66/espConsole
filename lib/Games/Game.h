#ifndef GAME_H
#define GAME_H

#include <Display.h>


class Game {
public:
    virtual void init(Display *display) = 0;
    virtual void update() = 0;
    virtual ~Game() = default;
    virtual bool isFinished() = 0;
};

#endif