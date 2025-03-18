#include "Organism.h"
#define RIGHT 2
#define LEFT 4
#define UP 1
#define BOTTOM 3


Organism::Organism(int strength, int iniciative, positionXY position, World* wrld, int id)
    : strength(strength), iniciative(iniciative), position(position), wrld(wrld), id(id) {
    this->wrld->addToWorld(this);
    this->wrld->addToLister(this);
}

Organism::Organism(int strength, int iniciative, positionXY position, World* wrld, int id, bool newBorn)
    : strength(strength), iniciative(iniciative), position(position), wrld(wrld), id(id), newBorn(newBorn) {
    this->wrld->addToWorld(this);
    this->wrld->addToLister(this);
}

int Organism::randomNumberGen(int bottom, int top) {
    std::random_device rd;
    std::mt19937 generator(rd());

    // Tworzenie obiektu rozk³adu równomiernego
    std::uniform_int_distribution<int> rozklad(bottom, top);

    // Generowanie losowej liczby
    int randomNumber = rozklad(generator);
    return randomNumber;
};

bool Organism::getNewBorn() const {
    return newBorn;
}

int Organism::getID() const{
    return id;
}

int Organism::getStrength() const {
    return strength;
}

int Organism::getIniciative() const {
    return iniciative;
}

positionXY Organism::getPosition() const {
    return position;
}

World* Organism::getWorld() const {
    return wrld;
}

void Organism::setStrength(int newStrength) {
    strength = newStrength;
}


void Organism::setIniciative(int newIniciative) {
    iniciative = newIniciative;
}


void Organism::setPosition(positionXY newPosition) {
    position = newPosition;
}

void Organism::setIfNewBorn(bool newBorn) {
    this->newBorn = false;
}

bool Organism::isDeadly() {
    return false;
}

bool Organism::isImmortal() {
    return false;
}

bool Organism::canRun() {
    return false;
}

bool Organism::canReturnBack() {
    return false;
}

bool Organism:: canSmell() {
    return false;
}

bool Organism::isBonus() {
    return false;
}

positionXY Organism::actualizePosition(int direction, positionXY position) {
    if (direction == UP)
    {
        position.y = position.y - 1;
    }
    else if (direction == RIGHT)
    {
        position.x = position.x + 1;
    }
    else if (direction == BOTTOM)
    {
        position.y = position.y + 1;
    }
    else if (direction == LEFT)
    {
        position.x = position.x - 1;
    }
    return position;
}

void Organism::reproduce() {
    for (int direction = 1; direction < 5; direction++) {
        if (canMove(direction) && isDirectionFree(direction)) {
            makeNew(actualizePosition(direction, getPosition()), getWorld());
            return;
        }
    }
}

positionXY Organism::choosePlace() {
    int direction = 0;
    bool accept = false;

    while (!accept) {
        direction = randomNumberGen(1, 4);      // 1 - up, 2 - right, 3 - bottom, 4 - left
        accept = canMove(direction);
    }

    return actualizePosition(direction, getPosition());
}


void Organism::kill() {
    getWorld()->deleteFromWorld(this);
}

bool Organism::isPlaceTheSame(positionXY position1, positionXY position2) {
    if (position1.x == position2.x && position1.y == position2.y) return true;
    return false;
}

bool Organism::isPlaceFree(positionXY position) {
    if (getWorld()->isSpaceFree(position.x, position.y)) return true;
    else return false;
}

bool Organism::isDirectionFree(int direction) {
    positionXY tmpPosition = getPosition();
    if (direction == UP) {
        tmpPosition.y--;
    }
    else if (direction == BOTTOM) {
        tmpPosition.y++;
    }
    else if (direction == RIGHT) {
        tmpPosition.x++;
    }
    else {
        tmpPosition.x--;
    }
    return isPlaceFree(tmpPosition);
}

bool Organism::isTheSame(positionXY position) {
    if (getWorld()->getIdFromOrganisms(position.x, position.y) == getID()) return true;
    else return false;

}

bool Organism::canMove(int direction) {
    if (direction % 2 == 1) {
        if (direction == UP && getPosition().y > 0) return true;
        else if (direction == BOTTOM && getPosition().y < (getWorld()->getWorldHight())-1) return true;
        else return false;
    }
    else {
        if (direction == LEFT && getPosition().x > 0) return true;
        else if (direction == RIGHT && getPosition().x < (getWorld()->getWorldWidth())-1) return true;
        else return false;
    }
}

void Organism::setCursorPosition() {
    COORD coord;
    coord.X = 2*this->position.x+1;
    coord.Y = this->position.y+1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};