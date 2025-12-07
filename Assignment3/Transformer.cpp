#include "Transformer.h"
#include <iostream>

Transformer::Transformer()
    : _level(0), _strength(0), _range(0), _fuel(0), _ammo(0) {}

Transformer::Transformer(uint level, uint strength, uint range, uint fuel, uint ammo)
    : _level(level), _strength(strength), _range(range), _fuel(fuel), _ammo(ammo) {}

Transformer::~Transformer() {}

bool Transformer::move() {
    return true;
}

bool Transformer::fire() {
    if (_ammo > 0) {
        _ammo--;
    }
    return true;
}

bool Transformer::transform() {
    return true;
}

void Transformer::setLevel(uint level) {
    _level = level;
}

uint Transformer::getLevel() const {
    return _level;
}

void Transformer::setStrength(uint strength) {
    _strength = strength;
}

uint Transformer::getStrength() const {
    return _strength;
}

void Transformer::setRange(uint range) {
    _range = range;
}

uint Transformer::getRange() const {
    return _range;
}

void Transformer::setFuel(uint fuel) {
    _fuel = fuel;
}

uint Transformer::getFuel() const {
    return _fuel;
}

void Transformer::setAmmo(uint ammo) {
    _ammo = ammo;
}

uint Transformer::getAmmo() const {
    return _ammo;
}

void Transformer::printAction() const {
    std::cout << "Transformer::printAction" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Transformer &t) {
    out << "Transformer level=" << t.getLevel()
        << " strength=" << t.getStrength()
        << " range=" << t.getRange()
        << " fuel=" << t.getFuel()
        << " ammo=" << t.getAmmo();
    return out;
}
