#pragma once
#include <string>

class UsableCommand
{
private:
	int m_potency = 0;
	class Character* m_owner;
	int m_commandCount = 1;
	bool m_isEquippable = false;
	std::string m_commandName = "Command";

public:
	UsableCommand();

	// Get Set potency values
	int const GetCommandPotency() const { return m_potency; }
	void SetCommandPotency(int potency);

	// Get Set if the command is equippable or not
	bool const GetIsEquippable() const { return m_isEquippable; }
	void SetIsEquippable(bool isEquippable);

	// Get Owning Character
	class Character* GetOwner() { return m_owner; }

	// Get Set command count values
	int const GetCommandCount() const { return m_potency; }
	void AddToCommandCount(int numberAdded);

	// Get Set command name
	std::string const GetCommandName() const { return m_commandName; }
	void SetCommandName(std::string commandName);

	// Command Event Functions
	virtual bool OnCommandUsed();
	virtual bool OnCommandEquipped();
};

