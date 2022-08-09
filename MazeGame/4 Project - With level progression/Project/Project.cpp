#include <iostream>
#include "Game.h"
#include "AudioManager.h"
#include "StateMachineExampleGame.h"
#include "vld.h"

using namespace std;

int main()
{
	Game myGame;

	StateMachineExampleGame gameStateMachine(&myGame);

	myGame.Initialize(&gameStateMachine);

	myGame.RunGameLoop();

	myGame.Deinitialize();

	AudioManager::DestroyInstance();

	return 0;
}