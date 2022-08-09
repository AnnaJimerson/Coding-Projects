#include "GameplayState.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <assert.h>

#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Money.h"
#include "Goal.h"
#include "AudioManager.h"
#include "Utility.h"
#include "StateMachineExampleGame.h"
#include "OwOFollower.h"
#include "Game.h"
#include "InputHandler.h"

using namespace std;

GameplayState::GameplayState(StateMachineExampleGame* pOwner)
	: m_pOwner(pOwner)
	, m_beatLevel(false)
	, m_skipFrameCount(0)
	, m_currentLevel(0)
	, m_pLevel(nullptr)
{
	m_LevelNames.push_back("Level1.txt");
	m_LevelNames.push_back("Level2.txt");
	m_LevelNames.push_back("Level3.txt");

	// Get the input handler from Game class, and set its game state to this
	m_pOwner->GetOwner()->GetInputHandle()->SetGameState(this);
}

GameplayState::~GameplayState()
{
	delete m_pLevel;
	m_pLevel = nullptr;
}

bool GameplayState::Load()
{
	if (m_pLevel)
	{
		delete m_pLevel;
		m_pLevel = nullptr;
	}

	m_pLevel = new Level();
	
	return m_pLevel->Load(m_LevelNames.at(m_currentLevel), m_player.GetXPositionPointer(), m_player.GetYPositionPointer());

}

void GameplayState::Enter()
{
	Load();

	// Once loaded level, set player's initial position
	m_playerX = GetPlayer().GetXPosition();
	m_playerY = GetPlayer().GetYPosition();
}

bool GameplayState::Update(bool processInput)
{

	//if(m_playerMoved)
		//m_player.SetPreviousPosition(m_player.GetXPosition(), m_player.GetYPosition());

	m_player.SetPosition(m_playerX, m_playerY);
	HandleCollision(m_playerX, m_playerY);

	if (m_beatLevel)
	{
		++m_skipFrameCount;
		if (m_skipFrameCount > kFramesToSkip)
		{
			m_beatLevel = false;
			m_skipFrameCount = 0;
			++m_currentLevel;
			if (m_currentLevel == m_LevelNames.size())
			{
				Utility::WriteHighScore(m_player.GetMoney());

				AudioManager::GetInstance()->PlayWinSound();
				
				m_pOwner->LoadScene(StateMachineExampleGame::SceneName::Win);

				// Stop input from infinite looping (need a better way to handle this)
				m_pOwner->GetOwner()->GetInputHandle()->SetGameState(nullptr);
			}
			else
			{
				// On to the next level
				Load();
			}

		}
	}

	m_playerMoved = false;

	return false;
}

void GameplayState::SetPlayerMoved(bool moved)
{
	m_playerMoved = moved;
}

