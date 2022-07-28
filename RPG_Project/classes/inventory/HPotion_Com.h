#pragma once
#include "UsableCommand.h"

class HPotion_Com : 
	public UsableCommand
{
private:

public:
	HPotion_Com();
	virtual bool ExecuteCommand() override;
};

