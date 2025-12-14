#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon : public Transformer {
public:
    Decepticon();
    Decepticon(uint level, uint strength, uint range, uint fuel, uint ammo, uint weaponPower);
    ~Decepticon();

    void setWeaponPower(uint power);
    uint getWeaponPower() const;

    bool attack();

    void printClass() const override;
    void printAction() const override;

private:
    uint _weaponPower;
};

#endif

