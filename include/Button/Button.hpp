//
// Created by Herman Hårstad Gran on 30/09/2024.
//

#ifndef STARTSTOPP_BUTTON_HPP
#define STARTSTOPP_BUTTON_HPP

#include "Arduino.h"

class Button {
public:
    Button(int pinInput_);

    void setup();

    bool read();
private:
    int pinInput;
};

#endif //STARTSTOPP_BUTTON_HPP
