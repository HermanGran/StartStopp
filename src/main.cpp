#include <Arduino.h>
#include "Sensor/Sensor.hpp"
#include "Timer/Timer.hpp"
#include <LiquidCrystal.h>

Sensor sensor(22);
// Initializes timer class, values are thresholds for sensor, timer-start and timer-stop
Timer timer(sensor, 150, 5000, 2000);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    Serial.begin(9600);
    sensor.setup();
    lcd.begin(16,2);
}

void loop() {
    timer.run();

    Serial.print("Running: ");
    Serial.print(timer.getRunning());
    Serial.print("       Value: ");
    Serial.print(sensor.readSensor());
    Serial.print("      Time: ");
    Serial.println(timer.getTime());

    lcd.setCursor(0, 1);
    //lcd.clear();
    lcd.print(timer.getTime());

}