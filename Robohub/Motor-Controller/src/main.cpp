#include <Arduino.h>
#include <movement_handler.h>
#include <message_handler.h>
#include <sensors.h>

//https://www.volunteerlabs.us/parallax-feedback-360-and-arduino/
//https://www.parallax.com/product/parallax-feedback-360-high-speed-servo/
//https://forum.arduino.cc/t/sending-byte-arrays/256761
//https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
//https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/
//https://www.youtube.com/watch?v=Pip_r6ANDSI 

void setup() {
  // put your setup code here, to run once:
  message_handler_setup();
  movement_handler_setup();
  sensors_setup();
  sensors_accelerometer_set_measurement_mode();
}

void loop() {
  // put your main code here, to run repeatedly:
  message_handler_serial_input();
  movement_handler_check_movement();
  sensors_loop();
}