#include <Arduino.h>
#include <Display.h>
#include <InputManager.h>
#include <ButtonEvent.h>
#include <ScreenManager.h>
#include <SoundManager.h>
#include <Screens/MainScreen/MainScreen.h>
#include <StateManager.h>


Display display;
InputManager inputManager;
StateManager stateManager;
ScreenManager screenManager(&display, &stateManager);
SoundManager soundManager;

void setup()
{
  Serial.begin(9600);
  inputManager.init();
  soundManager.init();
  screenManager.setScreen(new MainScreen(&inputManager, &soundManager, &display, &screenManager));
  display.init();
  delay(1000);
  Serial.println("Setup complete");
}


void loop()
{
  inputManager.update();
  soundManager.update();

  screenManager.update();
  screenManager.render();
}