#include "Character.h"
#include <algorithm>

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
{ 
	m_health = health;

	// Don't allow hp to go over max health
	m_health = std::min(m_health, m_maxHealth);
}

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

void Character::CharacterTurnEvent()
{
	// ...override this in all characters
}

void Character::TakeDamage(int damage)
{
	// Calculate critical hits
	if (rand() % 10 == 0) {
		damage *= 2;
		std::cout << "~CRITICAL!!~" << std::endl;
		std::cout << "*<" << damage << ">*" << std::endl;
	};

	// Deal damage to this character...
	SetHealth(GetHealth() - damage);
}
