#include "Autobot.h"
#include "Decepticon.h"
#include "Minicon.h"
#include "Team.h"
#include <iostream>
#include <vector>

int main() {
    Autobot a1;
    Autobot a2(1, 2, 3, 4, 5, "blue");
    Autobot a3(2, 3, 4, 5, 6, "green");

    Decepticon d1;
    Decepticon d2(3, 4, 5, 6, 7, 150);
    Decepticon d3(4, 5, 6, 7, 8, 200);

    Minicon m1;
    Minicon m2(5, 6, 7, 8, 9, 250);
    Minicon m3(6, 7, 8, 9, 10, 300);

    std::cout << a1 << std::endl;
    std::cout << d1 << std::endl;
    std::cout << m1 << std::endl;

    a1.printClass();
    a1.printAction();

    d1.printClass();
    d1.printAction();

    m1.printClass();
    m1.printAction();

    std::vector<Transformer *> v;
    v.push_back(&a1);
    v.push_back(&a2);
    v.push_back(&a3);
    v.push_back(&d1);
    v.push_back(&d2);
    v.push_back(&d3);
    v.push_back(&m1);
    v.push_back(&m2);
    v.push_back(&m3);

    for (Transformer *t : v) {
        t->printClass();
        t->printAction();
    }

    std::cout << "Composition and association demo:" << std::endl;

    std::cout << "Composition check (Autobot contains Minicon):" << std::endl;
    std::cout << a1.getMinicon().getSpeed() << std::endl;
    a1.setMiniconSpeed(777);
    std::cout << a1.getMinicon().getSpeed() << std::endl;

    std::cout << "Association check (Team holds pointers):" << std::endl;
    Team team;
    team.addMember(&a1);
    team.addMember(&d1);
    std::cout << "Team size: " << team.size() << std::endl;
    team.showLevels();
    team.removeMember(&d1);
    std::cout << "Team size after remove: " << team.size() << std::endl;

    return 0;
}

