#include "SnakeGame.h"

void SnakeGame::init(Display *display)
{
    cell_size = min(display->getWidth() / GRID_WIDTH, display->getHeight() / GRID_HEIGHT);
    field_width_px = GRID_WIDTH * cell_size;
    field_height_px = GRID_HEIGHT * cell_size;
    field_x = (display->getWidth() - field_width_px) / 2;
    field_y = (display->getHeight() - field_height_px) / 2;

    length = INITIAL_LENGTH;
    speed = INITIAL_SPEED;
    direction = {0, 1};
    gameOver = false;



}

void SnakeGame::update()
{

}

bool SnakeGame::isFinished()
{
    return false;
}