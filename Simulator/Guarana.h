#pragma once
#include "Plant.h"

#define ID_GUARANA 8

class Guarana : public Plant {
public:
    Guarana(positionXY position, World* wrld);
    Guarana(positionXY position, World* wrld, bool newBorn);
    bool isBonus() override;
    void makeNew(positionXY position, World* wrld) override;
    string getName() override;
    void drawing() override;
    virtual ~Guarana() {} // Destruktor             // Destructor declaration
};