//
// Created by Herman Hårstad Gran on 24/09/2024.
//

#ifndef STARTSTOPP_TIMER_HPP
#define STARTSTOPP_TIMER_HPP

#include <Arduino.h>
#include "Sensor/Sensor.hpp"

class Timer{
public:
    Timer(Sensor &sensor);

    void run();

    signed long getTime();

    bool getRunning();
private:
    signed long time;
    signed long prevTime;
    bool running;

    Sensor &sensor;
};


#endif //STARTSTOPP_TIMER_HPP
