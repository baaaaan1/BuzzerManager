#include "BuzzerManager.h"

BuzzerManager::BuzzerManager(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW); // Pastikan buzzer mati di awal
  _beepCount = 0;
  _duration = 0;
  _pause = 0;
  _currentBeep = 0;
  _previousMillis = 0;
  _isBeeping = false;
  _active = false;
}

void BuzzerManager::beep(int count, int duration, int pause, bool state) {
  _beepCount = count;
  _duration = duration;
  _pause = pause;

  _currentBeep = 0;
  _previousMillis = 0;
  _isBeeping = false;
  
  if (state) {
    _active = true;
  } else {
    _active = false;
  }
}

void BuzzerManager::update() {
  if (!_active) return;

  unsigned long currentMillis = millis();

  if (_currentBeep < _beepCount) {
    if (!_isBeeping) {
      // Mulai beep jika jeda selesai
      if (currentMillis - _previousMillis >= _pause || _currentBeep == 0) {
        digitalWrite(_pin, HIGH); // Hidupkan buzzer
        _previousMillis = currentMillis;
        _isBeeping = true;
      }
    } else {
      // Matikan beep jika durasi selesai
      if (currentMillis - _previousMillis >= _duration) {
        digitalWrite(_pin, LOW); // Matikan buzzer
        _previousMillis = currentMillis;
        _isBeeping = false;
        _currentBeep++;
      }
    }
  } else {
    // Stop
    _active = false;
    digitalWrite(_pin, LOW); // Pastikan buzzer mati
  }
}
