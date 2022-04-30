#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <Wire.h>
#include <protocols.h>
#include "lsm6.h"

#define SENSOR_SLAVE_ADDRESS (LSM6_DEVICE_ADDRESS)
#define CONFIGURATION 0x80
#define IF_INC 0x04

#define LIGHT_SENSOR_PIN A0
#define WARMTH_SENSOR_PIN A1

#define DELAY 250

struct sensors_data
{
    int16_t accX;
    int16_t accY;
    int16_t accZ;
    uint16_t analogLight;
    uint16_t flux;
    uint16_t analogWarmth;
    int16_t temperature;
}; //14 bytes


void sensors_setup();
void sensors_accelerometer_set_measurement_mode();
void sensors_update_data(sensors_data* data);
//void sensors_send_data();
void sensors_loop();

#endif