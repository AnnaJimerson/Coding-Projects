#include "Game.h"
#include "InputHandler.h"
#include <thread>

Game::Game()
	: m_pStateMachine(nullptr)
{

}

void Game::Initialize(GameStateMachine* pStateMachine)
{
	if (pStateMachine != nullptr)
	{
		pStateMachine->Init();
		m_pStateMachine = pStateMachine;
	}

	// Create our input handler
	m_Input = new InputHandler();
}

void Game::RunInputLoop()
{
	while (m_isRunningInput)
	{
		m_Input->GetPlayerInput();
	}
}

void Game::RunGameLoop()
{
	bool isGameOver = false;

	int deltaFrameTime = 0;
	int deltaFrameMax = 99999999;

	std::thread InputThread(&Game::RunInputLoop, this);

	while (!isGameOver)
	{
		m_isRunningInput = true;

		// Slow down frame update
		if (deltaFrameTime == deltaFrameMax)
		{
			// update with no input
			Update(false);
			// Draw
			Draw();
			// Update with input
			isGameOver = Update();

		}

		deltaFrameTime < deltaFrameMax ? deltaFrameTime++ : deltaFrameTime = 0;
	}

	m_isRunningInput = false;
	InputThread.join();

	Draw();
}

void Game::Deinitialize()
{
	if (m_pStateMachine != nullptr)
		m_pStateMachine->Cleanup();

	// delete input handler
	if (m_Input != nullptr)
		delete m_Input;
}

bool Game::Update(bool processInput)
{
	return m_pStateMachine->UpdateCurrentState(processInput);
}

void Game::Draw()
{
	m_pStateMachine->DrawCurrentState();
}
