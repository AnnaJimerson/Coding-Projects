#pragma once
#include "PlacableActor.h"
#include <vector>

class Key;

class Player : public PlacableActor
{
public:
	Player();

	bool HasKey();
	bool HasKey(ActorColor color);
	void PickupKey(Key* key);
	void UseKey();
	void DropKey();
	Key* GetKey() { return m_pCurrentKey; }

	void AddMoney(int money) { m_money += money; }
	int GetMoney() { return m_money; }

	int GetLives() { return m_lives; }
	void DecrementLives() { m_lives--; }

	virtual ActorType GetType() override { return ActorType::Player; }
	virtual void Draw() override;

	// Added follower mechanic (to shoot them at enemies)
	std::vector<class PlacableActor*>& GetFollowers() { return followers; }
	void UpdateFollowers();
	void DropFollower();

	void SetPreviousPosition(int x, int y);

	int GetPrevX() { return m_prevX; }
	int GetPrevY() { return m_prevY; }

private:
	Key* m_pCurrentKey;
	int m_money;
	int m_lives;
	std::vector<class PlacableActor*> followers;

	int m_prevX = 0;
	int m_prevY = 0;
};
