#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(const Position& enemyPos, const Grid& grid) : _enemyBulletPos(enemyPos), _grid(grid), _aliveStatus(true)
{
    _enemyBulletPos.setAngle(enemyPos.getAngle());
    _enemyBulletPos.setRadius(0);
    _enemyBulletPos.setXposInitial(enemyPos.getXpos());
    _enemyBulletPos.setYposInitial(enemyPos.getYpos());
    _enemyBulletPos.setXpos(enemyPos.getXpos());
    _enemyBulletPos.setYpos(enemyPos.getYpos());
}

EnemyBullet::~EnemyBullet()
{
}

Position EnemyBullet::getPosition()
{
    return _enemyBulletPos;
}

EntityType EnemyBullet::getEntityType()
{
    return EntityType::ENEMY_BULLET;
}

bool EnemyBullet::isAlive()
{
    return _aliveStatus;
} 	

void EnemyBullet::move()
{
    if (_enemyBulletPos.getRadius() < _grid.getRadius())
	{
        auto radianAngle = (_enemyBulletPos.getAngle() * M_PI/180);
        _enemyBulletPos.setRadius(_enemyBulletPos.getRadius()  + _factor);
        _enemyBulletPos.setXpos(_enemyBulletPos.getXposInitial() + _factor * _grid.getRadius() * cos(radianAngle));
        _enemyBulletPos.setYpos(_enemyBulletPos.getYposInitial() + _factor * _grid.getRadius() * sin(radianAngle));
        _factor += 0.003;
	}
    else 
	{
		_aliveStatus = false;
	}
}

bool EnemyBullet::getRespawn()
{
	return false;
}

void EnemyBullet::setDead()
{   
    _aliveStatus = false;
}

float EnemyBullet::getHitRadius()
{
    return _hitRadius;
}