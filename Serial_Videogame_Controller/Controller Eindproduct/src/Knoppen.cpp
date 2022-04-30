//Knoppen.cpp - Bibliotheek voor de 4 knoppen

#include <Arduino.h>
#include <Knoppen.h>

Knoppen::Knoppen(int Left, int Right, int Bottom, int Top)
{
  pinMode(Left, INPUT_PULLUP);
  pinMode(Right, INPUT_PULLUP);
  pinMode(Bottom, INPUT_PULLUP);
  pinMode(Top, INPUT_PULLUP);

  _left = Left;
  _right = Right;
  _bottom = Bottom;
  _top = Top;
}

void Knoppen::SendMessage()
{
  int leftState = digitalRead(_left);
  int rightState = digitalRead(_right);
  int bottomState = digitalRead(_bottom);
  int topState = digitalRead(_top);

  if(leftState == LOW){
    Serial.println("#ButtonLeft%");
  }
  else if(rightState == LOW){
    Serial.println("#ButtonRight%");
  }
  else if(bottomState == LOW){
    Serial.println("#ButtonDown%");
  }
  else if(topState == LOW){
    Serial.println("#ButtonUp%");
  }
  else
  {
    Serial.println("#ButtonNone%");
  }
  
}