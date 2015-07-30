/*
  Flicker.h - Library for a flickering LED.
*/

#ifndef Flicker_h
#define Flicker_h

#include "Arduino.h"

class Flicker
{
  public:
    Flicker(int pin, int minF, int maxF, int minB, int maxB, long on);
    void Enable();
    void Update();
  private:
    bool enabled;
    int ledPin;
    int minFlick;
    int maxFlick;
    int minBrightness;
    int maxBrightness;
    long FlickTime;
    long OnTime;
    long prevMillis;
};

#endif
