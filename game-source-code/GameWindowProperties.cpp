#include "GameWindowProperties.h"

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

GameWindowProperties::~GameWindowProperties()
{
	
}