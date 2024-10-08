//
// Created by Herman Hårstad Gran on 24/09/2024.
//

#include "Timer/Timer.hpp"

Timer::Timer(Sensor &sensor_, int thresholdTimerStop_) :
sensor(sensor_),
time(0),
prevTime(0),
running(false),
ready(true),
thresholdTimerStop(thresholdTimerStop_) {}

void Timer::run() {

    if ((sensor.readSensor() && !running && ready)) {
        time = 0;
        prevTime = millis();
        running = true;
        ready = false;
    } else if (sensor.readSensor() && running && time > thresholdTimerStop) {
        running = false;
    }

    if (running) {
        time = millis() - prevTime;
        finalTime = millis();
    }
}

void Timer::reset(bool buttonState_, LiquidCrystal& lcd_) {
    if (buttonState_) {
        if (running) {
            running = false;
        } else {
            lcd_.clear();
            time = 0;
            ready = true;
        }
    }
}

double Timer::getTime() const {
    return time / 1000.0;
}

bool Timer::getRunning() const {
    return running;
}