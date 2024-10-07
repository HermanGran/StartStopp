//
// Created by Herman Hårstad Gran on 24/09/2024.
//

#ifndef STARTSTOPP_TIMER_HPP
#define STARTSTOPP_TIMER_HPP

#include <Arduino.h>
#include "Sensor/Sensor.hpp"
#include <LiquidCrystal.h>

class Timer{
public:
    Timer(Sensor &sensor_, int thresholdTimerStop_);

    void run();

    void reset(bool buttonState_, LiquidCrystal& lcd_);

    double getTime() const;

    bool getRunning() const;

private:
    long long time;
    long long prevTime;
    unsigned long finalTime = 0;
    bool running;
    bool ready;
    int thresholdTimerStop;

    Sensor &sensor;
};


#endif //STARTSTOPP_TIMER_HPP
