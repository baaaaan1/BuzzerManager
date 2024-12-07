#ifndef BuzzerManager_h
#define BuzzerManager_h

#include <Arduino.h>

class BuzzerManager {
  public:
    BuzzerManager(int pin);
    void beep(int count, int frequency, int duration, int pause);
    void update(); // Harus dipanggil dalam loop()

  private:
    int _pin;
    int _beepCount;
    int _frequency;
    int _duration;
    int _pause;

    int _currentBeep;
    unsigned long _previousMillis;
    bool _isBeeping;
    bool _active;
};

#endif
