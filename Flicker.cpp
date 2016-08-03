#include "Arduino.h"
#include "Flicker.h"
#include <SoftwareSerial.h>

Flicker::Flicker(int pin, int minF, int maxF, int minB, int maxB, long on)
{
      enabled = 0;

      ledPin = pin;

      minFlick = minF;
      maxFlick = maxF;
      minBrightness = minB;
      maxBrightness = maxB;
      currentMillis = millis();
      Brightness = 250;

      OnTime = on;

      prevMillis = 0;
}


void Flicker::Enable()
{
  enabled = 1;
  pinMode(ledPin, OUTPUT);
  prevMillis = millis();
  FlickTime = random(maxFlick - minFlick) + minFlick;
}
 
void Flicker::Update()
{
  currentMillis = millis();
  passedMillis = currentMillis - prevMillis;
  Serial.print(passedMillis);
  Serial.print("\n");

  if(enabled) 
  { 
    analogWrite(ledPin, Brightness);
    if (passedMillis >= OnTime)
    // Flickering timeout met, switch off
    {
      Serial.print("\nOff\n");
      enabled = 0;
      prevMillis = 0;
      digitalWrite(ledPin, LOW);
    }
    if (passedMillis >= FlickTime)
    // Flick timeout met, change Flicktime and Brightness
    {
      Serial.print("\nFlick\n");
      Serial.print(FlickTime);
      Brightness = random(maxBrightness - minBrightness) + minBrightness;
      FlickTime = passedMillis + random(maxFlick - minFlick) + minFlick;
    }
  }
}
