 # Simple handler for working with repeaded actions
Version 0.0.2

## Installation
Download repository and install it through the Library Manager in Arduino (tutorial [here](https://www.arduino.cc/en/Guide/Libraries)) or via IDE which your are using (i.g. [platform.io](https://docs.platformio.org/en/latest/librarymanager/index.html#librarymanager))  
Import the library with `#import <TimedAction.h>`

## Basic usage
```c++
#include <TimedAction.h>

TimedAction *temperatureLoading;

void animateTemperature(){
    //do some stuff
}

void setup() {
    temperatureLoading = new TimedAction(animateTemperature, 400);
}

void loop() {
  temperatureLoading->operate();
}
```

## Documentation
`TimedAction();`   
`TimedAction(void (*calledAction)(void), unsigned long interval);`  
### Public methods
`init(void (*calledAction)(void), unsigned long interval)`  
`isActive()`  
`operate()`  
`stop()`  
