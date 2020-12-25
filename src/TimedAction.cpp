/*
 * TimedAction.h is simple library for running repeated actions by some interval
 * Created by Alexey Nikolaev (25. December 2020)
 */

#include "TimedAction.h"

TimedAction::TimedAction() {
  this->calledAction = 0;
  this->updatedAt = 0;
  this->interval = UINT32_MAX;
}

void TimedAction::init(void (*calledAction)(void), unsigned long interval) {
  this->calledAction = calledAction;
  this->updatedAt = millis();
  this->interval = interval;
  this->initialized = true;
}

TimedAction::TimedAction(void (*calledAction)(void), unsigned long interval) {
  this->init(calledAction, interval);
}

bool TimedAction::isActive() {
  return this->initialized && this->active;
}

void TimedAction::operate() {
  if (!this->isActive()) {
    return;
  }

  unsigned long currentTime = millis();
  if (currentTime - this->updatedAt >= this->interval) {
    this->calledAction();
    this->passedSteps++;
    this->updatedAt = currentTime;
  }
}

void TimedAction::stop() {
  this->active = false;
}

unsigned int TimedAction::steps() {
  return this->passedSteps;
}