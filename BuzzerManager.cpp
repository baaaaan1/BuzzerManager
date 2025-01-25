#include "BuzzerManager.h"

// Constructor to initialize the buzzer pin
BuzzerManager::BuzzerManager(int pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW); // Ensure buzzer is off initially
    _beepCount = 0;
    _duration = 0;
    _pause = 0;
    _currentBeep = 0;
    _previousMillis = 0;
    _isBeeping = false;
    _active = false;
}

// Method to beep the buzzer a specified number of times
void BuzzerManager::beep(int count, int duration, int pause, bool state) {
    // Input validation
    if (count <= 0 || duration <= 0 || pause < 0) {
        return; // Invalid parameters, do nothing
    }

    _beepCount = count;
    _duration = duration;
    _pause = pause;
    _active = state;
    _currentBeep = 0;
    _previousMillis = 0;
}

// Update method to be called in the loop() to manage buzzer state
void BuzzerManager::update() {
    if (_active && _currentBeep < _beepCount) {
        unsigned long currentMillis = millis();

        if (currentMillis - _previousMillis >= (_isBeeping ? _duration : _pause)) {
            _previousMillis = currentMillis;

            if (_isBeeping) {
                digitalWrite(_pin, LOW); // Turn off buzzer
                _isBeeping = false;
                _currentBeep++;
            } else {
                digitalWrite(_pin, HIGH); // Turn on buzzer
                _isBeeping = true;
            }
        }
    } else {
        digitalWrite(_pin, LOW); // Ensure buzzer is off when not active
        _active = false; // Reset active state
    }
}
