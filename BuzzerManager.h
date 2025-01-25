#ifndef BuzzerManager_h
#define BuzzerManager_h

#include <Arduino.h>

class BuzzerManager {
  public:
    // Constructor to initialize the buzzer pin
    BuzzerManager(int pin);

    // Method to beep the buzzer a specified number of times
    // count: number of beeps
    // duration: duration of each beep in milliseconds
    // pause: pause between beeps in milliseconds
    // state: true to turn on the buzzer, false to turn it off
    void beep(int count, int duration, int pause, bool state);

    // Update method to be called in the loop() to manage buzzer state
    void update();

  private:
    int _pin;                // Pin number for the buzzer
    int _beepCount;         // Number of beeps
    int _duration;          // Duration of each beep
    int _pause;             // Pause between beeps

    int _currentBeep;       // Current beep index
    unsigned long _previousMillis; // Timing for beeping
    bool _isBeeping;        // State of the buzzer
    bool _active;           // Is the buzzer active?
};

#endif
