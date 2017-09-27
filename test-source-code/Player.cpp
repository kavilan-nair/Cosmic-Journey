#include "Player.h"
#include "GameWindowProperties.h"
#include <cmath>


Player::Player()
{
   
}

Player::Player(GameWindowProperties gameWindowProperties)
{
    _gameWindowProperties = gameWindowProperties;
    _position.setAngle(0.f);
    _position.setX(_gameWindowProperties.getXOrigin());
    _position.setY(_gameWindowProperties.getYOrigin() + _gameWindowProperties.getRadius());
    _isAlive = true;
    _lives = 5;
    _weaponType = WeaponType::Single;
}

void Player::moveClockwise()
{
        _position.setAngle(_position.getAngle() + 1);
        auto rad = (_position.getAngle() * PI/180)*5;
        int xPosition = _gameWindowProperties.getXOrigin() + _gameWindowProperties.getRadius()*cos(rad-originFix);
		int yPosition = _gameWindowProperties.getYOrigin() - _gameWindowProperties.getRadius()*sin(rad-originFix);
        _position.setX(xPosition);
        _position.setY(yPosition);
}


void Player::moveAntiClockwise()
{
        _position.setAngle(_position.getAngle() - 1);
        auto rad = (_position.getAngle() * PI/180)*5;
        int xPosition = _gameWindowProperties.getXOrigin() + _gameWindowProperties.getRadius()*cos(rad-originFix);
		int yPosition = _gameWindowProperties.getYOrigin() - _gameWindowProperties.getRadius()*sin(rad-originFix);
        _position.setX(xPosition);
        _position.setY(yPosition);
}

void Player::respawn()
{
    _position.setAngle(0.f);
    _position.setX(_gameWindowProperties.getXOrigin());
    _position.setY(_gameWindowProperties.getYOrigin() + _gameWindowProperties.getRadius());
}

void Player::decreaseLives()
{
    if (_lives != 1) //when it was 0, the player has an extra life for some odd reason
        _lives--;
    else
        _isAlive = false;
}

Player::~Player()
{

}