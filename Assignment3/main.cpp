#include "Autobot.h"
#include "Decepticon.h"
#include "Minicon.h"
#include <iostream>

int main() {
    Autobot a;
    Decepticon d;
    Minicon m;

    a.setLevel(5);
    d.setWeaponPower(300);
    m.setSpeed(250);

    std::cout << a.getLevel() << std::endl;
    std::cout << d.getWeaponPower() << std::endl;
    std::cout << m.getSpeed() << std::endl;

    return 0;
}
