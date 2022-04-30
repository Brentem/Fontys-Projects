//Joystick.h - Bibliotheek voor de joystick.
#ifndef Joystick_h
#define Joystick_h

#include <Arduino.h>

struct Joystick
{
    Joystick(int X_Pin, int Y_Pin);
    void SendMessage();
    private:
        int xPin, yPin;
};
#endif