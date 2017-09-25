#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "Position.h"
#include "GameWindowProperties.h"

class EnemyBullet
{
    public:
        EnemyBullet();
        EnemyBullet(Position position, GameWindowProperties gameWindowProperties, Position posPlayer);
        Position getPosition() {return _positionSpawn;};
        bool isEnemyBulletAlive() {return _isAlive;};
        void setEnemyBulletDead() {_isAlive = false;};
        void updateEnemyBullet();
        void setEnemyBulletPosition(Position position) {_positionSpawn = position;};
        void setEnemyBulletGameWindowProperties(GameWindowProperties gameWindowProperties) {_gameWindowProperties = gameWindowProperties;};
        ~EnemyBullet();        
    public:
        static constexpr float PI = 3.14159265358979323846;
		float originFix = PI/2;
int newX;
int newY;
int newRadius;
float newAngle;
private:
	Position _posPlayer;
        Position _positionSpawn;
        GameWindowProperties _gameWindowProperties;
        bool _isAlive;
        int _enemyBulletRadius;
        int _enemyBulletSpeed;
		int _playerPosition;
        float _factor = 0.1;
		int _countX = 0;
};







#endif