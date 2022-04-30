#ifndef FIFO_H
#define FIFO_H

#include <Arduino.h>

#define BUFSIZE 5

struct FifoFlux{
    int16_t head;
    int16_t tail;
    uint16_t buffer[BUFSIZE];
    int16_t count;
};

struct FifoWarmth{
    int16_t head;
    int16_t tail;
    float buffer[BUFSIZE];
    int16_t count; 
};

// pre: readvalue not null
// post : function returnvalue:
// 	0 : read succeeded
// 	-1: readvalue null or buffer empty
int16_t FifoFluxRead(uint16_t* value, FifoFlux* fifoFlux);

//Please define a prototype for the write function taking in to account the following
//-	Return value 0 if element has been added.
//-	Return value 1 if element has been added to the buffer, but the buffer was already full
//-	Return value -1 if the element has not been added.
int16_t FifoFluxWrite(uint16_t value, FifoFlux* fifoFlux);

uint16_t FifoFluxAverageBuffer(uint16_t* average, FifoFlux* fifoFlux);



// pre: readvalue not null
// post : function returnvalue:
// 	0 : read succeeded
// 	-1: readvalue null or buffer empty
int16_t FifoWarmthRead(float* value, FifoWarmth* fifoWarmth);

//Please define a prototype for the write function taking in to account the following
//-	Return value 0 if element has been added.
//-	Return value 1 if element has been added to the buffer, but the buffer was already full
//-	Return value -1 if the element has not been added.
int16_t FifoWarmthWrite(float value, FifoWarmth* fifoWarmth);

int16_t FifoWarmthAverageBuffer(int16_t* average, FifoWarmth* fifoWarmth);

#endif