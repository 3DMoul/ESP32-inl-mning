#ifndef _LockRecorder_H
#define _LockRecorder_H
class LockRecorder
{
  public:
  void unlockrecord();
  void unlockattemptRecord();
  private:
  int unlockCount = 0;
  int unlockAttempts = 0;
};

#endif