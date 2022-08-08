#pragma once
class InputHandler
{
private:
	class GameplayState* m_gameState;
public:
	void GetPlayerInput();
	void SetGameState(class GameplayState* gameState);
};

