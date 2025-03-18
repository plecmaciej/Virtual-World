#include "Human.h"
#include <conio.h>

Human::Human(positionXY position, World* wrld) : Animal(3, 7, position, wrld, IDHUMAN) {}
Human::Human(positionXY position, World* wrld, bool newBorn) : Animal(3, 7, position, wrld, IDHUMAN, newBorn) {}

void Human::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "H";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void Human::action() {
    if (getNewBorn() == true) {
        setIfNewBorn(false);
        return;
    }

    positionXY tmpPosition = getPosition();
    int direction = getWorld()->getHumanDirection();

    if (canMove(direction)) {
        tmpPosition = actualizePosition(direction, tmpPosition);
    }

    World* tmpWorld = getWorld();

    if (isPlaceFree(tmpPosition)) {
        move(tmpPosition);
        this->getWorld()->informPersonalEvent(getName(), tmpPosition.x, tmpPosition.y, INF_MOVE);
    }
    else {
        colision(tmpWorld->getOrganismFromTable(tmpPosition.x, tmpPosition.y));
    }
}

bool Human::isImmortal() {
    if (getWorld()->getActive()) {
        return true;
    }
    else return false;
}

void Human::makeNew(positionXY position, World* wrld) {
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Human::getName() {
    return "Human";
}
