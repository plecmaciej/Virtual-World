#include "Turtle.h"

Turtle::Turtle(positionXY position, World* wrld) : Animal(2, 1, position, wrld, IDTURTLE) {}
Turtle::Turtle(positionXY position, World* wrld, bool newBorn) : Animal(2, 1, position, wrld, IDTURTLE, newBorn) {}

void Turtle::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "T";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

bool Turtle::canReturnBack() {
    return true;
}
void Turtle::action() {
    if (canReturnBack() && randomNumberGen(1, 4) != 2) return;
    Animal::action();

}

void Turtle::makeNew(positionXY position, World* wrld) {
    Turtle* org = new Turtle(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Turtle::getName() {
    return "Turtle";
}