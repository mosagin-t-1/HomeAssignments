#ifndef MINICON_H
#define MINICON_H

#include "Transformer.h"

class Minicon : public Transformer {
public:
    Minicon();
    Minicon(uint level, uint strength, uint range, uint fuel, uint ammo, uint speed);
    ~Minicon();

    void setSpeed(uint speed);
    uint getSpeed() const;

    bool assist();

    void printClass() const override;
    void printAction() const override;

private:
    uint _speed;
};

#endif
