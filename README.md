# BuzzerManager Library
![GitHub release (latest by date)](https://img.shields.io/github/v/release/baaaaan1/BuzzerManager)
![GitHub](https://img.shields.io/github/license/baaaaan1/BuzzerManager)

**BuzzerManager** is an Arduino library for controlling buzzers with flexible and non-blocking beep patterns. This library is ideal for projects that require independent control of multiple buzzers or specific beep sequences.

## Features
- **Non-blocking**: Does not use `delay()`, allowing other tasks to run concurrently.
- **Flexible Patterns**: Set the number of beeps, frequency, duration, and pause between beeps.
- **Multi-Buzzer Support**: Control multiple buzzers independently.

## Installation
1. Download the library files.
2. Place the folder `BuzzerManager` in the `libraries` directory of your Arduino environment.
3. Restart the Arduino IDE.

## Usage
### Initialization
```cpp
#include <BuzzerManager.h>

const int buzzerPin = 9;  // Pin connected to the buzzer
BuzzerManager buzzer(buzzerPin);
