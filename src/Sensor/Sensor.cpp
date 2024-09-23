//
// Created by Herman Hårstad Gran on 23/09/2024.
//
#include "Sensor/Sensor.hpp"

Sensor::Sensor(int pin) : pin(pin) {}

void Sensor::setup() {
    pinMode(pin, INPUT);
}

int Sensor::readSensor() {
    return analogRead(pin);
}