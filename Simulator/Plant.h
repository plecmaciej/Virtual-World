#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
    Plant(int strength, int iniciative, positionXY position, World* wrld, int id);
    Plant(int strength, int iniciative, positionXY position, World* wrld, int id, bool newBorn);
    virtual void drawing() = 0;
    virtual void runAway() {};
    virtual void action() override;
    virtual void seed(positionXY position);
    virtual void colision(Organism* organism) override;
    virtual void makeNew(positionXY position, World* wrld) = 0;
    virtual ~Plant() {};               // Destructor declaration
};