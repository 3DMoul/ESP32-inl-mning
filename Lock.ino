#include "Lock.h"
#include "LockRecorder.h"
#include "Matrix.h"
void Lock::checkLock(String c, class LockRecorder& object)
{
  if(lockCode == c)
  {
    long time = 0;
    long newCodeTime = 0;
    lockedStatus = false;
    object.unlockrecord();
    analogWrite(redRGB, 0);
    analogWrite(greenRGB, 255);
    analogWrite(blueRGB, 0);
    tone(buzzerPin, 100);
    delay(1000);
    noTone(buzzerPin);
    while(time < 9000)
    {
      time++;
        Serial.print("time: ");
        Serial.println(time);
      while(digitalRead(columnPins[0]) == LOW && digitalRead(rowPins[0]) == LOW)
      {
        newCodeTime++;
        time++;
        Serial.println(newCodeTime);
        Serial.print("new code time: ");
        if(newCodeTime > 5000)
        {
          while(digitalRead(columnPins[0]) == LOW && digitalRead(rowPins[0]) == LOW)
          {}
          newCode();
          break;
        }
      }
    }
    analogWrite(redRGB, 0);
    analogWrite(greenRGB, 0);
    analogWrite(blueRGB, 255);
    lockedStatus = true;
  
  }
  else
  {
    object.unlockattemptRecord();
    analogWrite(redRGB, 255);
    analogWrite(greenRGB, 0);
    analogWrite(blueRGB, 0);
    tone(buzzerPin, 100);
    delay(2500);
    noTone(buzzerPin);
    delay(5500);
    analogWrite(redRGB, 0);
    analogWrite(greenRGB, 0);
    analogWrite(blueRGB, 255);
  }
}
void Lock::newCode()
{
      analogWrite(redRGB, 255);
      analogWrite(greenRGB, 0);
      analogWrite(blueRGB, 255);
      String newCode = "";
      String comfirmCode = ""; 
      bool newCodeLoop = true;
      delay(50);
      while(newCodeLoop == true)
      {
        if(newCode.length() < 4)
        {
        newCode += readMatrix();
        delay(75);
        Serial.println(newCode);
        Serial.println(newAttempt.length());
        }
        else if(newCode.length() == 4)
        {
          analogWrite(redRGB, 0);
          analogWrite(greenRGB, 255);
          analogWrite(blueRGB, 255);
          comfirmCode += readMatrix();
          delay(75);
          Serial.println(comfirmCode);

          if(comfirmCode.length() == 4)
          {
            if(comfirmCode == newCode)
            {
              Serial.println("COMFIRMD");
            lockCode = newCode;
            newCodeLoop = false;
            analogWrite(redRGB, 0);
            analogWrite(greenRGB, 255);
            analogWrite(blueRGB, 0);
            delay(1000);
            analogWrite(redRGB, 0);
            analogWrite(greenRGB, 0);
            analogWrite(blueRGB, 255);
            }
            else
            {
              Serial.println("NOT COMFIRMD");
              analogWrite(redRGB, 255);
              analogWrite(greenRGB, 0);
              analogWrite(blueRGB, 0);
              delay(1000);
              analogWrite(redRGB, 0);
              analogWrite(greenRGB, 0);
              analogWrite(blueRGB, 255);
              newCodeLoop = false;
            }
          }
        }
        delay(50);
      }
}
