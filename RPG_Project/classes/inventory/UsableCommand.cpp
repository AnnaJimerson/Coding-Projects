#include "UsableCommand.h"
#include "../characters/Character.h"
#include <iostream>

UsableCommand::UsableCommand()
{
}

void UsableCommand::SetCommandName(std::string commandName)
{
}

bool UsableCommand::OnCommandUsed()
{
	// Check if owner exists
	if (!GetOwner()) {
		std::cout << "NO VALID OWNER!!";
		return false;
	}

	// Then check if their target exists
	if (GetOwner()->GetTarget() == nullptr) {
		std::cout << "NO VALID TARGET!!";
		return false;
	}

	return true;
}

bool UsableCommand::OnCommandEquipped()
{
	// Check if owner exists
	if (!GetOwner()) {
		std::cout << "NO VALID OWNER!!";
		return false;
	}

	// Successfully equipped
	std::cout << GetCommandName() << " successfully equipped!!";
	return true;
}

void UsableCommand::SetCommandPotency(int potency)
{
	// Set the potency of the UsableCommand
	this->m_potency = potency;
}

void UsableCommand::SetIsEquippable(bool isEquippable)
{
	m_isEquippable = isEquippable;
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
