#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(const Position& playerPos, const Grid& grid, const int& bulletNumber) : _playerBulletPos(playerPos), _grid(grid), _aliveStatus(true)
{
    if (bulletNumber == 2)
    {
        _playerBulletPos.setAngle(_playerBulletPos.getAngle() + 10);
    }
    else if (bulletNumber == 3)
    {
        _playerBulletPos.setAngle(_playerBulletPos.getAngle() - 10);
    }
}

PlayerBullet::~PlayerBullet()
{
}

Position PlayerBullet::getPosition()
{
    return _playerBulletPos;
}
EntityType PlayerBullet::getEntityType()
{
    return EntityType::PLAYER_BULLET;
}

bool PlayerBullet::isAlive()
{
    return _aliveStatus;
} 	

void PlayerBullet::move()
{
    if (_playerBulletPos.getRadius() > 15)
	{
		auto radiusFactor = _grid.getRadius()*0.0001f;
		_playerBulletPos.setRadius(_playerBulletPos.getRadius() - radiusFactor);
		auto rad = (_playerBulletPos.getAngle() * M_PI/180)*0.5;
		int newXPos = _grid.getCenterX() + _playerBulletPos.getRadius()*cos(rad-M_PI_2);
		int newYPos = _grid.getCenterY() - _playerBulletPos.getRadius()*sin(rad-M_PI_2);
		_playerBulletPos.setXpos(newXPos);
		_playerBulletPos.setYpos(newYPos);
	}
	else 
	{
		_aliveStatus = false;
	}	
}

bool PlayerBullet::getRespawn()
{
	return false;
}

void PlayerBullet::setDead()
{   
    _aliveStatus = false;
}

float PlayerBullet::getHitRadius()
{
    return _hitRadius;
}