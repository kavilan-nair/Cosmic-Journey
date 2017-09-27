#include "GameWindowProperties.h"
#include <iostream>

GameWindowProperties::GameWindowProperties()
{	
	
}

GameWindowProperties::GameWindowProperties(int width, int height)
{
	_width = width;
	_height = height;
	_xOrigin =  _width/2;
	_yOrigin = _height/2;
 
    if (_width < _height)_radius = 0.95 * _width/2;
    else _radius = 0.95 * _height/2;
}

void GameWindowProperties::displayProperties()
{
    std::cout << "Resolution Width: " << getWidth() << std::endl;
    std::cout << "Resolution Height: " << getHeight() << std::endl;
    std::cout << "Radius of the circle: " << getRadius() << std::endl;
    std::cout << "Origin of the screen: (" << getXOrigin() << "," << getYOrigin() << ")" << std::endl;
}

GameWindowProperties::~GameWindowProperties()
{
	
}