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
    void setFood(const Point& newFood) { food = newFood; }
    bool isRedrawFood() const { return redrawFood; }
    bool isRedrawField() const { return redrawField; }
    void resetRedrawFlags() {
        redrawFood = false;
        redrawField = false;
    }

    Point& getDirection() { return direction; }
    void setDirection(const Point& newDirection) { direction = newDirection; }
    Point& getFood() { return food; }
    int getLength() const { return length; }
    int getScore() const { return score; }
    int getSpeed() const { return speed; }
    int getCellSize() const { return cell_size; }
    int getFieldWidthPx() const { return field_width_px; }
    int getFieldHeightPx() const { return field_height_px; }
    int getFieldX() const { return field_x; }
    int getFieldY() const { return field_y; }
    Point& getSnakeSegment(int index) { return snake[index]; }


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
    int score = 0;
    unsigned long gameTick = 0;
    Point food;
    int speed;
    Point direction;
    bool gameOver = false;

    bool redrawFood = true;
    bool redrawField = true;

    void updateSnakePosition();
    void checkCollision();
    void generateFood();
};

#endif