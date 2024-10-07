//
// Created by Herman Hårstad Gran on 30/09/2024.
//

#include "Button/Button.hpp"

Button::Button(int pinInput_) : pinInput(pinInput_), lastPressed(0) {}

void Button::setup() const {
    pinMode(pinInput, INPUT_PULLUP);
}

bool Button::read() {

    if ((digitalRead(pinInput) == LOW) && (millis() >= lastPressed + 200)) {
        lastPressed = millis();
        return true;
    } else {
        return false;
    }
}