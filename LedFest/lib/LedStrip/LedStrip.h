#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <PWM_Timer.h>

#include <stdint.h>


struct grb_color
{
    uint8_t green;
    uint8_t red;
    uint8_t blue;
};

class LedStrip
{
private:
    grb_color buffer[30];
    PWM_Timer* timer;

    volatile bool updateStarted = false;
    volatile uint8_t* bytePtr = nullptr;
    volatile uint8_t byteCounter = 0;
    volatile uint8_t bufferCounter = 0;
    volatile uint8_t bitCounter = 0;

    void checkByte(uint8_t);

public:
    LedStrip(PWM_Timer* timer);
    void SetBuffer(uint16_t index, grb_color color);
    void SetBuffer(uint16_t index, uint8_t red,
                     uint8_t green, uint8_t blue);
    void StartUpdate();
    void Update();
};

#endif