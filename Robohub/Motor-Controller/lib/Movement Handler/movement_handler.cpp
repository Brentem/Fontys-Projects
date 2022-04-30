#include "movement_handler.h"

MovementState movementState = STOP;
uint8_t speed = 0;

void movement_handler_setup()
{
    parallax_servo_setup();
    ultrasonic_setup();
}

void movement_handler_handle_movement_message(uint8_t* array)
{
    movementState = (MovementState) array[0];
    speed = array[1];
}

void movement_handler_check_movement()
{
    switch (movementState)
    {
        case STOP:
            parallax_servo_stop();
            break;

        case FORWARDS:
            movement_handler_movement_with_condition(parallax_servo_forwards, speed);
            break;

        case LEFTWARDS:
            movement_handler_movement_with_condition(parallax_servo_leftwards, speed);
            break;

        case RIGHTWARDS:
            movement_handler_movement_with_condition(parallax_servo_rightwards, speed);
            break;

        case BACKWARDS:
            parallax_servo_backwards(speed);
            break;
  
        default:
            break;
    }
}

void movement_handler_movement_with_condition(void (*movement_function)(uint8_t), uint8_t speed)
{
    if(!ultrasonic_activated())
    {
        movement_function(speed);
    }
    else
    {
        movementState = STOP;
    }
}