#include "BuzzerManager.h"

BuzzerManager::BuzzerManager(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  _beepCount = 0;
  _frequency = 0;
  _duration = 0;
  _pause = 0;
  _currentBeep = 0;
  _previousMillis = 0;
  _isBeeping = false;
  _active = false;
}

void BuzzerManager::beep(int count, int frequency, int duration, int pause) {
  _beepCount = count;
  _frequency = frequency;
  _duration = duration;
  _pause = pause;

  _currentBeep = 0;
  _previousMillis = 0;
  _isBeeping = false;
  _active = true;
}

void BuzzerManager::update() {
  if (!_active) return;

  unsigned long currentMillis = millis();

  if (_currentBeep < _beepCount) {
    if (!_isBeeping) {
      // Mulai beep jika jeda selesai
      if (currentMillis - _previousMillis >= _pause || _currentBeep == 0) {
        tone(_pin, _frequency, _duration);
        _previousMillis = currentMillis;
        _isBeeping = true;
      }
    } else {
      // Matikan beep jika durasi selesai
      if (currentMillis - _previousMillis >= _duration) {
        noTone(_pin);
        _previousMillis = currentMillis;
        _isBeeping = false;
        _currentBeep++;
      }
    }
  } else {
    // Semua beep selesai
    _active = false;
    noTone(_pin); // Pastikan buzzer mati
  }
}

