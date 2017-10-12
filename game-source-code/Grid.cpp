#include "Grid.h"

Grid::Grid(const int& width, const int& height) : _width(width), _height(height)
{
	_centerX = _width/2;
	_centerY = _height/2;
	_radius = (_height/2)*0.95;
}

Grid::~Grid()
{
}

int Grid::getWidth() const 
{
	return _width;
}

int Grid::getHeight() const 
{
	return _height;
}

int Grid::getCenterX() const 
{
	return _centerX;
}

int Grid::getCenterY() const 
{
	return _centerY;
}

int Grid::getRadius() const 
{
	return _radius;
}
