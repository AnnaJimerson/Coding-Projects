#pragma once
#include <vector>
#include "../inventory/UsableCommand.h"

class Character
{
private:
	int maxHealth = 90;
	int maxMana = 90;

	int health = maxHealth;
	int mana = maxMana;

	std::vector<UsableCommand*> commands;
	std::vector<UsableCommand*> inventory;

public:
	//Constructor
	Character(int in_health, int in_mana, std::vector<UsableCommand*> in_commands, std::vector<UsableCommand*> in_inventory);

	// Get Functions
	int getHealth() { return health; }
	int getMana() { return mana; }
	std::vector<UsableCommand*>& getCommands () { return commands; }
	std::vector<UsableCommand*>& getInventory() { return inventory; }
	
	//Set Functions
	void setHealth(int in_health);
	void setMana(int in_mana);
};

