#include "Minicon.h"

Minicon::Minicon() : _speed(200) {}
Minicon::~Minicon() {}

void Minicon::setSpeed(uint speed) { _speed = speed; }
uint Minicon::getSpeed() const { return _speed; }

bool Minicon::assist() { return true; }
