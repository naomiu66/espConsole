#include <Screens/SnakeGameScreen/SnakeGameScreen.h>
#include "SnakeGameScreen.h"
#include <Arduino.h>

void SnakeGameScreen::update()
{
    if(inputManager->hasEvent())
    {
        ButtonEvent event = inputManager->getEvent();
        if(event.pressed)
        {
            switch(event.buttonId)
            {
                case ButtonEvent::UP:
                    if(game->getDirection().y == 0){ game->setDirection({0, -1}); }
                    soundManager->playTone(450, 50);
                    break;
                case ButtonEvent::DOWN:
                    if(game->getDirection().y == 0){ game->setDirection({0, 1}); }
                    soundManager->playTone(450, 50);
                    break;
                case ButtonEvent::LEFT:
                    if(game->getDirection().x == 0){ game->setDirection({-1, 0}); }
                    soundManager->playTone(450, 50);
                    break;
                case ButtonEvent::RIGHT:
                    if(game->getDirection().x == 0){ game->setDirection({1, 0}); }
                    soundManager->playTone(450, 50);
                    break;
                case ButtonEvent::A:
                    if(game->isFinished())
                    {
                        game->resetRedrawFlags();
                        game->init(display);
                        soundManager->playTone(600, 50);
                    }
                    break;
                case ButtonEvent::B:
                    // Handle B button press
                    break;
                default:
                    break;
            }
        }
    }
    game->update();
}
void SnakeGameScreen::render(Display *display)
{
    if(game->isFinished())
    {
        display->clear();
        display->drawText(display->getWidth() / 2 - 100, display->getHeight() / 2 - 50, "Game Over", 4, TFT_RED);
        display->drawText(display->getWidth() / 2 - 100, display->getHeight() / 2 + 50, "Press A to restart", 2, TFT_WHITE);
        return;
    }

    if(game->isRedrawField())
    {
        redrawField(display);
    }
    if(game->isRedrawFood())
    {
        redrawFood(display);
        drawScore(display);
    }
    drawSnake(display);
}

void SnakeGameScreen::redrawField(Display *display) 
{
    display->drawRect(game->getFieldX(), game->getFieldY(), game->getFieldWidthPx(), game->getFieldHeightPx(), TFT_WHITE);
}

void SnakeGameScreen::redrawFood(Display *display)
{
    Point food = game->getFood();
    display->drawFilledRect(game->getFieldX() + food.x * game->getCellSize(),
                            game->getFieldY() + food.y * game->getCellSize(),
                            game->getCellSize(), game->getCellSize(), TFT_RED);
}

void SnakeGameScreen::drawSnake(Display *display)
{
    for(int i = 0; i < game->getLength(); i++)
    {
        Point segment = game->getSnakeSegment(i);
        display->drawFilledRect(game->getFieldX() + segment.x * game->getCellSize(),
                                game->getFieldY() + segment.y * game->getCellSize(),
                                game->getCellSize(), game->getCellSize(), TFT_GREEN);
    }
}

void SnakeGameScreen::drawScore(Display *display) 
{
    char scoreText[20];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", game->getScore());
    display->drawText(10, 10, scoreText, 2, TFT_WHITE);
}