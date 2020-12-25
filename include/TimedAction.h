/*
 * TimedAction.h is simple library for running repeated actions by some interval
 * Created by Alexey Nikolaev (25. December 2020)
 */

#ifndef TimedAction_Header
#define TimedAction_Header

#include "Arduino.h"

class TimedAction {
  public:
    TimedAction();
    TimedAction(void (*calledAction)(void), unsigned long interval);
    void init(void (*calledAction)(void), unsigned long interval);
    bool isActive();
    void operate();
    void stop();
    unsigned int steps();
  private:
    bool initialized = false;
    bool active = true;
    unsigned int passedSteps = 0;
    unsigned long updatedAt;
    void (*calledAction)(void);
    unsigned long interval;
};

#endif