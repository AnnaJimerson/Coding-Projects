#include "Character.h"

Character::Character(std::string name, int health, int mana, std::vector<UsableCommand*> commands,
	std::vector<UsableCommand*> inventory) :
	  m_name(name)
	, m_health(health)
	, m_mana(mana)
	, m_commands(commands)
	, m_inventory(inventory)
{

}

Character::~Character()
{
	// First delete all inventory pointers
	for (int i = 0; i < m_commands.size(); i++) {
		if(m_commands[i] != nullptr)
			delete m_commands[i];
	}
	for (int i = 0; i < m_inventory.size(); i++) {
		if (m_inventory[i] != nullptr)
			delete m_inventory[i];
	}

	// Then clear the arrays
	m_commands.clear();
	m_inventory.clear();
}

void Character::SetHealth(int health)
{
}

void Character::SetMana(int mana)
{
}

void Character::SetName(std::string name)
{
}

void Character::SetTarget(Character* target)
{
	m_target = target;
}
