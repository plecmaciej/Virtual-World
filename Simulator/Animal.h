#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
    Animal(int strength, int iniciative, positionXY position, World* wrld, int id);
    Animal(int strength, int iniciative, positionXY position, World* wrld, int id, bool newBorn);
    virtual void drawing() = 0;  // Member function declaration
    virtual void action() override;
    virtual void colision(Organism* organism) override;
    virtual void move(positionXY position);
    virtual void makeNew(positionXY position, World* wrld) = 0;
    virtual void runAway() override;
    virtual ~Animal() {};               // Destructor declaration
};