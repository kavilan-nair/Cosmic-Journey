#include "Asteroid.h"

Asteroid::Asteroid(const Grid& grid) 
	: _grid(grid),
	  _aliveStatus(true),
	  _radiusFactor(0.00001),
	  _radiusIncrease(0.003),      
	  _hitRadius(15)
{
	int randomStartAngle = rand()%360;
	_asteroidPos.setAngle(randomStartAngle);
	_asteroidPos.setRadius(0);
	_asteroidPos.setXposInitial(grid.getCenterX());
	_asteroidPos.setYposInitial(grid.getCenterY());
	_asteroidPos.setXpos(grid.getCenterX());
	_asteroidPos.setYpos(grid.getCenterY());
}

Asteroid::~Asteroid()
{
}

Position Asteroid::getPosition()
{
	return _asteroidPos;
}

EntityType Asteroid::getEntityType()
{
	return EntityType::ASTEROID;
} 

void Asteroid::move()
{    
	if (_asteroidPos.getRadius() < _grid.getRadius())
	{
		auto radianAngle = (_asteroidPos.getAngle() * M_PI/180);
		_asteroidPos.setRadius(_asteroidPos.getRadius()  + _radiusFactor);
		_asteroidPos.setXpos(_asteroidPos.getXposInitial() + _radiusFactor * _grid.getRadius() * cos(radianAngle));
		_asteroidPos.setYpos(_asteroidPos.getYposInitial() + _radiusFactor * _grid.getRadius() * sin(radianAngle));
		_radiusFactor += _radiusIncrease;
	}
	else 
	{
		_aliveStatus = false;
	}	
}

bool Asteroid::isAlive()
{
	return _aliveStatus;
}

bool Asteroid::getRespawn()
{
	return false;
}

void Asteroid::setDead()
{   
	_aliveStatus = false;
}

float Asteroid::getHitRadius()
{
	return _hitRadius;
}