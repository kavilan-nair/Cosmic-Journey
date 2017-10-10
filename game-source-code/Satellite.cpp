#include "Satellite.h"

Satellite::Satellite(const Grid& grid, int& inDirection,const int& numSatellite) : _grid(grid)
{
	_aliveStatus = true;
	int startingPosition = 0;
    if(numSatellite == 1) 
	{
		startingPosition = inDirection;
    } 
	else if(numSatellite == 2) 
	{
		startingPosition = inDirection + 20;
    } 
	else 
	{
		startingPosition = inDirection - 20;
    }

	_satellitePos.setAngle(startingPosition);
	_satellitePos.setRadius(grid.getRadius());
	_satellitePos.setXposInitial(grid.getCenterX());
	_satellitePos.setYposInitial(grid.getCenterY());
	_satellitePos.setXpos(grid.getCenterX());
	_satellitePos.setYpos(grid.getCenterY());
	_gyrationRadius = 0.12 * _satellitePos.getRadius();
}

Position Satellite::getPosition() 
{
	return _satellitePos;
}

EntityType Satellite::getEntityType() 
{
	return EntityType::SATELLITE;
}

void Satellite::move() 
{
	if(_lifeCycle <= 10) 
	{
		auto radianAngle = (_satellitePos.getAngle() * M_PI/180);
		_satellitePos.setXpos(_satellitePos.getXposInitial() + _factor * _satellitePos.getRadius() * cos(radianAngle));
		_satellitePos.setYpos(_satellitePos.getYposInitial() + _factor * _satellitePos.getRadius() * sin(radianAngle));
		_factor += 0.05;
		_lifeCycle++;
    }

    if(_lifeCycle == 11) 
	{
		_satellitePos.setXposInitial(_satellitePos.getXpos());
		_satellitePos.setYposInitial(_satellitePos.getYpos());
		_lifeCycle++;
    }

    if(_lifeCycle > 11) 
	{
		if(_lifeCycle%3 == 0)
		{
            float radianAngle = (_satellitePos.getAngle() * M_PI/180);
            auto X = _gyrationRadius * cos(radianAngle);
            auto Y = _gyrationRadius * sin(radianAngle);
            _satellitePos.setXpos(_satellitePos.getXposInitial() + X);
            _satellitePos.setYpos(_satellitePos.getYposInitial() + Y);
            _satellitePos.setAngle((_satellitePos.getAngle() + 1) % 360);
		}
		_lifeCycle++;
    }
}

bool Satellite::isAlive() 
{
	return _aliveStatus;
}

vector<shared_ptr<IMovingEntity>> Satellite::shoot()  
{
    vector<shared_ptr<IMovingEntity>> enemyBulletVector; 
	if(_lifeCycle > 11)
	{
		enemyBulletVector.push_back(std::make_shared<EnemyBullet>(_satellitePos, _grid));
	}
    return enemyBulletVector;
}

bool Satellite::getRespawn() 
{
	return false;
}

Satellite::~Satellite()
{
}

void Satellite::setDead()
{
    _aliveStatus = false;
}

float Satellite::getHitRadius()
{
    return _hitRadius;
}