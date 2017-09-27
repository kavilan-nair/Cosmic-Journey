#ifndef PLAYER_H
#define PLAYER_H
#include "Position.h"
#include "GameWindowProperties.h"
#include <cmath>
#include "WeaponType.h"

class Player
{
	public:
        Player();
        Player(GameWindowProperties gameWindowProperties);
        void setPosition(Position position) { _position = position;};
        Position getPosition() { return _position;};
        void moveClockwise();
        void moveAntiClockwise();
        GameWindowProperties getWindowProperties(){return _gameWindowProperties;};
        void decreaseLives();
        int getLives(){return _lives;};
        bool isDead(){return (!_isAlive);};
        void respawn();
        void upgradeWeaponDouble(){_weaponType = WeaponType::Double;};
        void upgradeWeaponTriple(){_weaponType = WeaponType::Triple;};
        WeaponType getWeaponType(){return _weaponType;};
		~Player();
        
	public:
		float PI = atan(1)*4;  //same issue with making this const, breaks like a hoe
		float originFix = PI/2;

    private:
        Position _position;
        GameWindowProperties _gameWindowProperties;
        int _lives;
        bool _isAlive;
        WeaponType _weaponType;
};

#endif // PLAYER_H