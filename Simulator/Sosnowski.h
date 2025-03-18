#pragma once
#include "Plant.h"

#define ID_Sosnowski 10

class Sosnowski : public Plant {
public:
    Sosnowski(positionXY position, World* wrld);
    Sosnowski(positionXY position, World* wrld, bool newBorn);
    void makeNew(positionXY position, World* wrld) override;
    string getName() override;
    bool isDeadly() override;
    void drawing() override;
    virtual ~Sosnowski() {} // Destruktor             // Destructor declaration
};