void GameplayState::HandleCollision(int newPlayerX, int newPlayerY)
{
	PlacableActor* collidedActor = m_pLevel->UpdateActors(newPlayerX, newPlayerY);
	if (collidedActor != nullptr && collidedActor->IsActive())
	{
		switch (collidedActor->GetType())
		{
		case ActorType::OwOFollower:
		{
			OwOFollower* collidedOwO = dynamic_cast<OwOFollower*>(collidedActor);

			if (collidedOwO->FollowPlayer()) {
				assert(collidedOwO);
				AudioManager::GetInstance()->PlayKeyDropSound();
				m_player.SetPosition(newPlayerX, newPlayerY);
				m_player.GetFollowers().push_back(collidedOwO);
			}
			break;
		}
		case ActorType::Enemy:
		{
			Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);
			assert(collidedEnemy);
			AudioManager::GetInstance()->PlayLoseLivesSound();
			collidedEnemy->Remove();
			m_player.SetPosition(newPlayerX, newPlayerY);

			m_player.DecrementLives();
			if (m_player.GetLives() < 0)
			{
				//TODO: Go to game over screen
				AudioManager::GetInstance()->PlayLoseSound();
				m_pOwner->LoadScene(StateMachineExampleGame::SceneName::Lose);

				// Stop input from infinite looping (need a better way to handle this)
				m_pOwner->GetOwner()->GetInputHandle()->SetGameState(nullptr);
			}
			break;
		}
		case ActorType::Money:
		{
			Money* collidedMoney = dynamic_cast<Money*>(collidedActor);
			assert(collidedMoney);
			AudioManager::GetInstance()->PlayMoneySound();
			collidedMoney->Remove();
			m_player.AddMoney(collidedMoney->GetWorth());
			m_player.SetPosition(newPlayerX, newPlayerY);
			break;
		}
		case ActorType::Key:
		{
			Key* collidedKey = dynamic_cast<Key*>(collidedActor);
			assert(collidedKey);
			if (!m_player.HasKey())
			{
				m_player.PickupKey(collidedKey);
				collidedKey->Remove();
				m_player.SetPosition(newPlayerX, newPlayerY);
				AudioManager::GetInstance()->PlayKeyPickupSound();
			}
			break;
		}
		case ActorType::Door:
		{
			Door* collidedDoor = dynamic_cast<Door*>(collidedActor);
			assert(collidedDoor);
			if (!collidedDoor->IsOpen())
			{
				if (m_player.HasKey(collidedDoor->GetColor()))
				{
					collidedDoor->Open();
					collidedDoor->Remove();
					m_player.UseKey();
					m_player.SetPosition(newPlayerX, newPlayerY);
					AudioManager::GetInstance()->PlayDoorOpenSound();
				}
				else
				{
					AudioManager::GetInstance()->PlayDoorClosedSound();
				}
			}
			else
			{
				m_player.SetPosition(newPlayerX, newPlayerY);
			}
			break;
		}
		case ActorType::Goal:
		{
			if (m_player.GetFollowers().size() < m_pLevel->GetNeededFollowers()) return;
			Goal* collidedGoal = dynamic_cast<Goal*>(collidedActor);
			assert(collidedGoal);
			collidedGoal->Remove();
			m_player.GetFollowers().clear();
			m_player.SetPosition(newPlayerX, newPlayerY);
			m_beatLevel = true;
			break;
		}
		default:
			break;
		}
	}
	else if (m_pLevel->IsSpace(newPlayerX, newPlayerY)) // no collision
	{
		m_player.UpdateFollowers();
		m_player.SetPosition(newPlayerX, newPlayerY);
	}
	else if (m_pLevel->IsWall(newPlayerX, newPlayerY))
	{
		// wall collision, do nothing
	}
}

void GameplayState::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");

	m_pLevel->Draw();

	// Set cursor position for player 
	COORD actorCursorPosition;
	actorCursorPosition.X = m_player.GetXPosition();
	actorCursorPosition.Y = m_player.GetYPosition();
	SetConsoleCursorPosition(console, actorCursorPosition);
	m_player.Draw();

	// Set the cursor to the end of the level
	COORD currentCursorPosition;
	currentCursorPosition.X = 0;
	currentCursorPosition.Y = m_pLevel->GetHeight();
	SetConsoleCursorPosition(console, currentCursorPosition);

	DrawHUD(console);
}

int GameplayState::SetPlayerX(int playerX)
{
	m_playerX = playerX;
	return m_playerX;
}

int GameplayState::SetPlayerY(int playerY)
{
	m_playerY = playerY;
	return m_playerY;
}

void GameplayState::DrawHUD(const HANDLE& console)
{
	cout << endl;

	// Top Border
	for (int i = 0; i < m_pLevel->GetWidth(); ++i)
	{
		cout << Level::WAL;
	}
	cout << endl;

	// Left Side border
	cout << Level::WAL;

	cout << " wasd-move " << Level::WAL << " z-drop key " << Level::WAL;

	cout << " $:" << m_player.GetMoney() << " " << Level::WAL;
	cout << " lives:" << m_player.GetLives() << " " << Level::WAL;
	cout << " key:";
	if (m_player.HasKey())
	{
		m_player.GetKey()->Draw();
	}
	else
	{
		cout << " ";
	}

	// RightSide border
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);

	COORD pos;
	pos.X = m_pLevel->GetWidth() - 1;
	pos.Y = csbi.dwCursorPosition.Y;
	SetConsoleCursorPosition(console, pos);

	cout << Level::WAL;
	cout << endl;

	// Bottom Border
	for (int i = 0; i < m_pLevel->GetWidth(); ++i)
	{
		cout << Level::WAL;
	}
	cout << endl;
}