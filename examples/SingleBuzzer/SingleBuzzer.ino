#include <BuzzerManager.h>

const int buzzerPin = 9;
BuzzerManager buzzer(buzzerPin);

void setup() {
    // Initialize the buzzer pin
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    // Beep the buzzer three times
    buzzer.beep(3, 500, 250, true);
    // Update the state of the buzzer
    buzzer.update();
    
    // Optional: Add a delay to control the loop frequency
    delay(1000); // Adjust as necessary
}
