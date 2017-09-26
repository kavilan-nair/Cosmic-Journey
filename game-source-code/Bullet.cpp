#include "Bullet.h"
#include <cmath>

Bullet::Bullet(Position position, GameWindowProperties gameWindowProperties, int bulletNumber) //hookup an enum as the parameter instead of an int
{
	_positionBullet = position;
	if(bulletNumber > 1)
	{
		int bulletUpgradeInteger = pow(-1,bulletNumber);
		_positionBullet.setAngle(_positionBullet.getAngle() + bulletUpgradeInteger);
        auto radians = (_positionBullet.getAngle() * PI/180)*5;
        int xPosBullet = _gameWindowProperties.getXOrigin() + _gameWindowProperties.getRadius()*cos(radians-originFix);
		int yPosBullet = _gameWindowProperties.getYOrigin() - _gameWindowProperties.getRadius()*sin(radians-originFix);
        _positionBullet.setX(xPosBullet);
        _positionBullet.setY(yPosBullet);
	}
	
	_gameWindowProperties = gameWindowProperties;
	_bulletRadius = gameWindowProperties.getRadius();
	_aliveStatus = true;
}

void Bullet::updateBullet()
{
	if (_bulletRadius > 0)
	{
		int bulletSpeed = _gameWindowProperties.getRadius()*0.04;
		_bulletRadius -= bulletSpeed;
		auto radians = (_positionBullet.getAngle() * PI/180)*5;
		int xPosBullet = _gameWindowProperties.getXOrigin() + _bulletRadius*cos(radians-originFix);
		int yPosBullet = _gameWindowProperties.getYOrigin() - _bulletRadius*sin(radians-originFix);
		_positionBullet.setX(xPosBullet);
		_positionBullet.setY(yPosBullet);
	}
	else 
	{
		_aliveStatus = false;
	}	
	
}

Bullet::~Bullet()
{
	
}