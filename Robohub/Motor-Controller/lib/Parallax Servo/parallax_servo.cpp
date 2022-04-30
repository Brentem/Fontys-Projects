#include "parallax_servo.h"

Servo ServoLeft;
Servo ServoRight;

void parallax_servo_setup()
{
    ServoLeft.attach(LEFT_CONTROL_PIN);
    ServoRight.attach(RIGHT_CONTROL_PIN);

    parallax_servo_stop();
}

void parallax_servo_stop()
{
    if(ServoLeft.attached() && ServoRight.attached())
    {
        ServoLeft.write(SERVO_STOP_VALUE);
        ServoRight.write(SERVO_STOP_VALUE);
    }
}

void parallax_servo_forwards(uint8_t speed)
{
    //movement_servo_control(90, false);
    if(ServoLeft.attached() && ServoRight.attached())
    {
        ServoLeft.write(SERVO_STOP_VALUE + speed);
        ServoRight.write(SERVO_STOP_VALUE - speed);
    }
}

void parallax_servo_leftwards(uint8_t speed)
{
    if(ServoLeft.attached() && ServoRight.attached())
    {
        ServoLeft.write(SERVO_STOP_VALUE);
        ServoRight.write(SERVO_STOP_VALUE - speed);
    }
}

void parallax_servo_rightwards(uint8_t speed)
{
    if(ServoLeft.attached() && ServoRight.attached())
    {
        ServoLeft.write(SERVO_STOP_VALUE + speed);
        ServoRight.write(SERVO_STOP_VALUE);
    }
}

void parallax_servo_backwards(uint8_t speed)
{
    //movement_servo_control(90, true);
    if(ServoLeft.attached() && ServoRight.attached())
    {
        ServoLeft.write(SERVO_STOP_VALUE - speed);
        ServoRight.write(SERVO_STOP_VALUE + speed);
    }
}

// void movement_servo_control(uint8_t speed, bool isBackwards)
// {
//     if(ServoLeft.attached() && ServoRight.attached())
//     {
//         if(isBackwards)
//         {
//             ServoLeft.write(SERVO_STOP_VALUE - speed);
//             ServoRight.write(SERVO_STOP_VALUE + speed);
//         }
//         else
//         {
//             ServoLeft.write(SERVO_STOP_VALUE + speed);
//             ServoRight.write(SERVO_STOP_VALUE - speed);
//         }
//     }
// }

