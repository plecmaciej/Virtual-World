#include "World.h"
#include <stdio.h>
#include <string>
#include <fstream>
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


World::World() {
    width = 20;
    hight = 20;
    round = 0;
    lastUse = -5;
    humanDirection = 0;
    isActive = false;
    isAlive = true;

    this->organisms = new Organism * [20 * 20];

    for (int i = 0; i < 20 * 20; i++)
    {
        organisms[i] = nullptr;
    }
}

World::World(int Width, int Hight) {
    this->width = Width;
    this->hight = Hight;
    setWorldWidth(Width);
    setWorldHight(Hight);
    this->round = 0;
    lastUse = -5;
    humanDirection = 0;
    isActive = false;
    isAlive = true;
    this->organisms = new Organism * [Width * Hight];

    for (int i = 0; i < Width * Hight; i++)
    {
        organisms[i] = nullptr;
    }
}


// Member function definition
void World::displayMessage() {
    cout << "Hello from MyClass!" << endl;
}

int World::getWorldHight() {
    return hight;
}

int World::getWorldWidth() {
    return width;
}

int World::getWorldRound() {
    return round;
}

int World::getHumanDirection() {
    return humanDirection;
}

int World::getLastUse() {
    return lastUse;
}

bool World::getAlive() {
    return isAlive;
}

bool World::getActive() {
    return isActive;
}

Organism* World::getOrganismFromTable(int x, int y) {
    return this->organisms[getWorldWidth() * y + x];
}

void World::setWorldWidth(int newWidth) {
    width = newWidth;
}

void World::setWorldHight(int newHight) {
    hight = newHight;
}

void World::setWorldRound(int newRound) {
    round = newRound;
}

void World::setHumanDirection(int newDirection) {
    humanDirection = newDirection;
}

void World::setLastUse(int newLastUse) {
    lastUse = newLastUse;
}

void World::setAlive(bool alive) {
    isAlive = alive;
}

void World::setActive(bool active) {
    isActive = active;
}

void World::setWorldSize(int newWidth, int newHight) {
    setWorldWidth(newWidth);
    setWorldHight(newHight);
}


// Private member function definition
void World::privateFunction() {
    cout << "This is a private function." << endl;
}

void World::activeSuperpower() {
    if (isAlive && !isActive && (10 - (round - lastUse)) <= 0) {
        setActive(true);
        setLastUse(round);
    }
}

void World::drawWorld() {
    
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    cout << "+";
    for (int i = 0; i < (width); i++) {
        cout << "-+";
    }

    cout << endl;
    for (int j = 0; j < hight; j++) {
        for (int i = 0; i < width; i++) {
            cout << "| ";
        }
        cout << "| " << j << endl;
    }

    cout << "+";
    for (int i = 0; i < (width); i++) {
        cout << "-+";
    }
    cout << endl;



    for (int i = 0; i < width * hight; i++)
    {
        if (organisms[i] != nullptr) {
            organisms[i]->drawing();
        }
    }
    drawLegend();
}
int World::chooseLister(Organism* organism) {
    int i = organism->getIniciative();
    if (i < 2)
    {
        return i;
    }
    else if (i == 5)
    {
        return 3;
    }
    else if (i == 7)
    {
        return 4;
    }
    else
    {
        return 2;
    }
}

void World::drawLegend() {
    COORD coord;
    
    coord.X = 2*getWorldWidth() + 10;
    
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "author - Maciej Plec";
    coord.Y ++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "W - Wolf";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "S - Sheep";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN );
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "F - Fox";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "T - Turtle";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "A - Antelope";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "G - Grass";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "D - Dandelion";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "* - Guarana";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "x - Nightshade";
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "o - Sosonowski";
    coord.Y++;
    coord.Y++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "Round: " << getWorldRound() ;
    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    if (isAlive) {
        if (!isActive) {
            if (round - lastUse > 10) cout << "Superpower can be used          ";
            else cout << "Your cooldown last only for : " << 10 - (round - lastUse) << "          ";
        }
        else {
            cout << "SuperPower is active for : " << 5 - (round - lastUse) << "        ";
        }
    }
    else cout << "Human is dead           ";

    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "Press 'L' to load the game";
    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "Press 'P' to save the game";
    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "Press 'Q' to quit the game";
    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "Use 'WASD' to move";
    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "Use 'M' to use immmortality";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void World::addToLister(Organism* organism) {

    lister[chooseLister(organism)].push_back(organism);
}

