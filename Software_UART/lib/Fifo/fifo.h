#ifndef FIFO_H
#define FIFO_H

#include <stdint.h>

#define BUFSIZE 20

typedef struct{
    uint8_t head;
    uint8_t tail;
    uint8_t buffer[BUFSIZE];
    uint8_t count;
} Fifo;

// pre: readvalue not null
// post : function returnvalue:
// 	0 : read succeeded
// 	-1: readvalue null or buffer empty

int fiforead(uint8_t* value, Fifo* fifo);

//Please define a prototype for the write function taking in to account the following
//-	Return value 0 if element has been added.
//-	Return value 1 if element has been added to the buffer, but the buffer was already full
//-	Return value -1 if the element has not been added.
int fifowrite(uint8_t value, Fifo* fifo);

int averageBuffer(double* average, Fifo* fifo);

#endif
