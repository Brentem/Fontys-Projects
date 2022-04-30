#ifndef MY_UART_H
#define MY_UART_H

#include <stdint.h>
#include <Arduino.h>

#define MICROSECONDS 1000000

typedef enum
{
    NONE,
    ODD,
    EVEN
}ParityType;

typedef struct
{
    uint8_t RxPin;
    uint8_t TxPin;
    uint8_t NrDataBits;
    uint8_t NrStopBits;
    uint32_t BaudRate;
    ParityType Parity;
}UART_Config;

void UART_Init(UART_Config init);
bool UART_CheckReadState();
uint8_t UART_Read();
void UART_Write(const uint8_t byte);
bool UART_DataBitsConfig();
bool UART_ParityError();
uint8_t GetDataBitsCount();

#endif