#include <Screens/MainScreen/MainScreen.h>
#include <SnakeGame/SnakeGame.h>
#include <functional>

struct MenuItem {
    const char* name;
    std::function<Game*()> createGame;
};

static const MenuItem menuItems[] = {
    { "Snake Game", []() { return new SnakeGame(); } }
    
};



static const int menuItemCount = sizeof(menuItems) / sizeof(MenuItem);


void MainScreen::update()
{
    if(inputManager->hasEvent())
    {
        ButtonEvent event = inputManager->getEvent();
        if(event.pressed && event.buttonId == ButtonEvent::RIGHT && selected < gameCount)
        {
            soundManager->playTone(450, 50);
            selected++;
        }
        if(event.pressed && event.buttonId == ButtonEvent::LEFT && selected > 0)
        {
            soundManager->playTone(350, 50);
            selected--;
        }

        if(event.pressed && event.buttonId == ButtonEvent::A)
        {
            soundManager->playTone(600, 50);
            screenManager->setScreen(new GameScreen(new SnakeGame(), inputManager, soundManager, display, screenManager));
        }
    }
}

void MainScreen::render(Display &display)
{
    display.drawText(200, 200, "Hello world!");
}