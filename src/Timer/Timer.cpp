//
// Created by Herman Hårstad Gran on 24/09/2024.
//

#include "Timer/Timer.hpp"

Timer::Timer(Sensor &sensor_) : sensor(sensor_), time(0), prevTime(0), running(false) {}

void Timer::run() {
    signed long reading = sensor.readSensor();

    if ((reading > 150 && !running)) {
        time = 0;
        prevTime = millis();
        running = true;
    } else if (reading > 150 && running && time > 3000) {
        running = false;
        delay(500);
    }

    if (running) {
        time = millis() - prevTime;
    }
}

signed long Timer::getTime() {
    return time;
}

bool Timer::getRunning() {
    return running;
}