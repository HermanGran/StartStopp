//
// Created by Herman Hårstad Gran on 23/09/2024.
//

#ifndef STARTSTOPP_SENSOR_HPP
#define STARTSTOPP_SENSOR_HPP

#include <Arduino.h>

class Sensor{
public:
    Sensor(int pin);

    void setup();

    int readSensor();
private:
    int pin;
};

#endif //STARTSTOPP_SENSOR_HPP
