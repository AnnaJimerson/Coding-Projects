#pragma once
#include "GameStateMachine.h"
#include "Player.h"
#include "Level.h"

class Game
{
	GameStateMachine* m_pStateMachine;
public:
	Game();
	void Initialize(GameStateMachine* pStateMachine);
	void RunGameLoop();
	void RunInputLoop();
	void Deinitialize();

	class InputHandler* GetInputHandle() { return m_Input; }

	bool isRunning = false;

private:
	bool Update(bool processInput = true);
	void Draw();
	class InputHandler* m_Input;
};