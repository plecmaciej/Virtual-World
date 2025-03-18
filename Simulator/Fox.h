#pragma once
#include "Animal.h"

#define IDFOX 3

class Fox : public Animal {
public:
    Fox(positionXY position, World* wrld);
    Fox(positionXY position, World* wrld, bool newBorn);
    void makeNew(positionXY position, World* wrld) override;
    void drawing() override;
    string getName() override;
    bool canSmell() override;
    virtual ~Fox() {} // Destruktor             // Destructor declaration
};