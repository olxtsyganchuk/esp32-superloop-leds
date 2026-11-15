#include <Arduino.h>

struct Config {
    static constexpr uint8_t redLedPin = 4;          // Пін червоного світлодіода
    static constexpr uint8_t yellowLedPin = 5;       // Пін жовтого світлодіода
    static constexpr uint8_t greenLedPin = 6;        // Пін зеленого світлодіода

    static constexpr uint32_t blinkInterval1 = 200;  // Інтервал червоного, мс
    static constexpr uint32_t blinkInterval2 = 500;  // Інтервал жовтого, мс
    static constexpr uint32_t blinkInterval3 = 1000; // Інтервал зеленого, мс
};

// Змінні для збереження часу останнього блимання кожного діода
uint32_t prevMillis1 = 0;
uint32_t prevMillis2 = 0;
uint32_t prevMillis3 = 0;

// Поточний стан кожного світлодіода (LOW = вимкнений, HIGH = увімкнений)
bool ledState1 = LOW;
bool ledState2 = LOW;
bool ledState3 = LOW;

void setup() {
    pinMode(Config::redLedPin, OUTPUT);
    pinMode(Config::yellowLedPin, OUTPUT);
    pinMode(Config::greenLedPin, OUTPUT);
}

void loop() {
    uint32_t currentMillis = millis();

    // 1. Червоний світлодіод (кожні 200 мс)
    if (currentMillis - prevMillis1 >= Config::blinkInterval1) {
        prevMillis1 = currentMillis;
        ledState1 = !ledState1;
        digitalWrite(Config::redLedPin, ledState1);
    }

    // 2. Жовтий світлодіод (кожні 500 мс)
    if (currentMillis - prevMillis2 >= Config::blinkInterval2) {
        prevMillis2 = currentMillis;
        ledState2 = !ledState2;
        digitalWrite(Config::yellowLedPin, ledState2);
    }

    // 3. Зелений світлодіод (кожні 1000 мс)
    if (currentMillis - prevMillis3 >= Config::blinkInterval3) {
        prevMillis3 = currentMillis;
        ledState3 = !ledState3;
        digitalWrite(Config::greenLedPin, ledState3);
    }
}






