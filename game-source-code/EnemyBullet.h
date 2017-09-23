#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "Position.h"
#include "GameWindowProperties.h"

class EnemyBullet
{
    public:
        EnemyBullet();
        EnemyBullet(Position position, GameWindowProperties gameWindowProperties);
        Position getPosition() {return _positionSpawn;};
        bool isEnemyBulletAlive() {return _isAlive;};
        void updateEnemyBullet();
        void setEnemyBulletPosition(Position position) {_positionSpawn = position;};
        void setEnemyBulletGameWindowProperties(GameWindowProperties gameWindowProperties) {_gameWindowProperties = gameWindowProperties;};
        ~EnemyBullet();        
    public:
        const float PI = 3.14159265358979323846;
		float originFix = PI/2;


    private:
        Position _positionSpawn;
        GameWindowProperties _gameWindowProperties;
        bool _isAlive;
        int _enemyBulletRadius;
        int _enemyBulletSpeed;
        float _factor = 0.01;

};







#endif