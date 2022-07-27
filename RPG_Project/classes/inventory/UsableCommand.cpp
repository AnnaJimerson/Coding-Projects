#include "UsableCommand.h"
#include "../characters/Character.h"

UsableCommand::UsableCommand()
{
}

void UsableCommand::OnCommandUsed()
{
	//... override this function with UsableCommand subclasses and they do stuff here
}

void UsableCommand::SetCommandPotency(int potency)
{
	// Set the potency of the UsableCommand
	this->m_potency = potency;
}

void UsableCommand::AddToCommandCount(int numberAdded)
{
	// Adds the in count amount to the current count of the item
	m_commandCount += numberAdded;

	// IF out of items!!
	// find the command in the owner character's inventory and erase it (kinda bad but.........)
	if (m_commandCount <= 0) {
		// Find in commands list
		GetOwner()->GetCommands().erase
			(std::find(GetOwner()->GetCommands().begin(), GetOwner()->GetCommands().end(), this));

		// Find in inventory list
		GetOwner()->GetInventory().erase
		(std::find(GetOwner()->GetInventory().begin(), GetOwner()->GetInventory().end(), this));
	}
}
