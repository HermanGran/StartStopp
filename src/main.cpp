#include <Arduino.h>
#include "Sensor/Sensor.hpp"
#include "Timer/Timer.hpp"

Sensor sensor(22);
// Initializes timer class, values are thresholds for sensor, timer-start and timer-stop
Timer timer(sensor, 150, 5000, 2000);

void setup() {
    Serial.begin(9600);
    sensor.setup();
}

void loop() {
    timer.run();

    Serial.print("Running: ");
    Serial.print(timer.getRunning());
    Serial.print("       Value: ");
    Serial.print(sensor.readSensor());
    Serial.print("      Time: ");
    Serial.println(timer.getTime());
}