#ifndef TERMINAL_SERVER_H
#define TERMINAL_SERVER_H

typedef enum
{
    IDLE,
    MENU,
    DIGITAL,
    ANALOG,
    CLEAR
}State;

void Server_Init();
void ServerLoop();

#endif