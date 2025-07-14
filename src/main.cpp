#include <Arduino.h>
#include <Display.h>
#include <InputManager.h>
#include <ButtonEvent.h>
#include <ScreenManager.h>
#include <SoundManager.h>
#include <Screens/MainScreen/MainScreen.h>

Display display;
InputManager inputManager;
ScreenManager screenManager(display);
SoundManager soundManager;

void setup()
{
  Serial.begin(9600);

  display.init();
  inputManager.init();

  Serial.println("Setup complete");

  screenManager.setScreen(new MainScreen(&inputManager, &soundManager, &display, &screenManager));
}

void loop()
{
  inputManager.update();
  soundManager.update();
  screenManager.update();

  // if(inputManager.hasEvent())
  // {
  //   ButtonEvent event = inputManager.getEvent();

  //   Serial.print("Input has event: ");
  //   Serial.println(static_cast<int>(event.buttonId));

  //   Serial.println(event.pressed ? "pressed" : "released");
  // }
}