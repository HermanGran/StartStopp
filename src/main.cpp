#include <Arduino.h>
#include "Sensor/Sensor.hpp"
#include "Timer/Timer.hpp"
#include <LiquidCrystal.h>
#include "Button/Button.hpp"

Sensor sensor(22);
// Initializes timer class, values are thresholds for sensor, timer-start and timer-stop
Timer timer(sensor, 150, 5000, 2000);

Button button(7);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    Serial.begin(9600);
    sensor.setup();
    lcd.begin(16,2);
    button.setup();
}

void loop() {
    timer.run();
    timer.reset(button.read(), lcd);
    lcd.setCursor(0, 1);
    lcd.print(timer.getTime());
}