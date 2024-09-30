//
// Created by Herman Hårstad Gran on 30/09/2024.
//

#include "Button/Button.hpp"

Button::Button(int pinInput_) : pinInput(pinInput_) {}

void Button::setup() const {
    pinMode(pinInput, INPUT_PULLDOWN);
}

bool Button::read() const {
    long long currentTime = millis();
    long long lastPressed;

    if ((digitalRead(pinInput) == HIGH) && currentTime >= lastPressed + 50) {
        lastPressed = millis();
        return true;
    } else {
        return false;
    }
}