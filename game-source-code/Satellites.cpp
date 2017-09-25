#include "Satellites.h"
#include "GameWindowProperties.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <SFML/system.hpp>
#include <iostream>

Satellites::Satellites()
{
	
}

Satellites::Satellites(GameWindowProperties gameWindowProperties, int inDirection, int numShip)
{
	setAlive();
	int randomStart = 0;
	if(numShip == 1)
	{
		 randomStart = inDirection;
	}
	else if(numShip == 2)
	{
		 randomStart = inDirection+5;
	}
	else
	{
		 randomStart = inDirection-5;
	}
	
	_satellitesPosition.setAngle(randomStart);
	_satellitesPosition.setRadius(gameWindowProperties.getRadius());
	_satellitesPosition.setoriginX(gameWindowProperties.getXOrigin());
	_satellitesPosition.setoriginY(gameWindowProperties.getYOrigin());
    _satellitesPosition.setX(gameWindowProperties.getXOrigin());
    _satellitesPosition.setY(gameWindowProperties.getYOrigin());
    _gameWindowProperties = gameWindowProperties;
	gyrateRadius = 0.05*_satellitesPosition.getRadius();
}

void Satellites::move()
{	
	if(times <= 10)
	{
		auto rad = (_satellitesPosition.getAngle() * PI/180)*3;
		_satellitesPosition.setX(_satellitesPosition.getoriginX() + factor*_satellitesPosition.getRadius()*cos(rad));
		_satellitesPosition.setY(_satellitesPosition.getoriginY() + factor*_satellitesPosition.getRadius()*sin(rad));
		factor += 0.05;
		times++;
	}
	
	if(times == 11)
	{	
		_satellitesPosition.setoriginX(_satellitesPosition.getX());
		_satellitesPosition.setoriginY(_satellitesPosition.getY());
		//_satellitesPosition.setAngle(1);			
		setGyrate = true;
		times++;
	}
	
	if(times > 11)
	{	
		float rad = (_satellitesPosition.getAngle() * PI/180)*3;
		auto X = gyrateRadius*cos(rad);
		auto Y = gyrateRadius*sin(rad);
		_satellitesPosition.setX(_satellitesPosition.getoriginX() + X);
		_satellitesPosition.setY(_satellitesPosition.getoriginY() + Y);
		_satellitesPosition.setAngle((_satellitesPosition.getAngle()+1)%360);
	}
}
