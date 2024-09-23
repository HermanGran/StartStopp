#include <Arduino.h>
#include "Sensor/Sensor.hpp"

Sensor sensor(22);
int laser = 7;
bool running = false;

void setup() {
    Serial.begin(9600);
    sensor.setup();
}

void loop() {
    int reading = sensor.readSensor();


    if ((reading < 150) && (!running)) {
        running = true;
    } else {
        running = false;
    }






    Serial.print("Running: ");
    Serial.print(running);
    Serial.print("       Value: ");
    Serial.println(reading);

}