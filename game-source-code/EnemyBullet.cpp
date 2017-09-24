#include "EnemyBullet.h"
#include <cmath>
#include <iostream>

float PI = atan(1)*4;
float originFix = PI/2;

EnemyBullet::EnemyBullet()
{
    
}

EnemyBullet::EnemyBullet(Position position, GameWindowProperties gameWindowProperties, Position posPlayer)
{
	_posPlayer = posPlayer;
    _positionSpawn.setAngle(position.getAngle());
    _positionSpawn.setRadius(position.getRadius());
    _positionSpawn.setoriginX(position.getX());
    _positionSpawn.setoriginY(position.getY());
    _positionSpawn.setX(position.getX());
    _positionSpawn.setY(position.getY());
    _gameWindowProperties = gameWindowProperties;
	_enemyBulletRadius = gameWindowProperties.getRadius();
	_isAlive = true;
	_playerPosition = _posPlayer.getAngle()%360;
	
	if(_positionSpawn.getX() > _posPlayer.getX()){newX = -1;}
	else if(_positionSpawn.getX() < _posPlayer.getX()){newX = 1;}
	
	if(_positionSpawn.getY() > _posPlayer.getY()){newY = -1;}
	else if(_positionSpawn.getY() < _posPlayer.getY()){newY = 1;}
}

void EnemyBullet::updateEnemyBullet()
{
//	auto rad = (_posPlayer.getAngle() * PI/180)*3;
//	_positionSpawn.setX(_positionSpawn.getoriginX() + _factor*_positionSpawn.getRadius()*cos(rad));
//	_positionSpawn.setY(_positionSpawn.getoriginY() + _factor*_positionSpawn.getRadius()*sin(rad));
//	_factor += 0.01;
	
	_countX += 2.25;
//	if(_positionSpawn.getX() > _posPlayer.getX())
//		{_positionSpawn.setX(_positionSpawn.getoriginX() - _countX);}
//	else if(_positionSpawn.getX() < _posPlayer.getX())
//		{_positionSpawn.setX(_positionSpawn.getoriginX() + _countX);}
//	
//	if(_positionSpawn.getY() > _posPlayer.getY())
//		{_positionSpawn.setY(_positionSpawn.getoriginY() - _countX);}
//	else if(_positionSpawn.getY() < _posPlayer.getY())
//		{_positionSpawn.setY(_positionSpawn.getoriginY() + _countX);}
	
	_positionSpawn.setX(_positionSpawn.getoriginX() + _countX*newX);
	_positionSpawn.setY(_positionSpawn.getoriginY() + _countX*newY);
	
	if(_positionSpawn.getX() == _posPlayer.getX() && _positionSpawn.getY() == _posPlayer.getY())
		{_isAlive = false;}
}	


EnemyBullet::~EnemyBullet()
{

}