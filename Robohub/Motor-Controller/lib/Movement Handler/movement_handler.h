#ifndef MOVEMENT_HANDLER_H
#define MOVEMENT_HANDLER_H

#include <Arduino.h>
#include "ultrasonic.h"
#include "parallax_servo.h"

void movement_handler_setup();
void movement_handler_handle_movement_message(uint8_t* array);
void movement_handler_check_movement();
void movement_handler_movement_with_condition(void (*movement_function)(uint8_t), uint8_t speed);
#endif