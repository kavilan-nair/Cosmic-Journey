#include "Player.h"
#include "GameWindowProperties.h"
#include <cmath>

const auto PI = 3.14159265358979323846;
auto originFix1 = PI/2;

Player::Player()
{
   
}

Player::Player(GameWindowProperties gameWindowProperties)
{
       _gameWindowProperties = gameWindowProperties;
       _position.setAngle(0.f);
       _position.setX(_gameWindowProperties.getXOrigin());
       _position.setY(_gameWindowProperties.getYOrigin() + _gameWindowProperties.getRadius());
}

void Player::moveClockwise()
{
    
        _position.setAngle(_position.getAngle() + 1);
        auto rad = (_position.getAngle() * PI/180)*5;
        int xPosition = _gameWindowProperties.getXOrigin() + _gameWindowProperties.getRadius()*cos(rad-originFix1);
		int yPosition = _gameWindowProperties.getYOrigin() - _gameWindowProperties.getRadius()*sin(rad-originFix1);
        _position.setX(xPosition);
        _position.setY(yPosition);
}


void Player::moveAntiClockwise()
{
        _position.setAngle(_position.getAngle() - 1);
        auto rad = (_position.getAngle() * PI/180)*5;
        int xPosition = _gameWindowProperties.getXOrigin() + _gameWindowProperties.getRadius()*cos(rad-originFix1);
		int yPosition = _gameWindowProperties.getYOrigin() - _gameWindowProperties.getRadius()*sin(rad-originFix1);
        _position.setX(xPosition);
        _position.setY(yPosition);
}

Player::~Player()
{

}