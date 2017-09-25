#include "Enemy.h"
#include "GameWindowProperties.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <SFML/system.hpp>
#include <iostream>


Enemy::Enemy()
{
	
}

Enemy::Enemy(GameWindowProperties gameWindowProperties)
{
	setAlive();
	_reSpawn = false;
	int randomStart = rand()%361;
	_enemyPosition.setAngle(randomStart);
	_enemyPosition.setRadius(gameWindowProperties.getRadius());
	_enemyPosition.setoriginX(gameWindowProperties.getXOrigin());
	_enemyPosition.setoriginY(gameWindowProperties.getYOrigin());
    _enemyPosition.setX(gameWindowProperties.getXOrigin());
    _enemyPosition.setY(gameWindowProperties.getYOrigin());
    _gameWindowProperties = gameWindowProperties;

}

void Enemy::move()
{	
	auto rad = (_enemyPosition.getAngle() * PI/180)*3;
	_enemyPosition.setX(_enemyPosition.getoriginX() + factor*_enemyPosition.getRadius()*cos(rad));
	_enemyPosition.setY(_enemyPosition.getoriginY() + factor*_enemyPosition.getRadius()*sin(rad));
	//_enemyPosition.setAngle(_enemyPosition.getAngle() + 1);  //this is for spiralling
	//factor += 0.001;
	factor += 0.005;

    
    int xLimit = abs(_enemyPosition.getX());
    int yLimit = abs(_enemyPosition.getY());
    if(xLimit > _enemyPosition.getoriginX() + _enemyPosition.getRadius() || yLimit > _enemyPosition.getoriginY() + _enemyPosition.getRadius())
    {
       setDead();
		_reSpawn = true;
    }
    
    if(xLimit < _enemyPosition.getoriginX() - _enemyPosition.getRadius() || yLimit < _enemyPosition.getoriginY() - _enemyPosition.getRadius())
    {
           setDead();
		_reSpawn = true;
    }
}
