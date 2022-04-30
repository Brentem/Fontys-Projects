#include "LedStrip.h"

//Ervoor zorgen dat includes hieronder niet meer nodig is.                                                                                                                                                               
#include <stm32f303xe.h>

extern "C"
{
#include <USART.h>
#include <stdlib.h>
#include <string.h>
}

LedStrip::LedStrip(PWM_Timer* timer)
{
    grb_color color = {0, 0, 0};

    for(auto& item: buffer)
    {
        item = color;
    }

    this->timer = timer;
}

void LedStrip::SetBuffer(uint16_t index, grb_color color)
{
    // Deze if statement moet nog aangepast worden!
    if(index >= 30)
    {
        return;
    }

    buffer[index] = color;
}

void LedStrip::SetBuffer(uint16_t index, uint8_t red,
                         uint8_t green, uint8_t blue)
{
    // Deze if statement moet nog aangepast worden!
    if(index >= 30)
    {
        return;
    }

    grb_color color {green, red, blue};

    buffer[index] = color;
}

void LedStrip::StartUpdate()
{
    if(!updateStarted)
    {
        bytePtr = (uint8_t*)&buffer[bufferCounter];

        checkByte(*bytePtr);

        updateStarted = true;
    }
}

void LedStrip::Update()
{
    if(bitCounter == 8)
    {
        bitCounter = 0;
        byteCounter++;
        bytePtr++;
    }

    if(byteCounter == 3)
    {
        byteCounter = 0;
        bufferCounter++;

        if(bufferCounter != 30)
        {
            bytePtr = (uint8_t*)&buffer[bufferCounter];
        }
    }

    if(bufferCounter != 30)
    {
        checkByte(*bytePtr);

        // char str[20] = "Hallo\n";
        // itoa(bufferCounter, str, 10);
        // strcat(str, "\n");

        // USART_Send((uint8_t*)str, strlen(str));
    }
    else
    {
        bitCounter = 0;
        byteCounter = 0;
        bufferCounter = 0;
        bytePtr = nullptr;
        updateStarted = false;
        timer->SetLineLow();

        NVIC_DisableIRQ(TIM2_IRQn); // Misschien hiervoor een functie aanmaken in timer
    }
}

void LedStrip::checkByte(uint8_t input)
{
    uint8_t value = input & 1 << (7 - bitCounter);
        
    if(value)
    {
        timer->SetHighSymbol();
    }
    else
    {
        timer->SetLowSymbol();
    }

    NVIC_EnableIRQ(TIM2_IRQn); // Misschien hiervoor een functie aanmaken in timer

    bitCounter++;
}