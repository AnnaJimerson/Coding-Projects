#pragma once
#include "Enemy.h"
class OwOEnemy :
    public Enemy
{
public:
    OwOEnemy(int x, int y, int deltaX = 0, int deltaY = 0);
    virtual ActorType GetType() override { return ActorType::OwOEnemy; }
    virtual void Draw() override;
};

