#include "LockRecorder.h"

void LockRecorder::unlockrecord()
{
  unlockCount++;
  Serial.println(unlockCount);
}
void LockRecorder::unlockattemptRecord()
{
  unlockAttempts++;
  Serial.println(unlockAttempts);
}