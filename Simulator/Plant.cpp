#include "Plant.h"

Plant::Plant(int strength, int iniciative, positionXY position, World* wrld, int id) : Organism(strength, iniciative, position, wrld, id)
{

}

Plant::Plant(int strength, int iniciative, positionXY position, World* wrld, int id, bool newBorn) : Organism(strength, iniciative, position, wrld, id, newBorn)
{

}

void Plant::seed(positionXY position) {
    makeNew(position, getWorld());
}

void Plant::action()
{
    if (getNewBorn() == true) {
        setIfNewBorn(false);
        return;
    }

    World* tmpWorld = getWorld();
    positionXY tmpPosition = choosePlace();

    if (randomNumberGen(1, 3) == 2) {

        if (isPlaceFree(tmpPosition)) {
            seed(tmpPosition);
            //this->getWorld()->informChangePosition(getName(), tmpPosition.x, tmpPosition.y);
        }
        else {
            colision(tmpWorld->getOrganismFromTable(tmpPosition.x, tmpPosition.y));
        }
    }
}

void Plant::colision(Organism* organism) {
    positionXY prevPosition = organism->getPosition();

    
    if (this->getStrength() < organism->getStrength()) {
        return;
    }
    else {
        if (isDeadly()) {
            organism->kill();
            seed(prevPosition);
        }
    }
}