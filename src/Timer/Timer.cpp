//
// Created by Herman Hårstad Gran on 24/09/2024.
//

#include "Timer/Timer.hpp"

Timer::Timer(Sensor &sensor_, int thresholdSensor_, int thresholdTimerStart_, int thresholdTimerStop_) :
sensor(sensor_),
time(0),
prevTime(0),
running(false),
thresholdSensor(thresholdSensor_),
thresholdTimerStart(thresholdTimerStart_),
thresholdTimerStop(thresholdTimerStop_) {}

void Timer::run() {
    int reading = sensor.readSensor();

    if ((reading < thresholdSensor && !running && (millis() > finalTime + thresholdTimerStart))) {
        time = 0;
        prevTime = millis();
        running = true;
    } else if (reading < thresholdSensor && running && time > thresholdTimerStart) {
        running = false;
    }

    if (running) {
        time = millis() - prevTime;
        finalTime = millis();
    }
}

double Timer::getTime() const {
    return time / 1000.0;
}

bool Timer::getRunning() const {
    return running;
}