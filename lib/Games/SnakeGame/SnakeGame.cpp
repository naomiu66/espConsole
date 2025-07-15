#include "SnakeGame.h"
#include <Arduino.h>

void SnakeGame::init(Display *display)
{
    cell_size = min(display->getWidth() / GRID_WIDTH, display->getHeight() / GRID_HEIGHT);
    field_width_px = GRID_WIDTH * cell_size;
    field_height_px = GRID_HEIGHT * cell_size;
    field_x = (display->getWidth() - field_width_px) / 2;
    field_y = (display->getHeight() - field_height_px) / 2;

    length = INITIAL_LENGTH;
    speed = INITIAL_SPEED;
    direction = {0, -1};
    gameOver = false;
    for (int i = 0; i < length; ++i) {
        snake[i] = {GRID_WIDTH / 2, GRID_HEIGHT / 2 + i}; // Start in the middle of the field
    }

    redrawField = true;
    redrawFood = true;
    generateFood();
}

void SnakeGame::update()
{
    if (gameOver) return;
    resetRedrawFlags();
    if (millis() - gameTick >= speed) {
        gameTick = millis();
        checkCollision();
        updateSnakePosition();
    }
}

bool SnakeGame::isFinished()
{
    return gameOver;
}

void SnakeGame::updateSnakePosition()
{
    // Update snake position based on direction
    for (int i = length - 1; i > 0; --i) {
        snake[i] = snake[i - 1];
    }
    snake[0].x += direction.x;
    snake[0].y += direction.y;
}

void SnakeGame::checkCollision()
{
    // Check for collisions with walls
    if (snake[0].x < 0 || snake[0].x >= GRID_WIDTH || snake[0].y < 0 || snake[0].y >= GRID_HEIGHT) {
        gameOver = true;
        return;
    }

    // Check for collisions with itself
    for (int i = 1; i < length; ++i) {
        if (snake[i].x == snake[0].x && snake[i].y == snake[0].y) {
            gameOver = true;
            return;
        }
    }

    // check for food collision
    if(snake[0].x == food.x && snake[0].y == food.y)
    {
        if(length < MAX_LENGTH)
        {
            length++;
            score++;
            gameOver = true;
        }
        redrawFood = true;

        generateFood();
    }
}

void SnakeGame::generateFood()
{
    do {
        food.x = random(0, GRID_WIDTH);
        food.y = random(0, GRID_HEIGHT);
    } while (food.x == snake[0].x && food.y == snake[0].y); // Ensure food is not placed on the snake
}
