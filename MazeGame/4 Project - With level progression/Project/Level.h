#pragma once
#include <string>
#include <vector>

class PlacableActor;

class Level
{
	char* m_pLevelData;
	int m_height;
	int m_width;
	
	// Need followers to exit mechanic
	int m_neededFollowers = 0;

	std::vector<PlacableActor*> m_pActors;

public:
	Level();
	~Level();

	bool Load(std::string levelName, int* playerX, int* playerY);
	void Draw();
	PlacableActor* UpdateActors(int x, int y);

	// Looks at a list of actors to trigger collisions. HitActor is for returning the actor in the list that was hit
	PlacableActor* UpdateCollisionFromActors(std::vector<PlacableActor*>& CollidedActors, PlacableActor* HitActor);

	bool IsSpace(int x, int y);
	bool IsWall(int x, int y);

	int GetHeight() { return m_height; }
	int GetWidth() { return m_width;  }

	// return needed followers
	int GetNeededFollowers() { return m_neededFollowers; }

	static constexpr char WAL = (char)219;

private:
	bool ConvertLevel(int* playerX, int* playerY);
	int GetIndexFromCoordinates(int x, int y);

};