#pragma once
#include "Enemy.h"
class OwOFollower :
    public PlacableActor
{
private:
    bool m_isPlaced = false;
    bool m_isFollowingPlayer = false;
public:

    OwOFollower(int x, int y);
    virtual ActorType GetType() override { return ActorType::OwOFollower; }
    virtual void Draw() override;
    bool FollowPlayer();
    void PlaceFollower();

    bool IsFollowerPlaced() { return m_isPlaced; }
};

