#include "Team.h"
#include <algorithm>
#include <iostream>

void Team::addMember(Transformer* member) {
    if (member) members_.push_back(member);
}

void Team::removeMember(Transformer* member) {
    auto it = std::remove(members_.begin(), members_.end(), member);
    members_.erase(it, members_.end());
}

void Team::showLevels() const {
    std::cout << "Team members levels:" << std::endl;
    for (auto m : members_) {
        if (m) std::cout << m->getLevel() << std::endl;
    }
}

