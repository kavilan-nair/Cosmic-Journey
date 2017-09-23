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

Enemy::Enemy(GameWindowProperties gameWindowProperties, Position playerPosition)
{
    
    const float PI = 3.14159265358979323846;
    float originFix = PI/2;

	int upperAngle = (playerPosition.getAngle()*5) + 45;
    int lowerAngle = (playerPosition.getAngle()*5) - 45;
    
    upperAngle = upperAngle%360;
    lowerAngle = lowerAngle%360;
    
    
	auto randomStart = rand()% upperAngle + lowerAngle ;
    std::cout << "Player angle: " << playerPosition.getAngle()*5 << "Upper angle: " << upperAngle << "     " << "Lower angle: " << lowerAngle << std::endl;
    setAlive();
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
	factor += 0.01;

    
    int xLimit = abs(_enemyPosition.getX());
    int yLimit = abs(_enemyPosition.getY());
    if(xLimit > _enemyPosition.getoriginX() + _enemyPosition.getRadius() || yLimit > _enemyPosition.getoriginY() + _enemyPosition.getRadius())
    {
        setDead();
    }
    
    if(xLimit < _enemyPosition.getoriginX() - _enemyPosition.getRadius() || yLimit < _enemyPosition.getoriginY() - _enemyPosition.getRadius())
    {
        setDead();
    }
}
