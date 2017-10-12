#include "LaserGenerator.h"
#include "LaserField.h"
#include "vector"

using namespace std;

LaserGenerator::LaserGenerator(const Grid& grid, int inDirection, const int& typeSide) 
    : _grid(grid), 
    _fieldLine(0),
    _aliveStatus(true),
    _originalAngle(inDirection),
    _radiusFactor(0.005),
    _hitRadius(15),
    _radiusIncrease(0.001)
{
    int angleFactor = 20;
    if(typeSide == 1)
    {
         inDirection += angleFactor;
    }
    else
    {
         inDirection -= angleFactor;
    }
    
    _laserGeneratorPos.setAngle(inDirection);
    _laserGeneratorPos.setRadius(0);
    _laserGeneratorPos.setXposInitial(grid.getCenterX()); 
    _laserGeneratorPos.setYposInitial(grid.getCenterY());
    _laserGeneratorPos.setXpos(grid.getCenterX());
    _laserGeneratorPos.setYpos(grid.getCenterY());
}

LaserGenerator::~LaserGenerator()
{
}

Position LaserGenerator::getPosition()
{
    return _laserGeneratorPos;
}
    
EntityType LaserGenerator::getEntityType()
{
    return EntityType::LASER_GENERATOR;
} 

void LaserGenerator::move()
{
    if (_laserGeneratorPos.getRadius() < _grid.getRadius())
    {
        auto radianAngle = (_laserGeneratorPos.getAngle() * M_PI/180);
        _laserGeneratorPos.setRadius(_laserGeneratorPos.getRadius()  + _radiusFactor);
        _laserGeneratorPos.setXpos(_laserGeneratorPos.getXposInitial() + _radiusFactor * _grid.getRadius() * cos(radianAngle));
        _laserGeneratorPos.setYpos(_laserGeneratorPos.getYposInitial() + _radiusFactor * _grid.getRadius() * sin(radianAngle));
        _radiusFactor += _radiusIncrease;
    }
    else 
    {
        _aliveStatus = false;
    }	
}

bool LaserGenerator::isAlive()
{
    return _aliveStatus;
}

vector<shared_ptr<IMovingEntity>> LaserGenerator::shoot() 
{
    _fieldLine++;
    if(_fieldLine == 8){_fieldLine = 1 ;}
    
    vector<shared_ptr<IMovingEntity>> laserFieldVector; 
    laserFieldVector.push_back(std::make_shared<LaserField>(_grid,_originalAngle,_fieldLine));
    return laserFieldVector;
}
 
bool LaserGenerator::getRespawn() 
{
    return false;
}

void LaserGenerator::setDead()
{
    _aliveStatus = false;
}

float LaserGenerator::getHitRadius()
{
    return _hitRadius;
}