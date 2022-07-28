#include "Attack_Com.h"
#include "../characters/Character.h"

Attack_Com::Attack_Com()
{
	// Set potency of 'Attack' command
	SetCommandPotency(5);
}

bool Attack_Com::ExecuteCommand()
{
	// Call parent function first
	if (UsableCommand::ExecuteCommand() == false) return false;

	// Calculate Damage
	int damage = GetOwner()->GetAttackBonus() + GetCommandPotency();

	// Print that we dealt damage
	std::cout << GetOwner()->GetName() << " attacks and deals <" << damage << "> damage to " <<
		GetOwner()->GetTarget()->GetName() << "!!!" << std::endl;

	// Target takes damage
	GetOwner()->GetTarget()->TakeDamage(damage);
	
	return true;
}
