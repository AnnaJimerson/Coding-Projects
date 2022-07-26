#include "OwOEnemy.h"
#include <iostream>

OwOEnemy::OwOEnemy(int x, int y, int deltaX, int deltaY) : Enemy(x, y, deltaX, deltaY)
{

}

void OwOEnemy::Draw()
{
	std::cout << 'D';
}
