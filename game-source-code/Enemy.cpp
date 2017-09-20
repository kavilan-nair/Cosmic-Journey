#include "Enemy.h"
#include "GameWindowProperties.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <SFML/system.hpp>

Enemy::Enemy()
{
	
}

Enemy::Enemy(GameWindowProperties gameWindowProperties)
{

	
	setAlive();
	srand(time(0));
	int entryPoint= rand() %2;
	
	_coordinateX = gameWindowProperties.getXOrigin();
	_coordinateY = gameWindowProperties.getYOrigin();
	
}

Enemy::setAlive()
{
	_alive = true;
}

Enemy::isAlive()
{
	return _alive;
}

Enemy::move()
{	
	_coordinateX += 1;
	_coordinateY += 1;
}