#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"

class Autobot : public Transformer {
public:
    Autobot();
    ~Autobot();

    void setColor(const std::string &color);
    std::string getColor() const;

    bool protectHumans();

private:
    std::string _color;
};

#endif
