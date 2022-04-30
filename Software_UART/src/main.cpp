#include <Arduino.h>

extern "C"{
#include <Terminal_Server.h>
}

void setup() {
  // put your setup code here, to run once:
  Server_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  ServerLoop();
}