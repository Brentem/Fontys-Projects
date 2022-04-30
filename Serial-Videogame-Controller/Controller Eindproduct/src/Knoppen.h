//Knoppen.h - Bibliotheek voor de 4 knoppen
#ifndef Knoppen_h
#define Knoppen_h

#include <Arduino.h>

struct Knoppen{
    Knoppen(int Left, int Right, int Bottom, int Top);
    void SendMessage();
    private:
        int _left, _right, _bottom, _top;    
};

#endif