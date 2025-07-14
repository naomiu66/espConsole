#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <Game.h>

class SnakeGame : public Game {
public:
    void init() override;
    void update() override;
    void render(Display &display) override;
    SnakeGame() {}
    ~SnakeGame() = default;
    bool isFinished() override;

private:
};

#endif