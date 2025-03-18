#pragma once
#include "Animal.h"

#define IDWOLF 1

class Wolf : public Animal {
public:
    Wolf(positionXY position, World* wrld);
    Wolf(positionXY position, World* wrld, bool newBorn);
    string getName() override;
    void makeNew(positionXY position, World* wrld) override;
    void drawing() override;
    virtual ~Wolf() {} // Destruktor             // Destructor declaration

    //void drawWorld(); // Function draws the map of the World

};