void World::addToWorld(Organism* organism) {
    positionXY tmpPosition = organism->getPosition();
    this->organisms[getWorldWidth()*tmpPosition.y + tmpPosition.x] = organism;
    //addToLister(organism);
}
void World::deleteFromLister(Organism* organism) {
    int tmpId = chooseLister(organism);
    for (auto it = lister[tmpId].begin(); it != lister[tmpId].end(); ++it) {
        if ((*it)->getPosition().x == organism->getPosition().x && (*it)->getPosition().y == organism->getPosition().y) {
            delete* it;
            lister[tmpId].erase(it);
            break; // Jeœli znajdziesz tylko jeden organizm o takiej pozycji, mo¿esz przerwaæ pêtlê
        }
    }
}

void World::removeFromWorld(Organism* organism) {
    positionXY tmpPosition = organism->getPosition();
    this->organisms[getWorldWidth() * tmpPosition.y + tmpPosition.x] = nullptr;

}

void World::deleteFromWorld(Organism* organism) {
    removeFromWorld(organism);
    deleteFromLister(organism);
}

bool World::isSpaceFree(int x, int y) {
    if (this->organisms[getWorldWidth() * y + x] == nullptr) {
        return true;
    }
    else return false;
}

int World::getIdFromOrganisms(int x, int y) {
    return this->organisms[getWorldWidth() * y + x]->getID();
}

