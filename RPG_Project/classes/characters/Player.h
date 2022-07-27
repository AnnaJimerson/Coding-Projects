#pragma once
#include "Character.h"
class Player :
    public Character
{
private:

public:
    Player(std::string name, int health, int mana);
};

