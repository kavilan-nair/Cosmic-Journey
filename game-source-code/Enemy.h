#ifndef ENEMY_H
#define ENEMY_H
#include "Position.h"
#include "GameWindowProperties.h"
#include <vector>
#include <SFML/system.hpp>

class Enemy
{
	public:
		Enemy();
		Enemy(GameWindowProperties gameWindowProperties);
        bool& isAlive(){return _aliveStatus;};
        void setDead(){_aliveStatus = false;};
        void setAlive(){_aliveStatus = true;};
		void move();
		Position& getPosition(){return _enemyPosition;};
	public:
		float factor = 0.01;
		float PI = atan(1)*4; //if you put const, some other shit goes down
	private:
		Position _enemyPosition;
        bool _aliveStatus;
};

#endif // ENEMY_H