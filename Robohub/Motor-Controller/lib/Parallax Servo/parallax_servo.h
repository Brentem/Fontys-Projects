#ifndef PARALLAX_SERVO_H
#define PARALLAX_SERVO_H

#include <Arduino.h>
#include <Servo.h>

#define LEFT_CONTROL_PIN 9
#define RIGHT_CONTROL_PIN 6

#define SERVO_STOP_VALUE 90

typedef enum{
    STOP,
    FORWARDS,
    LEFTWARDS,
    RIGHTWARDS,
    BACKWARDS
} MovementState;

void parallax_servo_setup();

void parallax_servo_stop();
void parallax_servo_forwards(uint8_t speed);
void parallax_servo_leftwards(uint8_t speed);
void parallax_servo_rightwards(uint8_t speed);
void parallax_servo_backwards(uint8_t speed);

#endif