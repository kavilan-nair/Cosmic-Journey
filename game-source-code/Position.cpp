#include "Position.h"

Position::Position()
{
}

Position::~Position()
{
}

int Position::getXpos() const
{
    return _xPos;
}

int Position::getYpos() const
{
    return _yPos;
}

int Position::getRadius() const
{
    return _radius;
}

int Position::getAngle() const
{
    return _angle;
}

int Position::getXposInitial() const
{
    return _xPosInitial;
}

int Position::getYposInitial() const 
{
    return _yPosInitial;
}

void Position::setXpos(int xPos)
{
    _xPos = xPos;
}

void Position::setYpos(int yPos)
{
    _yPos = yPos;
}

void Position::setRadius(int radius)
{
    _radius = radius;
}

void Position::setAngle(int angle)
{
    _angle = angle;
}

void Position::setXposInitial(int xPosInitial)
{
    _xPosInitial = xPosInitial;
}

void Position::setYposInitial(int yPosInitial)
{
    _yPosInitial = yPosInitial;
}