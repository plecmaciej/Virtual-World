#pragma once
#include <windows.h>
#include <iostream>
#include <random>
#include <vector>
#include "Organism.h"

class Organism;

#define INF_BORN 1
#define INF_SMELL 2
#define INF_KILLED 3
#define INF_MOVE 4
#define INF_TRAP 5
#define INF_RETURN 6
#define INF_AVOID 7
#define INF_EATDEAD 8
#define INF_EATBONUS 9

using namespace std;

class World {
public:
    World();   
    World(int width, int hight);
    void takeTurn();
    void displayMessage(); 
    int getWorldHight();
    int getWorldWidth();
    int getWorldRound();
    int getHumanDirection();
    int getLastUse();
    bool getActive();
    bool getAlive();
    int getIdFromOrganisms(int x, int y);
    Organism* getOrganismFromTable(int x, int y);
    void setWorldWidth(int newWidth);
    void setWorldHight(int newHight);
    void setWorldRound(int newRound);
    void setHumanDirection(int newDirection);
    void setLastUse(int newLastUse);
    void setActive( bool active);
    void setAlive(bool alive);
    void setWorldSize(int newWidth, int newHight);

    ~World();
    void activeSuperpower();
    void drawWorld(); 
    void addToLister(Organism* organism);
    void addToWorld(Organism* organism);
    void removeFromWorld(Organism* organism);
    void deleteFromWorld(Organism* organism);
    void deleteFromLister(Organism* organism);
    int chooseLister(Organism* organism);
    bool isSpaceFree(int x, int y);

    void informPersonalEvent(string name, int x, int y, int code);
    void informMultiEvent(string name, string otherName, int x, int y, int code);

    void drawLegend();
    
    void saveWorld();
    void loadWorld();

private:
    int hight;
    int width;
    int round;
    int lastUse;
    int humanDirection;
    bool isActive;
    bool isAlive;
    void privateFunction();
    vector <Organism*> lister[5];
    Organism** organisms;
};


