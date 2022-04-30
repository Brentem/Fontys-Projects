#include "fifo.h"

int16_t FifoFluxRead(uint16_t* value, FifoFlux* fifoFlux)
{
    if(value == NULL || fifoFlux->count == 0);
    {
        return -1;
    }

    *value = fifoFlux->buffer[fifoFlux->tail];
    fifoFlux->tail = (fifoFlux->tail + 1) % BUFSIZE;

    fifoFlux->count--;

    return 0;
}

int16_t FifoFluxWrite(uint16_t value, FifoFlux* fifoFlux)
{
    int16_t returnValue = -1;

    fifoFlux->buffer[fifoFlux->head] = value;

    if(fifoFlux->count != BUFSIZE)
    {
        fifoFlux->count++;
        returnValue = 0;
    }
    else
    {
        if(fifoFlux->head == fifoFlux->tail)
        {
            fifoFlux->tail++;
        }
        returnValue = 1;
    }

    fifoFlux->head = (fifoFlux->head + 1) % BUFSIZE;

    return returnValue;
}

uint16_t FifoFluxAverageBuffer(uint16_t* average, FifoFlux* fifoFlux)
{
    if(fifoFlux->count == 0 || average == NULL || fifoFlux == NULL)
    {
        return -1;
    }

    for(int16_t i = 0; i < BUFSIZE; i++)
    {
        *average += fifoFlux->buffer[i];
    }

    *average = round((*average / BUFSIZE) * 100);

    return 0;
}

int16_t FifoWarmthRead(float* value, FifoWarmth* fifoWarmth)
{
    if(value == NULL || fifoWarmth->count == 0);
    {
        return -1;
    }

    *value = fifoWarmth->buffer[fifoWarmth->tail];
    fifoWarmth->tail = (fifoWarmth->tail + 1) % BUFSIZE;

    fifoWarmth->count--;

    return 0;
}

int16_t FifoWarmthWrite(float value, FifoWarmth* fifoWarmth)
{
    int16_t returnValue = -1;

    fifoWarmth->buffer[fifoWarmth->head] = value;

    if(fifoWarmth->count != BUFSIZE)
    {
        fifoWarmth->count++;
        returnValue = 0;
    }
    else
    {
        if(fifoWarmth->head == fifoWarmth->tail)
        {
            fifoWarmth->tail++;
        }
        returnValue = 1;
    }

    fifoWarmth->head = (fifoWarmth->head + 1) % BUFSIZE;

    return returnValue;
}

int16_t FifoWarmthAverageBuffer(int16_t* temperatureAverage, FifoWarmth* fifoWarmth)
{
    if(fifoWarmth->count == 0 || temperatureAverage == NULL || fifoWarmth == NULL)
    {
        return -1;
    }

    float average = 0;

    for(int16_t i = 0; i < BUFSIZE; i++)
    {
        average += fifoWarmth->buffer[i];
    }

    *temperatureAverage = round((average / BUFSIZE) * 100);

    return 0;
}