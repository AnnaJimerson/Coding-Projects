#include "InputHandler.h"
#include "GameplayState.h"
#include "StateMachineExampleGame.h"
#include <conio.h>

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscapeKey = 27;

void InputHandler::GetPlayerInput()
{
	if (!m_gameState) return;

	int input = _getch();
	int arrowInput = 0;
	int x = m_gameState->GetPlayerX();
	int y = m_gameState->GetPlayerY();

	// One of the arrow keys were pressed
	if (input == kArrowInput)
	{
		arrowInput = _getch();
	}

	if ((input == kArrowInput && arrowInput == kLeftArrow) ||
		(char)input == 'A' || (char)input == 'a')
	{
		x = m_gameState->SetPlayerX(x - 1);
	}
	else if ((input == kArrowInput && arrowInput == kRightArrow) ||
		(char)input == 'D' || (char)input == 'd')
	{
		x = m_gameState->SetPlayerX(x + 1);
	}
	else if ((input == kArrowInput && arrowInput == kUpArrow) ||
		(char)input == 'W' || (char)input == 'w')
	{
		y = m_gameState->SetPlayerY(y - 1);
	}
	else if ((input == kArrowInput && arrowInput == kDownArrow) ||
		(char)input == 'S' || (char)input == 's')
	{
		y = m_gameState->SetPlayerY(y + 1);
	}
	else if (input == kEscapeKey)
	{
		m_gameState->GetStateOwner()->LoadScene(StateMachineExampleGame::SceneName::MainMenu);
	}
	else if ((char)input == 'Z' || (char)input == 'z')
	{
		m_gameState->GetPlayer().DropKey();
	}
	else if ((char)input == 'X' || (char)input == 'x')
	{
		m_gameState->GetPlayer().DropFollower();
	}
}

void InputHandler::SetGameState(GameplayState* gameState)
{
	m_gameState = gameState;
}
