#include <BuzzerManager.h>

const int buzzerPins[] = {9, 10};
BuzzerManager buzzers[] = {BuzzerManager(buzzerPins[0]), BuzzerManager(buzzerPins[1])};

void setup() {}

void loop() {
  buzzers[0].beep(2, 400, 300, 200);
  buzzers[1].beep(3, 600, 250, 300);
  for (int i = 0; i < 2; i++) buzzers[i].update();
}
