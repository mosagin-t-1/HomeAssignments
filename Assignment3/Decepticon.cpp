#include "Decepticon.h"

Decepticon::Decepticon() : _weaponPower(100) {}
Decepticon::~Decepticon() {}

void Decepticon::setWeaponPower(uint power) { _weaponPower = power; }
uint Decepticon::getWeaponPower() const { return _weaponPower; }

bool Decepticon::attack() { return true; }
