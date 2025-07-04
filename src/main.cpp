#include <Arduino.h>
#include <Display.h>
#include <TFT_eSPI.h>

Display display;

void setup() {
  Serial.begin(115200);
  display.init();

  Serial.println("Setup is complete.");
  display.drawText(100, 100, "HELLO WORLD!");
  display.drawPixel(200, 200, TFT_RED);
}

void loop() {
  // put your main code here, to run repeatedly:
}