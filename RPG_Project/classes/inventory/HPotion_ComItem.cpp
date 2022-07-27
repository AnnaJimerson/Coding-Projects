#include "HPotion_ComItem.h"
#include "../characters/Character.h"
#include <iostream>

HPotion_ComItem::HPotion_ComItem()
{
	// Set the strength of the potion (amt. of hp to restore)
	SetCommandPotency(25);
}

void HPotion_ComItem::OnCommandUsed()
{
	if (!GetOwner()) return;
	
	// Print what the command is doing
	std::cout << GetOwner()->GetName() << " used a healing potion to restore " <<
			GetCommandPotency() << " health!!";

	// Restore the health
	GetOwner()->SetHealth(GetOwner()->GetHealth() + 25);
}


