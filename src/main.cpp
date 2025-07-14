#include <Arduino.h>
#include <Display.h>
#include <InputManager.h>
#include <ButtonEvent.h>
#include <ScreenManager.h>
#include <SoundManager.h>
#include <Screens/MainScreen/MainScreen.h>
#include <GameEngine.h>


Display display;
InputManager inputManager;
ScreenManager screenManager(&display);
SoundManager soundManager;
GameEngine gameEngine(&screenManager, &inputManager, &soundManager, &display);


void setup()
{
  Serial.begin(9600);
  gameEngine.init();
  Serial.println("Setup complete");
}


void loop()
{
  gameEngine.update();
  gameEngine.render();
}