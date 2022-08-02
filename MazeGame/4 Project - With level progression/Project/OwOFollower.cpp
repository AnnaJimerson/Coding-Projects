#include "OwOFollower.h"
#include <iostream>
#include <conio.h>

OwOFollower::OwOFollower(int x, int y) : PlacableActor(x, y)
{

}

void OwOFollower::Draw()
{
	std::cout << "OwO";
}

bool OwOFollower::FollowPlayer()
{
	if (!m_isFollowingPlayer) {
		m_isFollowingPlayer = true;
		return true;
	}
	else {
		return false;
	}
}

void OwOFollower::PlaceFollower()
{
	m_isPlaced = true;
	m_isFollowingPlayer = false;
}
