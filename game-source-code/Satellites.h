#ifndef SATELLITES_H
#define SATELLITES_H

#include "Position.h"
#include "GameWindowProperties.h"
#include "EnemyBullet.h"
#include <vector>
#include <SFML/system.hpp>

class Satellites
{
	public:
		Satellites();
		Satellites(GameWindowProperties gameWindowProperties);
        bool& isAlive(){return _aliveStatus;};
        void setDead(){_aliveStatus = false;};
        void setAlive(){_aliveStatus = true;};
		void move();
		Position& getPosition(){return _satellitesPosition;};
public:
		int times = 1;
		bool setGyrate = false;
		float factor = 0.05;
		bool beforeSet;
		float facGyrate = 0.05;
		float PI = atan(1)*4; //if you put const, some other shit goes down
        float gyrateRadius;
	private:
		Position _satellitesPosition;
        GameWindowProperties _gameWindowProperties;
        bool _aliveStatus;

       
};

#endif // ENEMY_H