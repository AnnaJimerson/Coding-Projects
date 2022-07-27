#include "Character.h"

Character::Character(std::string name, int health, int mana) :
	  m_name(name)
	, m_health(health)
	, m_mana(mana)
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
{ m_health = health; }

void Character::SetMana(int mana) 
{ m_mana = mana; }

void Character::SetName(std::string name) 
{ m_name = name; }

void Character::SetAttackBonus(int attackBns)
{ m_attackBns = attackBns; }

void Character::SetDefenseBonus(int defenseBns)
{ m_defenseBns = defenseBns; }

void Character::SetTarget(Character* target) 
{ m_target = target; }

void Character::OnCharacterTurnEvent()
{
	// ...override this in all characters
}
