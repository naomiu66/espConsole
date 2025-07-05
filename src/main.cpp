#include <Arduino.h>
#include <Display.h>
#include <InputManager.h>
#include <ButtonEvent.h>

Display display;
InputManager inputManager;

void setup()
{
  Serial.begin(9600);

  display.init();
  inputManager.init();

  Serial.println("Setup complete");

  display.drawText(200, 200, "Hello world!");
}

void loop()
{
  inputManager.update();

  if(inputManager.hasEvent())
  {
    ButtonEvent event = inputManager.getEvent();

    Serial.println("Input has event: ");
    Serial.println(static_cast<int>(event.buttonId));
  }
}