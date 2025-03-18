#include "Sosnowski.h"

Sosnowski::Sosnowski(positionXY position, World* wrld) : Plant(10, 0, position, wrld, ID_Sosnowski) {}
Sosnowski::Sosnowski(positionXY position, World* wrld, bool newBorn) : Plant(10, 0, position, wrld, ID_Sosnowski, newBorn) {}

void Sosnowski::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "o";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void Sosnowski::makeNew(positionXY position, World* wrld) {
    Sosnowski* org = new Sosnowski(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Sosnowski::getName() {
    return "Sosnowski";
}

bool Sosnowski::isDeadly() {
    return true;
}