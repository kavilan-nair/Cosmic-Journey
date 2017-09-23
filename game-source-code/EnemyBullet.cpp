#include "EnemyBullet.h"
#include <cmath>
#include <iostream>

EnemyBullet::EnemyBullet()
{
    
}

EnemyBullet::EnemyBullet(Position position, GameWindowProperties gameWindowProperties)
{
    _positionSpawn.setAngle(position.getAngle());
    _positionSpawn.setRadius(position.getRadius());
    _positionSpawn.setoriginX(position.getX());
    _positionSpawn.setoriginY(position.getY());
    _positionSpawn.setX(position.getX());
    _positionSpawn.setY(position.getY());
    _gameWindowProperties = gameWindowProperties;
	_enemyBulletRadius = gameWindowProperties.getRadius();
	_isAlive = true;
}

void EnemyBullet::updateEnemyBullet()
{
    auto rad = (_positionSpawn.getAngle() * PI/180)*3;
	_positionSpawn.setX(_positionSpawn.getoriginX() + _factor*_positionSpawn.getRadius()*cos(rad));
	_positionSpawn.setY(_positionSpawn.getoriginY() + _factor*_positionSpawn.getRadius()*sin(rad));
	_factor += 0.05;
}

EnemyBullet::~EnemyBullet()
{

}