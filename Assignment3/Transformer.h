#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>

typedef unsigned int uint;

class Transformer {
public:
    Transformer();
    virtual ~Transformer();

    bool move();
    bool fire();
    bool transform();

    void setLevel(uint level);
    uint getLevel() const;

    void setStrength(uint strength);
    uint getStrength() const;

    void setRange(uint range);
    uint getRange() const;

    void setFuel(uint fuel);
    uint getFuel() const;

    void setAmmo(uint ammo);
    uint getAmmo() const;

protected:
    uint _level;
    uint _strength;
    uint _range;
    uint _fuel;
    uint _ammo;
};

#endif

