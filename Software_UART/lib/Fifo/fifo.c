#include "fifo.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

int fiforead(uint8_t* value, Fifo* fifo)
{
    if(value == NULL || fifo->count == 0)
    {
        return -1;
    }

    *value = fifo->buffer[fifo->tail];
    fifo->tail = (fifo->tail + 1) % BUFSIZE; //Als waarde 9 is dan wordt tail weer 0

    fifo->count--;

    return 0;
}


int fifowrite(uint8_t value, Fifo* fifo)
{
    int returnValue = -1;

    fifo->buffer[fifo->head] = value;

    if(fifo->count != BUFSIZE)
    {
        fifo->count++;
        returnValue = 0;
    }
    else
    {
        if(fifo->head == fifo->tail)
        {
            fifo->tail++;
        }
        returnValue = 1;
    }

    fifo->head = (fifo->head + 1) % BUFSIZE;

    return returnValue;
}

int averageBuffer(double* average, Fifo* fifo)
{
    if(fifo->count == 0 || average == NULL || fifo == NULL)
    {
        return -1;
    }

    for(int i = 0; i < BUFSIZE; i++)
    {
        *average += fifo->buffer[i];
    }

    *average = *average / BUFSIZE;

    return 0;
}
