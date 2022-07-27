#pragma once
#include "UsableCommand.h"

class HPotion_ComItem : 
	public UsableCommand
{
private:

public:
	HPotion_ComItem();
	virtual bool OnCommandUsed() override;
};

