#include "protocol_handler.h"

#include <stddef.h>

int8_t protocol_handler_get_nibbles(uint8_t input, uint8_t* high, uint8_t* low)
{
    if((high == nullptr) || (low == nullptr))
    {
        return -1;
    }

    *high = input & (GET_NIBBLE << 4);
    *high >>= 4;

    *low = input & GET_NIBBLE;

    return 0;
}

int8_t protocol_handler_format_two_bytes(uint16_t input, uint8_t* array, uint8_t arraySize)
{
    if((array == nullptr) || (arraySize != 4))
    {
        return -1;
    }

    for(int i = 0; i < arraySize / 2; i++)
    {
        uint8_t newValue = input >>(SHIFT_BYTES * (1 - i));
        uint8_t high = 0;
        uint8_t low = 0;

        protocol_handler_get_nibbles(newValue, &high, &low);

        uint8_t index = i + i;
        array[index] = high;
        array[index + 1] = low;
    }

    return 0;
}

int8_t protocol_handler_format_byte(uint8_t input, uint8_t* array, uint8_t arraySize)
{
    if((array == nullptr) || (arraySize < 2))
    {
        return -1;
    }

    uint8_t high = 0;
    uint8_t low = 0;

    protocol_handler_get_nibbles(input, &high, &low);

    array[0] = high;
    array[1] = low;

    return 0;
}