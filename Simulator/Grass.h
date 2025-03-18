#pragma once
#include "Plant.h"

#define ID_GRASS 6

class Grass : public Plant {
public:
    Grass(positionXY position, World* wrld);
    Grass(positionXY position, World* wrld, bool newBorn);
    void makeNew(positionXY position, World* wrld) override;
    string getName() override;
    void drawing() override;
    virtual ~Grass() {} // Destruktor             // Destructor declaration
};