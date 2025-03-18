#include "Grass.h"

Grass::Grass(positionXY position, World* wrld) : Plant(0, 0, position, wrld, ID_GRASS) {}
Grass::Grass(positionXY position, World* wrld, bool newBorn) : Plant(0, 0, position, wrld, ID_GRASS, newBorn) {}

void Grass::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    cout << "G";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void Grass::makeNew(positionXY position, World* wrld) {
    Grass* org = new Grass(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Grass::getName() {
    return "Grass";
}