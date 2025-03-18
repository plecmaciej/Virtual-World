#include "Guarana.h"

Guarana::Guarana(positionXY position, World* wrld) : Plant(0, 0, position, wrld, ID_GUARANA) {}
Guarana::Guarana(positionXY position, World* wrld, bool newBorn) : Plant(0, 0, position, wrld, ID_GUARANA, newBorn) {}

void Guarana::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
    cout << "*";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void Guarana::makeNew(positionXY position, World* wrld) {
    Guarana* org = new Guarana(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Guarana::getName() {
    return "Guarana";
}

bool Guarana::isBonus() {
    return true;
}