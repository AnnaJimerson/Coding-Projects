#include <iostream>

#include "Player.h"
#include "Key.h"
#include "AudioManager.h"
#include "OwOFollower.h"

using namespace std;

constexpr int kStartingNumberOfLives = 3;

Player::Player()
	: PlacableActor(0, 0)
	, m_pCurrentKey(nullptr)
	, m_money(0)
	, m_lives(kStartingNumberOfLives)
{

}

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasKey(ActorColor color)
{
	return true;// HasKey() && m_pCurrentKey->GetColor() == color;
}

void Player::PickupKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::UseKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Remove();
		m_pCurrentKey = nullptr;
	}
}

void Player::DropKey()
{
	if (m_pCurrentKey)
	{
		AudioManager::GetInstance()->PlayKeyDropSound();
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@";
}

void Player::UpdateFollowers() {
	// First store previous coords
	prevX = GetXPosition();
	prevY = GetYPosition();
	int prev2X = 0;
	int prev2Y = 0;

	// Update each follower's position based on previous coordinates (snake-effect)
	for (int i = 0; i < followers.size(); i++) {

		prev2X = followers[i]->GetXPosition();
		prev2Y = followers[i]->GetYPosition();

		followers[i]->SetPosition(prevX, prevY);

		prevX = prev2X;
		prevY = prev2Y;
	}
}

void Player::DropFollower()
{
	followers[followers.size()-1]->PlaceFollower();
	followers.pop_back();
}
