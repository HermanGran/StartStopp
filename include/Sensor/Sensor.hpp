//
// Created by Herman Hårstad Gran on 23/09/2024.
//

#ifndef STARTSTOPP_SENSOR_HPP
#define STARTSTOPP_SENSOR_HPP

#include <Arduino.h>

class Sensor{
public:
    Sensor(int pin_, int threshold_);

    void setup();

    bool readSensor();

    bool errorDetection();

private:
    int pin;
    int threshold;
    long long time;
    long long prevTime;
};

#endif //STARTSTOPP_SENSOR_HPP
