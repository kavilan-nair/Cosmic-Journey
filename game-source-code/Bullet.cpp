#include "Bullet.h"
#include <cmath>
#include <iostream>


Bullet::Bullet()
{
	
}

Bullet::Bullet(Position position, GameWindowProperties gameWindowProperties)
{
	_positionSpawn = position;
	_gameWindowProperties = gameWindowProperties;
	_bulletRadius = gameWindowProperties.getRadius();
	_isAlive = true;
}

void Bullet::updateBullet()
{
	if (_bulletRadius > 0)
	{
		int bulletSpeed = _gameWindowProperties.getRadius()*0.04;
		_bulletRadius -= bulletSpeed;
		auto rad = (_positionSpawn.getAngle() * PI/180)*5;
		int xPosition = _gameWindowProperties.getXOrigin() + _bulletRadius*cos(rad-originFix);
		int yPosition = _gameWindowProperties.getYOrigin() - _bulletRadius*sin(rad-originFix);
		_positionSpawn.setX(xPosition);
		_positionSpawn.setY(yPosition);
	}
	else 
	{
		_isAlive = false;
	}	
	
}

Bullet::~Bullet()
{
	
}