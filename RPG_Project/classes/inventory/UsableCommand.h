#pragma once
class UsableCommand
{
private:
	int m_potency = 0;
	class Character* m_owner;
	int m_commandCount = 1;

public:
	UsableCommand();

	// When command is used
	virtual void OnCommandUsed();

	// Get Set potency values
	int GetCommandPotency() { return m_potency; }
	void SetCommandPotency(int potency);

	// Get Owning Character
	class Character* GetOwner() { return m_owner; }

	// Get Set command count values
	int GetCommandCount() { return m_potency; }
	void AddToCommandCount(int numberAdded);
};

