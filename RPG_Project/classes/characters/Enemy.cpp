#include "Enemy.h"
#include "../inventory/UsableCommand.h"

Enemy::Enemy(std::string name, int health, int mana) : Character(name, health, mana) {

}

void Enemy::CharacterTurnEvent()
{
	// Execute random attack...
	UsableCommand* executeCommand = GetCommands()[rand() % GetCommands().size()];
	executeCommand->ExecuteCommand();
}
