#include "Minicon.h"
#include <iostream>

Minicon::Minicon() 
    : Transformer(), _speed(200) {}

Minicon::Minicon(uint level, uint strength, uint range,
                 uint fuel, uint ammo, uint speed)
    : Transformer(level, strength, range, fuel, ammo),
      _speed(speed) {}

Minicon::~Minicon() {}

void Minicon::setSpeed(uint speed) {
    _speed = speed;
}

uint Minicon::getSpeed() const {
    return _speed;
}

bool Minicon::assist() {
    return true;
}

void Minicon::printClass() const {
    std::cout << "Minicon" << std::endl;
}

void Minicon::printAction() const {
    std::cout << "Minicon::printAction" << std::endl;
}
