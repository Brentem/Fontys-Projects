#include "Message_Handler.h"

#include <My_UART.h>
#include <fifo.h>

Fifo fifo = {.count = 0, .head = 0, .tail = 0};

void PrintNewLine()
{
    Message_Write(0x0D); //CR
    Message_Write(0x0A); //LF
}

void Message_Write(uint8_t byte)
{
    if(UART_DataBitsConfig())
    {
        // Empty bit 5, 6, 7
        uint8_t value = byte << 3;
        value >>= 3;
        UART_Write(value);

        // Send bit 5, 6, 7
        value = byte >> 5;
        UART_Write(value);
    }
    else
    {
        UART_Write(byte);
    }
}

void Message_Print(const char* string)
{
    if(string == NULL)
    {
        return;
    }

    for(uint16_t i = 0; string[i] != '\0'; i++)
    {
        Message_Write(string[i]);
    }
}

void Message_PrintLine(const char* string)
{
    if(string == NULL)
    {
        return;
    }

    Message_Print(string);
    PrintNewLine();
}

char ReadCharacter()
{
    char wholeCharacter = 0;

    if(UART_DataBitsConfig())
    {   
        uint8_t firstByte = 0;
        uint8_t secondByte = 0;

        fiforead(&firstByte, &fifo);
        fiforead(&secondByte, &fifo);

        wholeCharacter = (secondByte << GetDataBitsCount()) | firstByte;
    }
    else
    {
        fiforead((uint8_t*)&wholeCharacter, &fifo);
    }

    return wholeCharacter;
}

void UpdateFifoBuffer()
{
    bool reading = UART_CheckReadState();
    uint8_t readByte = UART_Read();

    if(reading)
    {
        fifowrite(readByte, &fifo);
    }
}

bool ReadAvailable()
{
    bool returnValue = false;

    if(UART_DataBitsConfig() && (fifo.count >= 2))
    {
        returnValue = true;
    }
    else if((!UART_DataBitsConfig()) && (fifo.count >= 1))
    {
        returnValue = true;
    }

    return returnValue;
}