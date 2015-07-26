#include "Arduino.h"
#include "Flicker.h"

Flicker::Flicker(int pin, int min, int max, long on)
{
      enabled = 0;

      ledPin = pin;

      minFlick = min;
      maxFlick = max;
      unsigned long currentMillis = millis();
      FlickTime = currentMillis + random(maxFlick - minFlick) + minFlick;

      OnTime = on;

      prevMillis = 0;
}


void Flicker::Enable()
{
  enabled = 1;
}
 
void Flicker::Update()
{
  unsigned long currentMillis = millis();

  if( enabled && (currentMillis - prevMillis >= OnTime))
  {
    enabled = 0;
    prevMillis = currentMillis;
    digitalWrite(ledPin, LOW);
  }
  else if ( enabled && (currentMillis - prevMillis <= FlickTime))
  {
    analogWrite(ledPin, random(120)+135);
    FlickTime = currentMillis + random(maxFlick - minFlick) + minFlick;
  }
}
