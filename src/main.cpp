#include <Arduino.h>
#include "Sensor/Sensor.hpp"

Sensor sensor(22);
int laser = 7;
bool running = false;

int timer = 0;
int prevTime = 0;

void setup() {
    Serial.begin(9600);
    sensor.setup();
}

void loop() {
    int reading = sensor.readSensor();


    if ((reading > 150 && !running)) {
        timer = 0;
        prevTime = millis();
        running = true;
    } else if (reading > 150 && running && timer > 3000) {
        running = false;
        delay(500);
    }

    if (running) {
        timer = millis() - prevTime;
    }


    Serial.print("Running: ");
    Serial.print(running);
    Serial.print("       Value: ");
    Serial.print(reading);
    Serial.print("      Time: ");
    Serial.println(timer);

}