// RPG_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vld.h"
#include "classes/characters/Character.h"

int main()
{
    // Set random seed
    srand(time(0));

    // Spawn Characters
    Character* myChar = new Character("Hero", 90, 90);

    delete myChar;
}
