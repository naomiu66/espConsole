#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <Game.h>
#include <ButtonEvent.h>
#include <Display.h>

struct Point {
    int x;
    int y;
};

class SnakeGame : public Game {
public:
    void init(Display *display) override;
    void update() override;
    SnakeGame() {}
    ~SnakeGame() = default;
    bool isFinished() override;

private:
    static const int GRID_WIDTH = 40;
    static const int GRID_HEIGHT = 40;
    static const int INITIAL_LENGTH = 5;
    static const int INITIAL_SPEED = 100; // milliseconds
    static const int MAX_LENGTH = 64;
    static const int MAX_SPEED = 50; // milliseconds

    int cell_size;
    int field_width_px;
    int field_height_px;
    int field_x;
    int field_y;

    Point snake[MAX_LENGTH];
    int length;
    Point food;
    int speed;
    Point direction; // 0: up, 1: right, 2: down, 3: left
    bool gameOver;
};

#endif