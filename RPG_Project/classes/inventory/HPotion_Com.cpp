#include "HPotion_Com.h"
#include "../characters/Character.h"

HPotion_Com::HPotion_Com()
{
	// Set the strength of the potion (amt. of hp to restore)
	SetCommandPotency(25);
}

bool HPotion_Com::ExecuteCommand()
{
	// Call parent function first
	if (UsableCommand::ExecuteCommand() == false) return false;
	
	// Print what the command is doing
	std::cout << GetOwner()->GetName() << " used a healing potion to restore " <<
			GetCommandPotency() << " health!!";

	// Restore the health
	GetOwner()->SetHealth(GetOwner()->GetHealth() + 25);

	return true;
}


