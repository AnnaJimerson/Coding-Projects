#pragma once
#include "Character.h"
class Enemy :
    public Character
{
private:

public:
    //Constructor
    Enemy(std::string name, int health, int mana);

    // Event Functions
    virtual void CharacterTurnEvent();
};

