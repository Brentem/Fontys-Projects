#include <Arduino.h>
#include <stdio.h>

#include <Terminal_Server.h>
#include <My_UART.h>
#include <Message_Handler.h>

State state = IDLE;
uint8_t DigitalPins[] = {8, 9, 10, 11, 12, 13};

void printMenu();
void printDigitalInputs();
void printAnalogInputs();
void clearScreen();
bool changeState(char input);

void Server_Init()
{
    for(uint8_t i = 0; i < 6; i++)
    {
        pinMode(DigitalPins[i], INPUT);
    }

    UART_Config init = 
    {   
        .RxPin = 7,
        .TxPin = 8,
        .NrDataBits = 5,
        .NrStopBits = 1,
        .BaudRate = 9600,
        .Parity = NONE
    };

    UART_Init(init);
}

void ServerLoop()
{
    UpdateFifoBuffer();
    //UART_CheckReadState();
    char input = 0;

    if(ReadAvailable())
    {
        input = ReadCharacter();
    }

    bool stateChanged = changeState(input);

    if(stateChanged)
    {
        switch(state)
        {
            case MENU:
            printMenu();
                break;

            case DIGITAL:
            printDigitalInputs();
                break;

            case ANALOG:
            printAnalogInputs();
                break;

            case CLEAR:
            clearScreen();
                break;

            default:
                break;
        }
    }
}

void printMenu()
{
    Message_PrintLine("View current Input Levels:");
    Message_PrintLine("- D: Digital Inputs DI08 - DI13");
    Message_PrintLine("- A: Analog Inputs A0 - A5");
    Message_PrintLine("- C: Clear Screen");
    Message_PrintLine("");
}

void printDigitalInputs()
{
    char digitalInputStrings[6][6] = {"DI08:", "DI09:", "DI10:", 
    "DI11:", "DI12:", "DI13:"};

    for(uint8_t i = 0; i < 6; i++)
    {
        char str[10];
        uint8_t result = digitalRead(DigitalPins[i]);
        sprintf(str, "%d", result);

        Message_Print(digitalInputStrings[i]);
        Message_Print(" ");
        Message_PrintLine(str);
    }

    Message_PrintLine("");
}

void printAnalogInputs()
{
    char analogInputStrings[6][4] = {"A0:", "A1:", "A2:",
    "A3:", "A4:", "A5:"};

    uint8_t analogPins[] = {A0, A1, A2, A3, A4, A5};

    for(uint8_t i = 0; i < 6; i++)
    {
        char str[10];
        uint16_t result = analogRead(analogPins[i]);
        sprintf(str, "%d", result);

        Message_Print(analogInputStrings[i]);
        Message_Print(" ");
        Message_PrintLine(str);
    }

    Message_PrintLine("");
}

void clearScreen()
{
    Message_Write(0x1B);
    Message_Print("[2J");
    Message_Write(0x1B);
    Message_Print("[H");
}

bool changeState(char input)
{
    bool stateChanged = false;

    if((input == 'S') || (input == 's'))
    {
        state = MENU;
        stateChanged = true;
    }

    if(state == MENU || state == DIGITAL || state == ANALOG)
    {
        if(input == 'D' || input == 'd')
        {
            state = DIGITAL;
            stateChanged = true;
        }
        else if(input == 'A' || input == 'a')
        {
            state = ANALOG;
            stateChanged = true;
        }
        else if(input == 'C' || input == 'c')
        {
            state = CLEAR;
            stateChanged = true;
        }
    }

    return stateChanged;
}