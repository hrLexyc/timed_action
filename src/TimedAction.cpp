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

bool TimedAction::isServing() {
  return this->serving;
}

void TimedAction::operate() {
  if (!this->isActive() || this->isServing()) {
    return;
  }

  unsigned long currentTime = millis();
  if (currentTime - this->updatedAt >= this->interval) {
    this->serving = true;
    this->calledAction();
    this->passedSteps++;
    this->updatedAt = currentTime;
    this->serving = false;
  }
}

void TimedAction::stop() {
  this->active = false;
}

unsigned int TimedAction::steps() {
  return this->passedSteps;
}