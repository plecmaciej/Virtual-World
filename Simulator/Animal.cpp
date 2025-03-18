#include "Animal.h"

Animal::Animal(int strength, int iniciative, positionXY position, World* wrld, int id) : Organism(strength, iniciative, position, wrld, id)
{

}

Animal::Animal(int strength, int iniciative, positionXY position, World* wrld, int id, bool newBorn) : Organism(strength, iniciative, position, wrld, id, newBorn)
{

}

void Animal::move(positionXY position) {
    getWorld()->removeFromWorld(this);
    setPosition(position);
    getWorld()->addToWorld(this);
}


void Animal::action() {
    if (getNewBorn() == true) {
        setIfNewBorn(false);
        return;
    }

    World* tmpWorld = getWorld();
    positionXY tmpPosition = choosePlace();

    if (isPlaceFree(tmpPosition)) {
        move(tmpPosition);
        this->getWorld()->informPersonalEvent(getName(), tmpPosition.x, tmpPosition.y, INF_MOVE);
    }
    else {
        if (this->canSmell() && tmpWorld->getOrganismFromTable(tmpPosition.x, tmpPosition.y)->getStrength() > getStrength()) {

            getWorld()->informPersonalEvent(getName(), tmpPosition.x, tmpPosition.y, INF_SMELL);
        }
        else colision(tmpWorld->getOrganismFromTable(tmpPosition.x, tmpPosition.y));
    }
}

void Animal::colision(Organism* organism) {
    positionXY prevPosition = organism->getPosition();
    if (getID() == organism->getID()) {
        reproduce();
    }
    
    else if (this->getStrength() < organism->getStrength()) {
        if (organism->isDeadly()) {
            // komunikat o zjedzeniu zatrutej roœliny 
            organism->kill();
            this->kill();
            return;
        }
        else if ((canRun() && randomNumberGen(0, 1) == 1) || isImmortal()) {
            runAway();
            return;
        }
        getWorld()->informMultiEvent(getName(), organism->getName(), prevPosition.x, prevPosition.y, INF_TRAP);
        this->kill();
        return;
    }
    else {
        if (organism->canReturnBack() && this->getStrength() < 5) {
            this->getWorld()->informMultiEvent(organism->getName(), getName(), prevPosition.x, prevPosition.y, INF_RETURN);
            return;
        }
        else if ((organism->canRun() && randomNumberGen(0, 1) == 1) || organism->isImmortal()) {
                organism->runAway();
                this->move(prevPosition);
                this->getWorld()->informPersonalEvent(organism->getName(), prevPosition.x, prevPosition.y, INF_AVOID);
                return;
        }
        if (organism->isBonus()) {
            setStrength(getStrength() + 3);
        }
        this->getWorld()->informMultiEvent(getName(), organism->getName(), prevPosition.x, prevPosition.y, INF_KILLED);
        organism->kill();
        move(prevPosition);
    }
}

void Animal::runAway() {
    for (int direction = 1; direction < 5; direction++) {
        if (canMove(direction) && isDirectionFree(direction)) {
            positionXY tmpPosition = actualizePosition(direction, getPosition());
            move(tmpPosition);
            getWorld()->informPersonalEvent(getName(), tmpPosition.x, tmpPosition.y, INF_AVOID);
            return;
        }
    }
}