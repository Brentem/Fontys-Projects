//Joystick.cpp - Bibliotheek voor de joystick.

#include <Arduino.h>
#include <Joystick.h>

Joystick::Joystick(int X_Pin, int Y_Pin)
{
  xPin = X_Pin;
  yPin = Y_Pin;
}

void Joystick::SendMessage()
{
  int X_state = analogRead(xPin);
  int Y_state = analogRead(yPin);  

  int X_map = map(X_state, 0, 1023, -100, 100);
  int Y_map = map(Y_state, 0, 1023, -100, 100);

  if(X_map < -25){
    Serial.println("#JoystickLeft%");
  }
  else if(X_map > 25){
    Serial.println("#JoystickRight%");
  }
  else if(Y_map < -25){
    Serial.println("#JoystickUp%");
  }
  else if(Y_map > 25){
    Serial.println("#JoystickDown%");
  }
  else
  {
    Serial.println("#JoystickNone%");
  }
}