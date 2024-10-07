//
// Created by Herman Hårstad Gran on 23/09/2024.
//
#include "Sensor/Sensor.hpp"

Sensor::Sensor(int pin_, int threshold_) : pin(pin_), threshold(threshold_), time(0) {}

void Sensor::setup() {
    pinMode(pin, INPUT);
}

bool Sensor::readSensor() {
    if (threshold < analogRead(pin)) {
        return true;
    } else {
        return false;
    }
}

bool Sensor::errorDetection() {

    if (readSensor()) {
        time = millis() - prevTime;
    } else {
        prevTime = millis();
        time = 0;
    }

    if (time >= 4000) {
        return true;
    } else {
        return false;
    }
}