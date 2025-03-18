#pragma once
#include <windows.h>
#include <iostream>
#include <random>

void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

int randomNumberGen(int bottom, int top) {
    std::random_device rd;
    std::mt19937 generator(rd());

    // Tworzenie obiektu rozk³adu równomiernego
    std::uniform_int_distribution<int> rozklad(bottom, top);

    // Generowanie losowej liczby
    int randomNumber = rozklad(generator);
    return randomNumber;
};