#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <stdint.h>
#include <stdbool.h>

void Message_Write(uint8_t byte);
void Message_Print(const char* string);
void Message_PrintLine(const char* string);
char ReadCharacter();
void UpdateFifoBuffer();
bool ReadAvailable();

#endif