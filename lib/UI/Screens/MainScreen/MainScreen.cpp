#include <Screens/MainScreen/MainScreen.h>

const MainScreen::MenuItem MainScreen::menuItems[] = {
    { "Snake Game", [](InputManager* im, SoundManager* sm, Display* d, ScreenManager* smgr) {
        return new SnakeGameScreen(im, sm, d, smgr);
    }},
    { "Pong Game", [](InputManager* im, SoundManager* sm, Display* d, ScreenManager* smgr) {
        return new PongGameScreen(im, sm, d, smgr);
    }}
};

const int MainScreen::menuItemCount = sizeof(MainScreen::menuItems) / sizeof(MainScreen::menuItems[0]);

void MainScreen::update()
{
    if(inputManager->hasEvent())
    {
        ButtonEvent event = inputManager->getEvent();
        if(event.pressed && event.buttonId == ButtonEvent::RIGHT)
        {
            soundManager->playTone(450, 50);
            selected = (selected + 1) % menuItemCount;
            needsRedraw = true;
        }
        if(event.pressed && event.buttonId == ButtonEvent::LEFT)
        {
            soundManager->playTone(350, 50);
            selected = (selected - 1 + menuItemCount) % menuItemCount;
            needsRedraw = true;
        }
        if(event.pressed && event.buttonId == ButtonEvent::A)
        {
            soundManager->playTone(600, 50);
            Screen* newScreen = menuItems[selected].createScreen(inputManager, soundManager, display, screenManager);
            screenManager->setScreen(newScreen);
        }
    }
}

void MainScreen::render(Display *display)
{
    if(!needsRedraw) return;
    needsRedraw = false;
    display->clear();
    display->drawText(10, 10, "Main Menu", 2, TFT_WHITE);
    display->drawText(10, 30, "Select a game:", 2, TFT_WHITE);
    for(int i = 0; i < menuItemCount; i++)
    {
        int y = 50 + i * 20;
        if(i == selected)
        {
            display->drawText(10, y, "> ", 2, TFT_YELLOW);
        }
        else
        {
            display->drawText(10, y, "  ", 2, TFT_WHITE);
        }
        display->drawText(30, y, menuItems[i].name, 2, TFT_WHITE);
    }
}