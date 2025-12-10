#ifndef _Matrix_H
#define _Matrix_H
#include "Lock.h"

const byte rows = 3;
const byte cols = 3;
const int rowPins[rows] = {4, 3, 2}; // output
const int columnPins[cols] = {22, 21, 20};// input
char buttonMatrix[rows][cols] = {
  {'1', '2', '3'},//column 1
   {'4', '5', '6'},//column 2
    {'7', '8', '9'}};//column 3 
    //here we have the matrix so we can get the value we want

String readMatrix()
{
  String codeAttempt = "";
  for (int i = 0; i < rows; i++)
    {
      digitalWrite(rowPins[i], LOW);
      for ( int j = 0; j < cols; j++)
      {
        if(digitalRead(columnPins[j]) == LOW)
        {
          codeAttempt += buttonMatrix[j][i];
          return codeAttempt;
        }
      }
      digitalWrite(rowPins[i], HIGH);
    }
  return "";
  }
  #endif
  
  /*        codeAttempt += 
          Serial.println(codeAttempt);
          Serial.println(codeAttempt.length());
          if(codeAttempt.length() == 4)
          {
            currentLock.checkLock(codeAttempt, record);
            codeAttempt = "";
          }
          */