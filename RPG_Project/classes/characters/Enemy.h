#pragma once
#include "Character.h"
class Enemy :
    public Character
{
private:
    //Constructor
    Enemy(std::string name, int health, int mana);
public:
    // Event Functions
    virtual void CharacterTurnEvent();
};

