#include <BuzzerManager.h>

const int buzzerPin = 9;
BuzzerManager buzzer(buzzerPin);

void setup() {}

void loop() {
  buzzer.beep(3, 500, 250, 300);
  buzzer.update();
}