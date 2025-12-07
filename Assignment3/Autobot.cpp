#include "Autobot.h"
#include <iostream>

Autobot::Autobot() : Transformer(), _color("red"), _minicon() {}

Autobot::Autobot(uint level, uint strength, uint range,
                 uint fuel, uint ammo, const std::string &color)
    : Transformer(level, strength, range, fuel, ammo),
      _color(color),
      _minicon()
{}

Autobot::~Autobot() {}

void Autobot::setColor(const std::string &color) {
    _color = color;
}

std::string Autobot::getColor() const {
    return _color;
}

bool Autobot::protectHumans() {
    return true;
}

void Autobot::printClass() const {
    std::cout << "Autobot" << std::endl;
}

void Autobot::printAction() const {
    std::cout << "Autobot::printAction" << std::endl;
}

Minicon& Autobot::getMinicon() {
    return _minicon;
}

void Autobot::setMiniconSpeed(unsigned int speed) {
    _minicon.setSpeed(speed);
}

