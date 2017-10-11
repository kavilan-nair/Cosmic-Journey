#include "Enemy.h"
#include <stdlib.h>

Enemy::Enemy(const Grid& grid)
    : _grid(grid), 
      _enemyBullet(_enemyPos, grid),
      _radiusFactor(0.005),
      _radiusIncrease(0.001),
      _hitRadius(24),
      _aliveStatus(true);
      _reSpawn(false)
{

	int randomStartAngle = rand()%360;
	_enemyPos.setAngle(randomStartAngle);
	_enemyPos.setRadius(0);
	_enemyPos.setXposInitial(grid.getCenterX()); 
    _enemyPos.setYposInitial(grid.getCenterY());
	_enemyPos.setXpos(grid.getCenterX());
    _enemyPos.setYpos(grid.getCenterY());
}

Enemy::~Enemy()
{
}

Position Enemy::getPosition()
{
	return _enemyPos;
}

EntityType Enemy::getEntityType()
{
	 return EntityType::ENEMY;
} 

void Enemy::move()
{
    if (_enemyPos.getRadius() < _grid.getRadius())
	{
        auto radianAngle = (_enemyPos.getAngle() * M_PI/180);
        _enemyPos.setRadius(_enemyPos.getRadius()  + _radiusFactor);
        _enemyPos.setXpos(_enemyPos.getXposInitial() + _radiusFactor * _grid.getRadius() * cos(radianAngle));
        _enemyPos.setYpos(_enemyPos.getYposInitial() + _radiusFactor * _grid.getRadius() * sin(radianAngle));
        _radiusFactor += speedIncrease;
	}
    else 
	{
		_aliveStatus = false;
        _reSpawn = true;
	}
}

bool Enemy::isAlive()
{
	return _aliveStatus;
}

vector<shared_ptr<IMovingEntity>> Enemy::shoot()
{
    vector<shared_ptr<IMovingEntity>> enemyBulletVector; 
    enemyBulletVector.push_back(std::make_shared<EnemyBullet>(_enemyPos, _grid));
    return enemyBulletVector;
}

bool Enemy::getRespawn()
{
	return _reSpawn;
}

void Enemy::setDead()
{   
    _aliveStatus = false;
}

float Enemy::getHitRadius()
{
    return _hitRadius;
}