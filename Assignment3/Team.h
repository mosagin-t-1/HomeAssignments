#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "Transformer.h"

class Team {
public:
    Team() = default;
    ~Team() = default;

    void addMember(Transformer* member);
    void removeMember(Transformer* member);
    void showLevels() const;
    size_t size() const { return members_.size(); }

private:
    std::vector<Transformer*> members_;
};

#endif

