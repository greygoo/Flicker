#include <Arduino.h>
#include <Flicker.h>

int ledPin = 3;
int duration = 1000;

Flicker tenSecondFlicker(ledPin, 10, 40, duration);

void setup()
{
  tenSecondFlicker.Enable();
}

void loop()
{
  tenSecondFlicker.Update();
}
