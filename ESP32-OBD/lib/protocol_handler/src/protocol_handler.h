#ifndef PROTOCOL_HANDLER_H
#define PROTOCOL_HANDLER_H

#include <stdint.h>

#define SHIFT_BYTES 8

#define PROTOCOL_THROTTLE_POSITION 0x82
#define PROTOCOL_VEHICLE_SPEED 0x83
#define PROTOCOL_ENGINE_SPEED 0x84
#define PROTOCOL_FUEL_TANK_LEVEL_INPUT 0x85
#define PROTOCOL_FUEL_SYSTEM_STATUS 0x86
#define PROTOCOL_ENGINE_FUEL_RATE 0x87
#define PROTOCOL_FUEL_PRESSURE 0x88
#define PROTOCOL_ENGINE_COOLANT_TEMP 0x89

#define MESSAGE_END 255

#define GET_NIBBLE 0X0F

// pre: high and low not null
//post: byte split into 2 nibbles
//      returns 0 on succes and -1 if an error occured
int8_t protocol_handler_get_nibbles(uint8_t input, uint8_t* high, uint8_t* low);

// pre: array not null and arraySize must not be smaller than 4
// post: (if necessary) bytes from value split and turned into array
//      returns 0 on success -1 if an error occurred
int8_t protocol_handler_format_two_bytes(uint16_t input, uint8_t* array, uint8_t arraySize);

//pre: array must not be null and arraySize must not be smaller than 2
// post byte split in high and low and put into the array
//      returns 0 on succes -1 if an error occurred
int8_t protocol_handler_format_byte(uint8_t input, uint8_t* array, uint8_t arraySize);
#endif