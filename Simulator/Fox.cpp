#include "Fox.h"

Fox::Fox(positionXY position, World* wrld) : Animal(3, 7, position, wrld, IDFOX) {}
Fox::Fox(positionXY position, World* wrld, bool newBorn) : Animal(3, 7, position, wrld, IDFOX, newBorn) {}

void Fox::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN );
    cout << "F";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}
bool Fox::canSmell()
{
    return true;
}

void Fox::makeNew(positionXY position, World* wrld) {
    Fox* org = new Fox(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Fox::getName() {
    return "Fox";
}
