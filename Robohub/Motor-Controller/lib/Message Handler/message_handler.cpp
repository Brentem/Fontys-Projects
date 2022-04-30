#include "message_handler.h"

uint8_t messageStartMarkers[MESSAGE_START_MARKERS_AMOUNT] = {MOVEMENT_COMMAND, SSID_COMMAND, NETWORK_PASSWORD_COMMAND};

void message_handler_setup()
{
    Serial.begin(9600);
}

void message_handler_serial_input()
{
    if(Serial.available() >= 4)
    {
        uint8_t startByte = Serial.read();

        bool communicationStarted = message_handler_start_message_received(startByte);

        message_handler_build_message_received(communicationStarted, startByte);
    }
}

bool message_handler_start_message_received(uint8_t readByte)
{
    bool communicationStarted = false;

    for(int i = 0; i < MESSAGE_START_MARKERS_AMOUNT; i++)
    {
        if(readByte == messageStartMarkers[i])
        {
            communicationStarted = true;
        }
    }

    return communicationStarted;
}

void message_handler_build_message_received(bool communicationStarted, uint8_t startByte)
{
    uint8_t payloadSize = message_handler_get_payload_size(startByte);
    uint8_t payload[payloadSize];
    uint8_t index = 0;

    while(communicationStarted)
    {
        uint8_t readByte = Serial.read();

        if(readByte == MESSAGE_END_MARKER)
        {
            communicationStarted = false;
            message_handler_handle_message(startByte, payload, index);
        }
        else
        {
            payload[index] = readByte;
            index++;
        }
    }
}

uint8_t message_handler_get_payload_size(uint8_t startByte)
{
    uint8_t payloadSize = 0;

    switch (startByte)
    {
    case MOVEMENT_COMMAND:
        payloadSize = MOVEMENT_PAYLOAD_SIZE;
        break;

    case SSID_COMMAND:
    case NETWORK_PASSWORD_COMMAND:
        payloadSize = 20;
        break;
    
    default:
        break;
    }

    return payloadSize;
}

void message_handler_handle_message(uint8_t startByte, uint8_t* payload, uint8_t bytesRetrieved)
{
    switch (startByte)
    {
    case MOVEMENT_COMMAND:
        movement_handler_handle_movement_message(payload);
        break;

    // case SSID_COMMAND:
    //     wifi_handler_build_ssid_payload(payload, bytesRetrieved);
    //     break;

    // case NETWORK_PASSWORD_COMMAND:
    //     wifi_handler_build_network_password_payload(payload, bytesRetrieved);
    //     break;
    
    default:
        break;
    }
}