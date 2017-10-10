#include "Player.h"
#include <Functional>

Player::Player(const Grid& grid) : _grid(grid), _playerBullet(_playerPos, _grid, 1) 
{
	_aliveStatus = true;
	_direction = Direction::HOVER;
    _playerPos.setAngle(0);
    _playerPos.setXpos(grid.getCenterX());
    _playerPos.setYpos(grid.getCenterY() + grid.getRadius());
    _playerPos.setRadius(grid.getRadius());
    _playerPos.setXposInitial(grid.getCenterX());  
    _playerPos.setYposInitial(grid.getCenterY());
}

Player::~Player()
{
}

Position Player::getPosition()
{
    return _playerPos;
}

EntityType Player::getEntityType()
{
    return EntityType::PLAYER;
}

void Player::move()
{
	
    if (getDirection() == Direction::CLOCKWISE)
        _playerPos.setAngle(_playerPos.getAngle() - 1);
    else if(getDirection() == Direction::ANTICLOCKWISE)
        _playerPos.setAngle(_playerPos.getAngle() + 1);
        
    auto radianAngle = (_playerPos.getAngle() * M_PI / 180)* 0.5;
    int newXPos = _playerPos.getXposInitial() + _playerPos.getRadius() * cos(radianAngle - M_PI_2);
    int newYPos = _playerPos.getYposInitial() - _playerPos.getRadius() * sin(radianAngle - M_PI_2);
    _playerPos.setXpos(newXPos);
    _playerPos.setYpos(newYPos);        
}
vector<shared_ptr<IMovingEntity>> Player::shoot()
{
    vector<shared_ptr<IMovingEntity>> bulletVector;
    
    if (_weaponType == WeaponType::SINGLE)
         bulletVector.push_back(std::make_shared<PlayerBullet>(_playerPos, _grid, 1));    
    
    if (_weaponType == WeaponType::DOUBLE)
    {
        bulletVector.push_back(std::make_shared<PlayerBullet>(_playerPos, _grid, 2));
        bulletVector.push_back(std::make_shared<PlayerBullet>(_playerPos, _grid, 3));
    }    
    
   
    return bulletVector;
}

bool Player::isAlive()
{
	return _aliveStatus;
}

Direction Player::getDirection()
{
	return _direction;
}

void Player::setDirection(const Direction& direction)
{
	_direction = direction;
}

bool Player::getRespawn()
{
	return false;
}

void Player::setDead()
{   
    _aliveStatus = false;
    respawn();
}

float Player::getHitRadius()
{
    return _hitRadius;
}

void Player::respawn()
{
    _lives--;
    _weaponType = WeaponType::SINGLE;
    _aliveStatus = true;
	_direction = Direction::HOVER;
    _playerPos.setAngle(0);
    _playerPos.setXpos(_grid.getCenterX());
    _playerPos.setYpos(_grid.getCenterY() + _grid.getRadius());
    _playerPos.setRadius(_grid.getRadius());
    _playerPos.setXposInitial(_grid.getCenterX());  
    _playerPos.setYposInitial(_grid.getCenterY());
}

bool Player::isGameOver()
{
    if (_lives <= 0)
        return true;
    else
        return false;
}

void Player::upgradeWeaponDouble()
{
    _weaponType = WeaponType::DOUBLE;
}

void Player::upgradeWeaponTriple()
{
    _weaponType = WeaponType::TRIPLE;
}

WeaponType Player::getWeaponType()
{
    return _weaponType;
}

int Player::getLives()
{
    return _lives;
}
int Player::addScore(const int& points)
{
    _score += points;
    return _score;
}
int Player::getScore()
{
    return _score;
}