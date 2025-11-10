#ifndef MINICON_H
#define MINICON_H

#include "Transformer.h"

class Minicon : public Transformer {
public:
    Minicon();
    ~Minicon();

    void setSpeed(uint speed);
    uint getSpeed() const;

    bool assist();

private:
    uint _speed;
};

#endif
