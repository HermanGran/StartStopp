//
// Created by Herman Hårstad Gran on 30/09/2024.
//

#include "Button/Button.hpp"

Button::Button(int pinInput_) : pinInput(pinInput_) {}

void Button::setup() {
    pinMode(pinInput, INPUT_PULLDOWN);
}

bool Button::read() {
    return digitalRead(pinInput);
}