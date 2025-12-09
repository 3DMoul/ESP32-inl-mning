#include "LockRecorder.h"
#include "Lock.h"
LockRecorder record;
Lock currentLock;
int redRGB = 14;
int greenRGB = 6;
int blueRGB = 7;
const int sizeOfCode = 4;
const byte rows = 3;
const byte cols = 3;
const int rowPins[rows] = {4, 3, 2}; // output
const int columnPins[cols] = {22, 21, 20};// input
char buttonMatrix[rows][cols] = {
  {'1', '2', '3'},//column 1
   {'4', '5', '6'},//column 2
    {'7', '8', '9'}};//column 3 
    //here we have the matrix so we can get the value we want
String codeAttempt = "";
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
  analogWrite(redRGB, 0);
  analogWrite(greenRGB, 0);
  analogWrite(blueRGB, 255);
}//setup

void loop()
{
  for (int i = 0; i < rows; i++)
  {
    digitalWrite(rowPins[i], LOW);
    for ( int j = 0; j < cols; j++)
    {
      if(digitalRead(columnPins[j]) == LOW)
      {
        
        codeAttempt += buttonMatrix[j][i];
        Serial.println(codeAttempt);
        Serial.println(codeAttempt.length());
        if(codeAttempt.length() == 4)
        {
          currentLock.checkLock(codeAttempt, record);
          codeAttempt = "";
        }
        while(digitalRead(columnPins[j]) == LOW)
        {

        }
      }
    }
    digitalWrite(rowPins[i], HIGH);
  }
  delay(50);
}//loop