#include "UsableCommand.h"
#include "../characters/Character.h"

UsableCommand::UsableCommand()
{
}

void UsableCommand::OnCommandUsed()
{
	//... override this function with UsableCommand subclasses and they do stuff here
}

void UsableCommand::SetCommandPotency(int in_potency)
{
	// Set the potency of the UsableCommand
	this->potency = in_potency;
}

void UsableCommand::AddToCommandCount(int in_count_add)
{
	// Adds the in count amount to the current count of the item
	commandCount += in_count_add;

	// IF out of items!!
	// find the command in the owner character's inventory and erase it (kinda bad but.........)
	if (commandCount <= 0) {
		// Find in commands list
		GetOwner()->getCommands().erase
			(std::find(GetOwner()->getCommands().begin(), GetOwner()->getCommands().end(), this));

		// Find in inventory list
		GetOwner()->getInventory().erase
		(std::find(GetOwner()->getInventory().begin(), GetOwner()->getInventory().end(), this));
	}
}
