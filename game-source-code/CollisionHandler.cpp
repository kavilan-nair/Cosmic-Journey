#include "CollisionHandler.h"

void CollisionHandler::checkCollisions(vector<shared_ptr<IMovingEntity>>& gameObjects)
{
    for (auto &gameObject1 : gameObjects)
    {
        for(auto &gameObject2 : gameObjects)
        {
            playerBulletCollidesWithEnemies(gameObject1, gameObject2);
            enemyCollidesWithPlayers(gameObject1, gameObject2);
            playerBulletCollidesWithSatellites(gameObject1, gameObject2);
            playerBulletCollidesWithLaserGenerator(gameObject1, gameObject2);
            laserFieldCollidesWithPlayer(gameObject1, gameObject2);
            asteroidCollidesWithPlayer(gameObject1, gameObject2);
        }
    }
    updateLaserGenerators(gameObjects);
}


void CollisionHandler::playerBulletCollidesWithEnemies(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2)
{
    if (gameObject1->getEntityType() == EntityType::PLAYER_BULLET && gameObject2->getEntityType() == EntityType::ENEMY && gameObject2->isAlive())
    {
        float distance = getDistance(gameObject1, gameObject2);
        if (distance < gameObject2->getHitRadius())
        {
            gameObject1->setDead();
            gameObject2->setDead();
            _points += 25*_pointsMultiplier;
            _enemiesKilled++;
        }
    }
}

void CollisionHandler::enemyCollidesWithPlayers(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2)
{
    if ( ((gameObject1->getEntityType() == EntityType::ENEMY) || (gameObject1->getEntityType() == EntityType::ENEMY_BULLET) )&& gameObject2->getEntityType() == EntityType::PLAYER)
    {
        float distance = getDistance(gameObject1, gameObject2);
        if (distance < gameObject2->getHitRadius())
        {
            gameObject1->setDead();
            gameObject2->setDead();
            resetMultiplier();
            if (gameObject1->getEntityType() == EntityType::ENEMY)
                _enemiesKilled++;
        }
    }
}

void CollisionHandler::playerBulletCollidesWithSatellites(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2)
{
    if (gameObject1->getEntityType() == EntityType::PLAYER_BULLET && gameObject2->getEntityType() == EntityType::SATELLITE && gameObject2->isAlive())
    {
        float distance = getDistance(gameObject1, gameObject2);
        if (distance < gameObject2->getHitRadius())
        {
            gameObject1->setDead();
            gameObject2->setDead();
            _points += 50*_pointsMultiplier;
            _satellitesKilled++;
            _enemiesKilled++;
        }
    }
}

bool CollisionHandler::isWeaponUpgradable()
{
    if (_satellitesKilled == 3)
    {
        _pointsMultiplier = 2;
        _satellitesKilled = 0;
        return true;
    }
    else
        return false;
}

float CollisionHandler::getDistance(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2)
{
    float distance =  sqrt(pow( (gameObject1->getPosition().getXpos() - gameObject2->getPosition().getXpos() ), 2) + pow( (gameObject1->getPosition().getYpos() - gameObject2->getPosition().getYpos() ), 2) );
    return distance;
}

int CollisionHandler::getPoints()
{
    int points = _points;
    _points = 0;
    return points;
}

void CollisionHandler::playerBulletCollidesWithLaserGenerator(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2)
{
    if (gameObject1->getEntityType() == EntityType::PLAYER_BULLET && gameObject2->getEntityType() == EntityType::LASER_GENERATOR)
    {
        float distance = getDistance(gameObject1, gameObject2);
        if (distance < gameObject2->getHitRadius())
        {
            gameObject1->setDead();
            gameObject2->setDead();
             _points += 100*_pointsMultiplier;
        }
    }
}

void CollisionHandler::laserFieldCollidesWithPlayer(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2)
{
    if ((gameObject1->getEntityType() == EntityType::LASER_GENERATOR || gameObject1->getEntityType() == EntityType::LASER_FIELD)  && gameObject2->getEntityType() == EntityType::PLAYER)
    {
        float distance = getDistance(gameObject1, gameObject2);
        if (distance < gameObject2->getHitRadius())
        {
            gameObject1->setDead();
            gameObject2->setDead();
            resetMultiplier();
        }
    }
}

void CollisionHandler::asteroidCollidesWithPlayer(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2)
{
    if ((gameObject1->getEntityType() == EntityType::ASTEROID || gameObject1->getEntityType() == EntityType::LASER_FIELD)  && gameObject2->getEntityType() == EntityType::PLAYER)
    {
        float distance = getDistance(gameObject1, gameObject2);
        if (distance < gameObject2->getHitRadius())
        {
            gameObject1->setDead();
            gameObject2->setDead();
            resetMultiplier();
        }
    }
}

void CollisionHandler::updateLaserGenerators(vector<shared_ptr<IMovingEntity>>& gameObjects)
{
    int numberOfLaserGenerators = 0;
    for (auto &gameObject : gameObjects)
    {
        if(gameObject->getEntityType() == EntityType::LASER_GENERATOR)
            numberOfLaserGenerators++;
    }
    
    if(numberOfLaserGenerators == 0 || numberOfLaserGenerators == 1)
    {
        for (auto &gameObject : gameObjects)
        {
            if(gameObject->getEntityType() == EntityType::LASER_FIELD)
                gameObject->setDead();
        }
    }
}

void CollisionHandler::resetMultiplier()
{
    _pointsMultiplier = 1;
}

int CollisionHandler::getEnemiesKilled()
{
    return _enemiesKilled;
}