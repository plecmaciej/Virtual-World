#pragma once
#include "Animal.h"

#define IDTURTLE 4

class Turtle : public Animal {
public:
    Turtle(positionXY position, World* wrld);
    Turtle(positionXY position, World* wrld, bool newBorn);
    string getName() override;
    void makeNew(positionXY position, World* wrld) override;
    void drawing() override;
    void action() override;
    bool canReturnBack() override;
    virtual ~Turtle() {}
};