/*
  Flicker.h - Library for a flickering LED.
*/

#ifndef Flicker_h
#define Flicker_h

#include "Arduino.h"

class Flicker
{
  public:
    Flicker(int pin, int min, int max, long on);
    void Enable();
    void Update();
  private:
    bool enabled;
    int ledPin;
    int minFlick;
    int maxFlick;
    long FlickTime;
    long OnTime;
    long prevMillis;
};

#endif
