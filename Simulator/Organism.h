#pragma once
#include "World.h"
#include <String.h>
using namespace std;

class World;

struct positionXY {
    int x;
    int y;
};



class Organism {
public:
    Organism(int strength, int iniciative, positionXY position, World* wrld, int id);
    Organism(int strength, int iniciative, positionXY position, World* wrld, int id, bool newBorn);

    virtual int randomNumberGen(int bottom, int top);
    virtual void action() = 0;
    virtual void colision(Organism* organism) = 0;
    virtual void drawing() = 0;
    virtual void makeNew(positionXY position, World* wrld) = 0;
    virtual void runAway() = 0;
    virtual void reproduce();
    virtual void setPosition(positionXY newPosition);
    virtual void kill();
    virtual positionXY actualizePosition(int direction, positionXY position);
    virtual positionXY choosePlace();

    bool getNewBorn() const;
    int getID() const;
    int getStrength() const;
    int getIniciative() const;
    World* getWorld() const;
    positionXY getPosition() const;
    virtual string getName() = 0;

    void setStrength(int newStrength);
    void setCursorPosition();
    void setIfNewBorn(bool newBorn);
    void setIniciative(int newIniciative);
    
    virtual bool canMove(int direction);
    virtual bool isPlaceTheSame(positionXY position1, positionXY position2);
    virtual bool isPlaceFree(positionXY position);
    virtual bool isDirectionFree(int direction);
    virtual bool isTheSame(positionXY position);

    virtual bool isDeadly();
    virtual bool canRun();
    virtual bool canSmell();
    virtual bool canReturnBack();
    virtual bool isBonus();
    virtual bool isImmortal();

    virtual ~Organism() {};               // Destructor declaration


private:
    int strength;
    int iniciative;
    positionXY position;
    int id;
    bool newBorn;
protected:
    World* wrld;
};





