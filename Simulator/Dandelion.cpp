#include "Dandelion.h"

Dandelion::Dandelion(positionXY position, World* wrld) : Plant(0, 0, position, wrld, ID_DANDELION) {}
Dandelion::Dandelion(positionXY position, World* wrld, bool newBorn) : Plant(0, 0, position, wrld, ID_DANDELION, newBorn) {}

void Dandelion::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "D";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void Dandelion::action() {
    Plant::action();
    Plant::action();
    Plant::action();
}

void Dandelion::makeNew(positionXY position, World* wrld) {
    Dandelion* org = new Dandelion(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Dandelion::getName() {
    return "Dandelion";
}