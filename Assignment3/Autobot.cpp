#include "Autobot.h"

Autobot::Autobot() : _color("red") {}
Autobot::~Autobot() {}

void Autobot::setColor(const std::string &color) { _color = color; }
std::string Autobot::getColor() const { return _color; }

bool Autobot::protectHumans() { return true; }
