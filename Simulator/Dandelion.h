#pragma once
#include "Plant.h"

#define ID_DANDELION 7

class Dandelion : public Plant {
public:
    Dandelion(positionXY position, World* wrld);
    Dandelion(positionXY position, World* wrld, bool newBorn);
    void action() override;
    void makeNew(positionXY position, World* wrld) override;
    string getName() override;
    void drawing() override;
    virtual ~Dandelion() {} // Destruktor             // Destructor declaration
};