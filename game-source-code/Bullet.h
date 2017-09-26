#ifndef BULLET_H
#define BULLET_H

#include "Position.h"
#include "GameWindowProperties.h"

class Bullet
{
	public:
		Bullet();
		Bullet(Position position, GameWindowProperties gameWindowProperties, int bulletNumber);
		Position getPosition() {return _positionSpawn;};
		bool isBulletAlive() {return _isAlive;};
        void setBulletDead() {_isAlive = false;};
		void updateBullet();
		~Bullet();
	public:
		static constexpr float PI = 3.14159265358979323846;
		float originFix = PI/2;
	
	private:
		Position _positionSpawn;
		GameWindowProperties _gameWindowProperties;
		bool _isAlive;
		int _bulletRadius;
		
};

#endif //BULLET_H