#ifndef _Lock_H
#define _Lock_H

class Lock
{
  public:
  void checkLock(String c, class LockRecorder& object);
  void newCode();
  private:
  bool lockedStatus = true;
  String lockCode = "1234";
};

#endif