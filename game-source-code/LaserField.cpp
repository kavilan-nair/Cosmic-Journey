#include "LaserField.h"
#include <stdlib.h>

LaserField::LaserField(const Grid& grid, int Angle, const int& Location) 
    : _grid(grid), 
    _aliveStatus(true), 
    _phase(0),
    _radiusFactor(0.005),
    _hitRadius(6),
    _radiusIncrease(0.001)	
{	
    switch(Location)
    {
        case 1: Angle = Angle -15; break;
        case 2: Angle = Angle -10; break;
        case 3: Angle = Angle -5;  break;
        case 4: Angle = Angle;     break;
        case 5: Angle = Angle +5;  break;
        case 6: Angle = Angle +10; break;
        case 7: Angle = Angle +15; break;
    }
    
    _laserFieldPos.setAngle(Angle);
    _laserFieldPos.setRadius(0);
    _laserFieldPos.setXposInitial(grid.getCenterX()); 
    _laserFieldPos.setYposInitial(grid.getCenterY());
    _laserFieldPos.setXpos(grid.getCenterX());
    _laserFieldPos.setYpos(grid.getCenterY());
}

LaserField::~LaserField()
{
}

Position LaserField::getPosition()
{
    return _laserFieldPos;
}

EntityType LaserField::getEntityType()
{
     return EntityType::LASER_FIELD;
} 

void LaserField::move()
{
    _phase++;
    switch(_phase)
    {
        case 1: _oscillationFactor = 1;  break;
        case 2: _oscillationFactor = 2;  break;
        case 3: _oscillationFactor = 3;  break;
        case 4: _oscillationFactor = 4;  break;
        case 5: _oscillationFactor = -4; break;
        case 6: _oscillationFactor = -3; break;
        case 7: _oscillationFactor = -2; break;
        case 8: _oscillationFactor = -1; break;
        case 9: _oscillationFactor = 0; _phase = 0; break;
    }
    
    if (_laserFieldPos.getRadius() < _grid.getRadius())
    {
        auto radianAngle = ((_laserFieldPos.getAngle()+_oscillationFactor) * M_PI/180);
        _laserFieldPos.setRadius(_laserFieldPos.getRadius()  + _radiusFactor);
        _laserFieldPos.setXpos(_laserFieldPos.getXposInitial() + _radiusFactor * _grid.getRadius() * cos(radianAngle));
        _laserFieldPos.setYpos(_laserFieldPos.getYposInitial() + _radiusFactor * _grid.getRadius() * sin(radianAngle));
        _radiusFactor += _radiusIncrease;
    }
    else 
    {
        _aliveStatus = false;
    }	
}

bool LaserField::isAlive()
{
    return _aliveStatus;
}

bool LaserField::getRespawn()
{
    return false;
}

void LaserField::setDead()
{
    _aliveStatus = false;
}

float LaserField::getHitRadius()
{
    return _hitRadius;
}