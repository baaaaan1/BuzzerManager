#include <BuzzerManager.h>

const int buzzerPins[] = {9, 10};
BuzzerManager buzzers[] = {BuzzerManager(buzzerPins[0]), BuzzerManager(buzzerPins[1])};

void setup() {
    // Initialize buzzer pins
    for (int i = 0; i < 2; i++) {
        pinMode(buzzerPins[i], OUTPUT);
    }
}

void loop() {
    // Beep the first buzzer twice
    buzzers[0].beep(2, 400, 300, true);
    // Beep the second buzzer three times
    buzzers[1].beep(3, 600, 250, true);
    
    // Update the state of both buzzers
    for (int i = 0; i < 2; i++) {
        buzzers[i].update();
    }
    
    // Optional: Add a delay to control the loop frequency
    delay(1000); // Adjust as necessary
}