void World::informPersonalEvent(string name, int x, int y , int code) {
    COORD coord;
    coord.X = 0;
    if (getWorldHight() > 20)
        coord.Y = getWorldHight() + 3;
    else coord.Y = 23;
    string x_str = to_string(x);
    string y_str = to_string(y);
    string massage = "none";

    if (code == INF_BORN) {
        massage = "New " + name + " is on the position: (" + x_str + ":" + y_str + ")        ";
    }
    else if (code == INF_SMELL) {
        coord.Y += 1;
        massage = name + " smells stronger enemy on the position: (" + x_str + ":" + y_str + "), and is not moving       ";
    }
    else if (code == INF_MOVE) {
        coord.Y = coord.Y + 2;
        massage = name + " moved on the position : (" + x_str + ":" + y_str + ")         ";
    }
    else if (code == INF_AVOID) {
        coord.Y = coord.Y + 3;
        massage = name + " is running from fight on the position : (" + x_str + ":" + y_str + ")         ";
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << massage;
}


void World::informMultiEvent(string name, string otherName, int x, int y, int code) {
    COORD coord;
    coord.X = 0;
    if (getWorldHight() > 20)
        coord.Y = getWorldHight() + 7;
    else coord.Y = 27;
    string x_str = to_string(x);
    string y_str = to_string(y);
    string massage = "none";

    if (code == INF_KILLED) {
        massage = otherName + " was killed by " + name + " on the position : (" + x_str + ":" + y_str + ")          ";
    }
    else if (code == INF_TRAP) {
        coord.Y = coord.Y + 1;
        massage = name + " was caught in trap by " + otherName + " on the position : (" + x_str + ":" + y_str + ")         ";
    }
    else if (code == INF_RETURN) {
        coord.Y = coord.Y + 2;
        massage = otherName + " was send back by " + name + " on the position : (" + x_str + ":" + y_str + ")         ";
    }
    else if (code == INF_EATDEAD) {
        coord.Y = coord.Y + 3;
        massage = name + " ate deadly" + otherName + " at the position : (" + x_str + ":" + y_str + ")            ";
    }
    else if (code == INF_EATBONUS) {
        coord.Y = coord.Y + 4;
        massage = name + " ate bonus" + otherName + " at the position : (" + x_str + ":" + y_str + ")           ";
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << massage;
}

void World::takeTurn() {
    for (int i = 5 - 1; i >= 0; i--)
    {
        int j = 0;
        while (j < lister[i].size()){
            lister[i][j]->action();
            j++;
            //drawWorld();
            //char key = getchar();
        }
    }
    drawWorld();
    setWorldRound(getWorldRound() + 1);
    if (isActive && (round - lastUse) > 5) setActive(false);
}

void World::saveWorld() {
    ofstream plik("save.txt");

    
    if (plik.is_open()) {

        plik << getWorldWidth() << " " << getWorldHight() << " " << getWorldRound() << " ";
        plik << getHumanDirection() << " " << getLastUse() << " " << getAlive() << " " << getActive() << std::endl;

            for (int j = 5 - 1; j >= 0; j--)
            {
                int k = 0;
                while (k < lister[j].size()) {
                    if (lister[j][k]->getID() == 11) cout << lister[j][k]->getStrength();
                    plik << lister[j][k]->getID() << " " << lister[j][k]->getStrength() << " ";
                    plik << lister[j][k]->getIniciative() << " " << lister[j][k]->getNewBorn() << " ";
                    plik << (lister[j][k]->getPosition()).x << " " << (lister[j][k]->getPosition()).y << "\n";
                    k++;
                    
                }
            }
        plik << "...";
        plik.close();

    }
    else {
        std::cerr << "Blad podczas otwierania pliku!" << std::endl;
    }

}

void World::loadWorld() {
    std::ifstream plik("save.txt");

    for (int i = 0; i < width * hight; i++) {
        delete organisms[i];
    }

    lister[0].clear();
    lister[1].clear();
    lister[2].clear();
    lister[3].clear();
    lister[4].clear();

    if (plik.is_open()) {

        int id, strength, iniciative, newBorn, posX, posY;
        positionXY position;
        std::string dane;

        plik >> dane;
        setWorldWidth(stoi(dane));
        plik >> dane;
        setWorldHight(stoi(dane));
        plik >> dane;
        setWorldRound(stoi(dane));
        plik >> dane;
        setHumanDirection(stoi(dane));
        plik >> dane;
        setLastUse(stoi(dane));
        plik >> dane;
        setAlive(stoi(dane));
        plik >> dane;
        setActive(stoi(dane));

        this->organisms = new Organism * [getWorldWidth() * getWorldHight()];

        for (int i = 0; i < getWorldWidth() * getWorldHight(); i++)
        {
            organisms[i] = nullptr;
        }

        Organism* org = nullptr;
        
        while (true) {
            plik >> dane;
            if (dane == "...") break;

            id = stoi(dane);
            plik >> dane;
            strength = stoi(dane);
            plik >> dane;
            iniciative = stoi(dane);
            plik >> dane;
            newBorn = stoi(dane);
            plik >> dane;
            posX = stoi(dane);
            plik >> dane;
            posY = stoi(dane);

            
            position.x = posX;
            position.y = posY;


            if (id == IDFOX) {
                org = new Fox(position, this, newBorn);
            }
            else if (id == IDWOLF) {
                org = new Wolf(position, this, newBorn);
            }
            else if (id == IDSHEEP) {
                org = new Sheep(position, this, newBorn);
            }
            else if (id == IDHUMAN) {
                org = new Human(position, this, newBorn);
            }
            else if (id == ID_DANDELION) {
                org = new Dandelion(position, this, newBorn);
            }
            else if (id == ID_GRASS) {
                org = new Grass(position, this, newBorn);
            }
            else if (id == IDTURTLE) {
                org = new Turtle(position, this, newBorn);
            }
            else if (id == IDANTELOPE) {
                org = new Antelope(position, this, newBorn);
            }
            else if (id == ID_GUARANA) {
                org = new Guarana(position, this, newBorn);
            }
            else if (id == ID_Nightshade) {
                org = new Nightshade(position, this, newBorn);
            }

            if (org != nullptr) {
                org->setStrength(strength);
                org->setIniciative(iniciative);
            }
        }
            system("cls");
            this->drawWorld();
            //this->takeTurn();
        
        plik.close();
    }
    else {
        std::cerr << "Blad podczas otwierania pliku!" << std::endl;
    }
}


World::~World() {
    if (organisms != nullptr)
    {
        for (int i = 0; i < hight * width; i++)
        {
            if (organisms[i] != nullptr)
                delete organisms[i];
        }
        delete[] organisms;
    }
    for (int i = 0; i < 5; i++)
        this->lister[i].clear();
}