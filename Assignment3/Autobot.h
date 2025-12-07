#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"
#include "Minicon.h"
#include <string>

class Autobot : public Transformer {
public:
    Autobot();
    Autobot(uint level, uint strength, uint range, uint fuel, uint ammo, const std::string &color);
    ~Autobot();

    void setColor(const std::string &color);
    std::string getColor() const;

    bool protectHumans();

    void printClass() const override;
    void printAction() const override;

    Minicon& getMinicon();
    void setMiniconSpeed(unsigned int speed);

private:
    std::string _color;
    Minicon _minicon;
};

#endif

