#include "Sheep.h"
#include <windows.h>
#include <iostream>

Sheep::Sheep(positionXY position, World* wrld) : Animal(4, 4, position, wrld, IDSHEEP) {}
Sheep::Sheep(positionXY position, World* wrld, bool newBorn) : Animal(4, 4, position, wrld, IDSHEEP, newBorn) {}

void Sheep::drawing() {
    setCursorPosition();
    cout << "S";

}

void Sheep::makeNew(positionXY position, World* wrld) {
    Sheep* org = new Sheep(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Sheep::getName() {
    return "Sheep";
}