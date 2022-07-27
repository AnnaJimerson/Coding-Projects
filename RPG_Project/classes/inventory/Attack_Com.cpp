#include "Attack_Com.h"
#include "../characters/Character.h"

Attack_Com::Attack_Com()
{
	// Set potency of 'Attack' command
	SetCommandPotency(5);
}

bool Attack_Com::OnCommandUsed()
{
	// Call parent function first
	if (UsableCommand::OnCommandUsed() == false) return false;


	
	return true;
}
