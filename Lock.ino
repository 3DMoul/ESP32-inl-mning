#include "Lock.h"
#include "LockRecorder.h"
#include "Matrix.h"

void Lock::checkLock(String c, class LockRecorder& object)
{
  if(lockCode == c)
  {
    lockedStatus = false;
    object.unlockrecord();
    analogWrite(redRGB, 0);
    analogWrite(greenRGB, 255);
    analogWrite(blueRGB, 0);
    tone(buzzerPin, 100);
    delay(1000);
    noTone(buzzerPin);
    delay(9000);
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
void Lock::newCode(String newC)
{
  lockCode = newC;
}
