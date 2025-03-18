#pragma once
#include "Animal.h"

#define IDSHEEP 2

class Sheep : public Animal {
public:
    Sheep(positionXY position, World* wrld);
    Sheep(positionXY position, World* wrld, bool newBorn);
    void makeNew(positionXY position, World* wrld) override;
    string getName() override;
    void drawing() override;

    ~Sheep() {} // Destruktor             // Destructor declaration

    //void drawWorld(); // Function draws the map of the World

};