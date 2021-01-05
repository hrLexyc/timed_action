#include <Arduino.h>
#include <TimedAction.h>

TimedAction *ledBlinker;

void blinkLed() {
    static uint8_t isTurnedOn = 0;

    isTurnedOn = !isTurnedOn;
    // Manipulate LED which you want to repeatedly turn on and off
}

void setup() {
    ledBlinker = new TimedAction(blinkLed, 1000); //time in msecs
}

void loop() {
    ledBlinker->operate();
}