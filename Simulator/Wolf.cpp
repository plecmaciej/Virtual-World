#include "Wolf.h"
#include <windows.h>
#include <iostream>

Wolf::Wolf(positionXY position, World* wrld) : Animal(9, 5, position, wrld, 1) {}
Wolf::Wolf(positionXY position, World* wrld, bool newBorn) : Animal(9, 5, position, wrld, 1, newBorn) {}

void Wolf::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    cout << "W";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void Wolf::makeNew(positionXY position, World* wrld) {
    Wolf* org = new Wolf(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Wolf::getName() {
    return "Wolf";
}