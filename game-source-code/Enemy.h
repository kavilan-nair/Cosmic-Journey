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
		
		&getPositionX(){return _coordinateX;};
		&getPositionY(){return _coordinateY;};
		setAlive();
		isAlive();
		move();
private:
		int _coordinateX;
		int _coordinateY;
		bool _alive = false;
		int Pos1 = 0;
		int Pos2 = 0;
};




#endif // ENEMY_H