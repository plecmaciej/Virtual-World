#pragma once
#include "Animal.h"

#define IDHUMAN 11

class Human : public Animal {
public:
    Human(positionXY position, World* wrld);
    Human(positionXY position, World* wrld, bool newBorn);
    void makeNew(positionXY position, World* wrld) override;
    void drawing() override;
    void action() override;
    bool isImmortal() override;
    string getName() override;
    virtual ~Human() {} // Destruktor             // Destructor declaration
private:
    int lastRound = 0;
};