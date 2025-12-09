#include "LockRecorder.h"

void LockRecorder::unlockrecord()
{
  unlockCount++;
  Serial.println("Times unlocked");
  Serial.println(unlockCount);
}
void LockRecorder::unlockattemptRecord()
{
  unlockAttempts++;
  Serial.println("Times faled to unlock");
  Serial.println(unlockAttempts);
}
