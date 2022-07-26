#pragma once
class UsableCommand
{
private:
	int potency = 0;
	class Character* Owner;
	int commandCount = 1;

public:
	UsableCommand();

	// When command is used
	virtual void OnCommandUsed();

	// Get Set potency values
	int GetCommandPotency() { return potency; }
	void SetCommandPotency(int in_potency);

	// Get Owning Character
	class Character* GetOwner() { return Owner; }

	// Get Set command count values
	int GetCommandCount() { return potency; }
	void AddToCommandCount(int in_count_add);
};

