#include "ultrasonic.h"

bool ultrasonicActivated = false;

void ultrasonic_setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

uint8_t ultrasonic_get_distance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    uint32_t duration = pulseIn(ECHO_PIN, HIGH);

    return duration * 0.034/2;
}

bool ultrasonic_activated()
{
    uint8_t distance = ultrasonic_get_distance();

    if((distance <= 15))
    {
        ultrasonicActivated = true;
    }
    else if((distance >= 18) & (ultrasonicActivated))
    {
        ultrasonicActivated = false;
    }

    return ultrasonicActivated;
}