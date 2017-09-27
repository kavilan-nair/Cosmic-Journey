#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "Enemy.h"
#include "Bullet.h"

class CollisionDetection
{
public:
    CollisionDetection();
    CollisionDetection(Enemy currEnemy, Bullet currBullet);
    ~CollisionDetection();

};

#endif // COLLISIONDETECTION_H
