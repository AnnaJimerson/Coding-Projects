#pragma once
#include "UsableCommand.h"
class Attack_Com :
    public UsableCommand
{
private:


public:
    Attack_Com();
    virtual bool ExecuteCommand() override;
};

