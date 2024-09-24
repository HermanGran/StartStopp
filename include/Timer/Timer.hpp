//
// Created by Herman Hårstad Gran on 24/09/2024.
//

#ifndef STARTSTOPP_TIMER_HPP
#define STARTSTOPP_TIMER_HPP

#include <Arduino.h>
#include "Sensor/Sensor.hpp"

class Timer{
public:
    Timer(Sensor &sensor_, int thresholdSensor_, int thresholdTimerStart_, int thresholdTimerStop_);

    void run();

    double getTime();

    bool getRunning();
private:
    long long time;
    long long prevTime;
    long finalTime = 0;
    bool running;

    int thresholdSensor;
    int thresholdTimerStart;
    int thresholdTimerStop;

    Sensor &sensor;
};


#endif //STARTSTOPP_TIMER_HPP
