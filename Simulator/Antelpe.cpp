#include "Antelope.h"

Antelope::Antelope(positionXY position, World* wrld) : Animal(4, 4, position, wrld, IDANTELOPE) {}
Antelope::Antelope(positionXY position, World* wrld, bool newBorn) : Animal(4, 4, position, wrld, IDANTELOPE, newBorn) {}

void Antelope::drawing() {
    setCursorPosition();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    cout << "A";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

bool Antelope::canRun() {
    return true;
}

void Antelope::makeNew(positionXY position, World* wrld) {
    Antelope* org = new Antelope(position, wrld, true);
    wrld->informPersonalEvent(getName(), position.x, position.y, INF_BORN);
}

string Antelope::getName() {
    return "Antelope";
}

positionXY Antelope::choosePlace() {
    positionXY currentPosition = getPosition();
    positionXY tmpPosition = Organism::choosePlace();
    bool accept = false, newPlace = false;
    int direction = 0;

    if (canRun()) {
        while (!newPlace) {
            while (!accept) {
                direction = randomNumberGen(1, 4);      // 1 - up, 2 - right, 3 - bottom, 4 - left
                accept = canMove(direction);
            }
            tmpPosition = actualizePosition(direction, tmpPosition);
            newPlace = !isPlaceTheSame(tmpPosition, currentPosition);
            accept = false;
        }
    }
    return tmpPosition;
}