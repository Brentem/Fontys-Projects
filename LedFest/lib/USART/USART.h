#ifndef USART_H
#define USART_H

#include <stm32f3xx.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void USART_Init();
bool USART_TXEFlagSet();
bool USART_TCFlagSet();
void USART_Send(uint8_t* buffer, uint32_t size);

#endif