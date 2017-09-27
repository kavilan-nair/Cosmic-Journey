#ifndef BULLET_H
#define BULLET_H

#include "Position.h"
#include "GameWindowProperties.h"

class Bullet
{
	public:
		Bullet(Position position, GameWindowProperties gameWindowProperties, int bulletNumber);
		~Bullet();
		Position getPosition() {return _positionBullet;};
		bool isBulletAlive() {return _aliveStatus;};
        void setBulletDead() {_aliveStatus = false;};
		void updateBullet();
        int getBulletRadius(){return _bulletRadius;}; //this should be moved to the radius in the position data member
	public:
		static constexpr float PI = 3.14159265358979323846;
		float originFix = PI/2;
	private:
		Position _positionBullet;
		GameWindowProperties _gameWindowProperties;
		bool _aliveStatus;
		int _bulletRadius;
		
};

#endif //BULLET_H