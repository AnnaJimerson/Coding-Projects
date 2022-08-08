#pragma once
#include "GameState.h"
#include "Player.h"
#include "Level.h"

#include <windows.h>
#include <vector>
#include <string>

class StateMachineExampleGame;

class GameplayState : public GameState
{
	StateMachineExampleGame* m_pOwner;
	
	Player m_player;
	Level* m_pLevel;

	bool m_beatLevel;
	int m_skipFrameCount;
	static constexpr int kFramesToSkip = 2;

	int m_currentLevel;

	std::vector<std::string> m_LevelNames;

	int m_playerX;
	int m_playerY;

public:
	GameplayState(StateMachineExampleGame* pOwner);
	~GameplayState();

	virtual void Enter() override;
	virtual bool Update(bool processInput = true) override;
	virtual void Draw() override;

	Player& GetPlayer() { return m_player; }
	int GetPlayerX() { return m_playerX; }
	int GetPlayerY() { return m_playerY; }
	int SetPlayerX(int playerX);
	int SetPlayerY(int playerY);
	StateMachineExampleGame* GetStateOwner() { return m_pOwner; }
	bool GetBeatLevel() { return m_beatLevel; }

private:
	void HandleCollision(int newPlayerX, int newPlayerY);
	bool Load();
	void DrawHUD(const HANDLE& console);
};
