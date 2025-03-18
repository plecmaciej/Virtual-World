#include "Nightshade.h"

Nightshade::Nightshade(positionXY position, World* wrld) : Plant(99, 0, position, wrld, ID_Nightshade) {}
Nightshade::Nightshade(positionXY position, World* wrld, bool newBorn) : Plant(99, 0, position, wrld, ID_Nightshade, newBorn) {}

void Nightshade::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "x";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void Nightshade::makeNew(positionXY position, World* wrld) {
    Nightshade* org = new Nightshade(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Nightshade::getName() {
    return "Nightshade";
}

bool Nightshade::isDeadly() {
    return true;
}