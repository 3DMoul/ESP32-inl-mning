#include "LockRecorder.h"
#include "Lock.h"
#include "Matrix.h"
LockRecorder record;
Lock currentLock;
int buzzerPin = 12;
int redRGB = 14;
int greenRGB = 6;
int blueRGB = 7;
const int sizeOfCode = 4;
const byte rowsmain = 3;
const byte colsmain = 3;
const int rowPinsmain[rows] = {4, 3, 2}; // output
const int columnPinsmain[cols] = {22, 21, 20};// input
String newAttempt;
String newCode;
void setup()
{
  Serial.begin(115200);
  for(int i = 0; i < rows ; i++)
  {
    pinMode(rowPins[i], OUTPUT);
  }
  for(int i = 0; i < cols ; i++)
  {
    pinMode(columnPins[i], INPUT_PULLUP);
  }
  pinMode(redRGB, OUTPUT);
  pinMode(greenRGB, OUTPUT);
  pinMode(blueRGB, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  analogWrite(redRGB, 0);
  analogWrite(greenRGB, 0);
  analogWrite(blueRGB, 255);
}//setup

void loop()
{
  long time = 0;
  newAttempt += readMatrix();
  while(digitalRead(columnPins[0]) == LOW && digitalRead(rowPins[0]) == LOW)
  {
    time += 1;
    Serial.println(time);
  }
  delay(100);
    if(time > 5000)
    {
      analogWrite(redRGB, 255);
      analogWrite(greenRGB, 255);
      analogWrite(blueRGB, 255);
      newAttempt = "";
      bool istrue = true;
      while(istrue == true)
      {
        newAttempt += readMatrix();
        delay(75);
        Serial.println(newAttempt.length());
        if(newAttempt.length() == 4)
        {
          currentLock.newCode(newAttempt);
          time = 0;
          newAttempt = "";
          istrue = false;
          analogWrite(redRGB, 0);
          analogWrite(greenRGB, 0);
          analogWrite(blueRGB, 255);
        }
        delay(50);
      }
    }
    else
    {
      Serial.println(newAttempt.length());
      Serial.println(newAttempt);
      if (newAttempt.length() == 4)
      {
        currentLock.checkLock(newAttempt, record);
        newAttempt = "";
      }
    }
  delay(50);
}//loop
