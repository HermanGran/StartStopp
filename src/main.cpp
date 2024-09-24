#include <Arduino.h>
#include "Sensor/Sensor.hpp"
#include "Timer/Timer.hpp"

Sensor sensor(22);
Timer timer(sensor);

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