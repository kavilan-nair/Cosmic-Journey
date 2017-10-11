#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "IMovingEntity.h"
#include <vector>
#include <memory>
#include <cmath>

using std::vector;
using std::shared_ptr;

class CollisionHandler
{
public:
    void checkCollisions(vector<shared_ptr<IMovingEntity>>& gameObjects);
    bool isWeaponUpgradable();
    int getPoints();
	int getEnemiesKilled();
    
private:
    float getDistance(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
    void playerBulletCollidesWithEnemies(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
    void enemyCollidesWithPlayers(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
    void playerBulletCollidesWithSatellites(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
    void playerBulletCollidesWithLaserGenerator(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
    void laserFieldCollidesWithPlayer(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
    void asteroidCollidesWithPlayer(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
    void updateLaserGenerators(vector<shared_ptr<IMovingEntity>>& gameObjects);
    void resetMultiplier();
    
    bool _areSatellitesDestroyed;
    int _satellitesKilled;
    int _points;
	int _pointsMultiplier;
    int _enemiesKilled;
};

#endif // COLLISIONHANDLER_H