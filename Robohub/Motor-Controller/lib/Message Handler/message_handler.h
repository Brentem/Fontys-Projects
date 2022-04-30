#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <Arduino.h>
#include <movement_handler.h>
//#include <wifi_handler.h>
#include <protocols.h>

void message_handler_setup();
void message_handler_serial_input();
bool message_handler_start_message_received(uint8_t readByte);
void message_handler_build_message_received(bool communicationStarted, uint8_t startByte);
uint8_t message_handler_get_payload_size(uint8_t startByte);
void message_handler_handle_message(uint8_t startByte, uint8_t* payload, uint8_t payloadSize);

#endif