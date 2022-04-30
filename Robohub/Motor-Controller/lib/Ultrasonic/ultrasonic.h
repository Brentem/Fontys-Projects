#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

#define TRIG_PIN 10
#define ECHO_PIN 11

void ultrasonic_setup();
uint8_t ultrasonic_get_distance();
bool ultrasonic_activated();

#endif