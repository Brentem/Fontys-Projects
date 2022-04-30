#include <Arduino.h>
#include <Wire.h>
#include <LSM6.h>
#include <Joystick.h> //Zelf gemaakt
#include <Knoppen.h> //Zelf gemaakt

LSM6 imu;

Joystick joystick(0, 1);
Knoppen knoppen(2,5,3,4); //Left - Right - Bottom - Top

char Bericht[15] = "";

const char startKarakter = '#';
const char eindKarakter = '%';

bool communicatie = false;

bool AccOn = false;
bool ButtonsOn = true;
bool JoystickOn = true;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  if(!imu.init()){
      Serial.println("Kan IMU niet detecteren en initialiseren!");
      while(1);
  }
  imu.enableDefault();
}

void HandleMessage(char bericht[15])
{
  if(strcmp(bericht, "AccOff") == 0)
  {
    AccOn = false;
  }
  else if(strcmp(bericht, "AccOn") == 0)
  {
    AccOn = true;
  }
  else if(strcmp(bericht, "ButtonsOff") == 0)
  {
    ButtonsOn = false;
  }
  else if(strcmp(bericht, "ButtonsOn") == 0)
  {
    ButtonsOn = true;
  }
  else if(strcmp(bericht, "JoystickOff") == 0)
  {
    JoystickOn = false;
  }
  else if(strcmp(bericht, "JoystickOn") == 0)
  {
    JoystickOn = true;
  }
}

void ReceiveMessages()
{
  if(Serial.available() > 0)
  {
    char readByte = Serial.read();
    if(readByte == startKarakter)
    {
      strcpy(Bericht, "");
      communicatie = true;
    }
    else if(communicatie)
    {
      if (readByte == eindKarakter)
      {
        communicatie = false;
        HandleMessage(Bericht);
      }
      else
      {
        char tmp[2] = {readByte};
        strcat(Bericht, tmp);
      }
    }
  }
}

void loop(){
  ReceiveMessages();

  if(JoystickOn)
  {
    joystick.SendMessage();  
  }

  if(ButtonsOn)
  {
    knoppen.SendMessage();
  }
  
  if(AccOn)
  {
    imu.readAcc();

    int accelY = map(imu.a.y, -32768, 32767, -1000, 1000);

    if(accelY >= 200)
    {
      Serial.println("#AccLeft%");
    }
    else if(accelY <= -200)
    {
      Serial.println("#AccRight%");
    }
    else
    {
      Serial.println("#AccIdle%");
    }
  }
}