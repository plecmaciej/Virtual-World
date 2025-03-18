#include <iostream>
#include <conio.h>
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Human.h"
#include "Nightshade.h"
#include "Sosnowski.h"

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

int randomidGen2(int bottom, int top) {
	std::random_device rd;
	std::mt19937 generator(rd());

	// Tworzenie obiektu rozk³adu równomiernego
	std::uniform_int_distribution<int> rozklad(bottom, top);

	// Generowanie losowej liczby
	int randomid = rozklad(generator);
	return randomid;
};



void setCursorVisibility(bool visible) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

using namespace std;

int main() {

	//World newWorld;
	int width = 20, hight = 20;
	cout << "PODAJ ROZMIAR PLANSZY:" << endl;
	cout << "SZEROKOSC:" << endl;
	cin >> width;
	cout << "WYSOKOSC:" << endl;
	cin >> hight;
	system("cls");
	World newWorld(width, hight);

	newWorld.drawWorld();


	positionXY humanPosition = { width/2, hight-2 };
	positionXY randomPos;
	

	setCursorVisibility(false);

	Organism* org = nullptr;

	int iterations = width * hight / 9;

	for (int i = 0; i < iterations; i++) {
		int id = randomidGen2(1,10);
		int randomX = randomidGen2(0, width-1);
		int randomY = randomidGen2(0, hight-1);
		randomPos.x = randomX;
		randomPos.y = randomY;

		if (id == 1 && randomidGen2(0,1) == 1 ) {
			org = new Sosnowski(randomPos, &newWorld);
		}
		else if (id == 2 && randomidGen2(0, 1) == 1) {
			org = new Nightshade(randomPos, &newWorld);
		}
		else if (id == 3) {
			org = new Guarana(randomPos, &newWorld);
		}
		else if (id == 4 && randomidGen2(0, 1) == 1) {
			org = new Dandelion(randomPos, &newWorld);
		}
		else if (id == 5) {
			org = new Grass(randomPos, &newWorld);
		}
		else if (id == 6) {
			org = new Turtle(randomPos, &newWorld);
		}
		else if (id == 7) {
			org = new Fox(randomPos, &newWorld);
		}
		else if (id == 8) {
			org = new Wolf(randomPos, &newWorld, true);
		}
		else if (id == 9) {
			org = new Sheep(randomPos, &newWorld);
		}
		else if (id == 10) {
			org = new Sheep(randomPos, &newWorld);
		}
		else if (id == 11) {
			org = new Antelope(randomPos, &newWorld);
		}

		org->drawing();

	}

	int randomX = randomidGen2(0, width - 1);
	int randomY = randomidGen2(0, hight - 1);
	randomPos.x = randomX;
	randomPos.y = randomY;

	org = new Human(randomPos, &newWorld);
	org->drawing();

	char key = 0;

	while (key != 'q') {
		key = _getch();

		if (key == 'p') {
			newWorld.saveWorld();
		}
		else if (key == 'l') {
			newWorld.loadWorld();
		}
		else if (key == 'm') {
			newWorld.activeSuperpower();
		}
		else {
			if (key == 'w') {
				newWorld.setHumanDirection(UP);

			}
			else if (key == 'a') {
				newWorld.setHumanDirection(LEFT);

			}
			else if (key == 's') {
				newWorld.setHumanDirection(DOWN);

			}
			else if (key == 'd') {
				newWorld.setHumanDirection(RIGHT);

			}
			newWorld.takeTurn();
			newWorld.drawWorld();
		}
	}

	setCursorVisibility(true);
	COORD coord;
	coord.X = 2;
	coord.Y = 26;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
