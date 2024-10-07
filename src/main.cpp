#include <Arduino.h>
#include "Sensor/Sensor.hpp"
#include "Timer/Timer.hpp"
#include <LiquidCrystal.h>
#include "Button/Button.hpp"

// Initializes Sensor class
Sensor sensor(22, 150);

// Initializes timer class, value is timer-start and timer-stop
Timer timer(sensor, 5000);

Button button(7);
int clear = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    sensor.setup();
    lcd.begin(16,2);
    button.setup();
}

void loop() {
    timer.run();
    timer.reset(button.read(), lcd);

    if (sensor.errorDetection()) {
        lcd.setCursor(0, 1);
        lcd.print("Laser error");
        clear = 0;
    } else {
        if (clear == 0) {
            lcd.setCursor(0, 1);
            clear += 1;
            lcd.clear();
        }
        lcd.setCursor(0, 1);
        lcd.print(timer.getTime());
    }
}