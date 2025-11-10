#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon : public Transformer {
public:
    Decepticon();
    ~Decepticon();

    void setWeaponPower(uint power);
    uint getWeaponPower() const;

    bool attack();

private:
    uint _weaponPower;
};

#endif
