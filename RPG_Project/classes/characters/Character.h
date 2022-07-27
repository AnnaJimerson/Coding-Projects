#pragma once
#include <vector>
#include <string>
#include "../inventory/UsableCommand.h"

class Character
{
private:
	int m_maxHealth = 90;
	int m_maxMana = 90;

	int m_health = m_maxHealth;
	int m_mana = m_maxMana;

	int m_attackBns = 0;
	int m_defenseBns = 0;

	std::string m_name = "Character";

	std::vector<UsableCommand*> m_commands;
	std::vector<UsableCommand*> m_inventory;

	Character* m_target = nullptr;

public:
	//Constructor
	Character(std::string name, int health, int mana);

	// Destructor
	virtual ~Character();

	// Health Functions
	int const GetHealth() const { return m_health; }
	void SetHealth(int health);

	// Mana Functions
	int const GetMana() const { return m_mana; }
	void SetMana(int health);

	// Character Name Functions
	std::string const GetName() const { return m_name; }
	void SetName(std::string name);

	// Character Attack/Def Bonus Functions
	int const GetAttackBonus() const { return m_attackBns; }
	void SetAttackBonus(int attackBns);
	int const GetDefenseBonus() const { return m_defenseBns; }
	void SetDefenseBonus(int defenseBns);

	// Character Target Functions
	Character* GetTarget() { return m_target; }
	void SetTarget(Character* target);

	// Event Functions
	virtual void OnCharacterTurnEvent();

	// Inventory / Command Array functions
	std::vector<UsableCommand*>& GetCommands () { return m_commands; }
	std::vector<UsableCommand*>& GetInventory() { return m_inventory; }
};

