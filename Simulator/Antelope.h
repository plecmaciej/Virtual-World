#pragma once
#include "Animal.h"
#include <random>

#define IDANTELOPE 5

class Antelope : public Animal {
public:
    Antelope(positionXY position, World* wrld);
    Antelope(positionXY position, World* wrld, bool newBorn);
    void makeNew(positionXY position, World* wrld) override;
    void drawing() override;
    string getName() override;
    bool canRun() override;
    positionXY choosePlace() override;
    virtual ~Antelope() {} // Destruktor             // Destructor declaration
};