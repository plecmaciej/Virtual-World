#pragma once
#include "Plant.h"

#define ID_Nightshade 9

class Nightshade : public Plant {
public:
    Nightshade(positionXY position, World* wrld);
    Nightshade(positionXY position, World* wrld, bool newBorn);
    void makeNew(positionXY position, World* wrld) override;
    string getName() override;
    bool isDeadly() override;
    void drawing() override;
    virtual ~Nightshade() {} // Destruktor             // Destructor declaration
};