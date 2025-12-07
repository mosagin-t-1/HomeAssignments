#include "Decepticon.h"
#include <iostream>

Decepticon::Decepticon() 
    : Transformer(), _weaponPower(100) {}

Decepticon::Decepticon(uint level, uint strength, uint range,
                       uint fuel, uint ammo, uint weaponPower)
    : Transformer(level, strength, range, fuel, ammo),
      _weaponPower(weaponPower) {}

Decepticon::~Decepticon() {}

void Decepticon::setWeaponPower(uint power) {
    _weaponPower = power;
}

uint Decepticon::getWeaponPower() const {
    return _weaponPower;
}

bool Decepticon::attack() {
    return true;
}

void Decepticon::printClass() const {
    std::cout << "Decepticon" << std::endl;
}

void Decepticon::printAction() const {
    std::cout << "Decepticon::printAction" << std::endl;
}
