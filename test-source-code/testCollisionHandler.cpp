#include "CollisionHandler.h"
#include "Grid.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "PlayerBullet.h"
#include "Satellite.h"
#include "Player.h"
#include "LaserGenerator.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("CollisionHandler is initialized with the correct attributes")
{
    CollisionHandler collisionHandler{};
    
    CHECK(collisionHandler.getPoints() == 0);
    CHECK(collisionHandler.getEnemiesKilled() == 0);
    CHECK_FALSE(collisionHandler.isWeaponUpgradable());
}

TEST_CASE("PlayerBullet collides with enemy")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(enemy_ptr->getPosition() ,grid, bulletNumber);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(enemy_ptr);
    gameObjects.push_back(playerBullet_ptr);
    collisionHandler.checkCollisions(gameObjects);
    bool isEnemyAlive = gameObjects[0]->isAlive();
    bool isPlayerBulletAlive = gameObjects[1]->isAlive();
    
    CHECK_FALSE(isEnemyAlive);
    CHECK_FALSE(isPlayerBulletAlive);
    
}

TEST_CASE("PlayerBullet collides with Satellite")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    auto bulletNumber = 0;
    int directionAngle = 20;
    int numSatellite= 1;
    shared_ptr<IMovingEntity> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(satellite_ptr->getPosition() ,grid, bulletNumber);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(satellite_ptr);
    gameObjects.push_back(playerBullet_ptr);
    collisionHandler.checkCollisions(gameObjects);
    bool isSatelliteAlive = gameObjects[0]->isAlive();
    bool isPlayerBulletAlive = gameObjects[1]->isAlive();
    
    CHECK_FALSE(isSatelliteAlive);
    CHECK_FALSE(isPlayerBulletAlive);
    
}

TEST_CASE("PlayerBullet collides with LaserGenerator")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    auto bulletNumber = 0;
    int startAngle = 0;
    int laserGenNumber = 1;
    shared_ptr<IMovingEntity> laserGen_ptr = make_shared<LaserGenerator>(grid,startAngle,laserGenNumber);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(laserGen_ptr->getPosition() ,grid, bulletNumber);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(laserGen_ptr);
    gameObjects.push_back(playerBullet_ptr);
    collisionHandler.checkCollisions(gameObjects);
    bool isLaserGenAlive = gameObjects[0]->isAlive();
    bool isPlayerBulletAlive = gameObjects[1]->isAlive();
    
    CHECK_FALSE(isLaserGenAlive);
    CHECK_FALSE(isPlayerBulletAlive);
}


TEST_CASE("LaserGenerator collides with player")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    int startAngle = 0;
    int laserGenNumber = 1;
    shared_ptr<IMovingEntity> laserGen_ptr = make_shared<LaserGenerator>(grid,startAngle,laserGenNumber);
    shared_ptr<Player> player_ptr = make_shared<Player>(grid);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(laserGen_ptr);
    gameObjects.push_back(player_ptr);
    
    while (laserGen_ptr->getPosition().getRadius() < grid.getRadius())
        laserGen_ptr->move();
    laserGen_ptr->move();
    
    player_ptr->setDirection(Direction::ANTICLOCKWISE);
    auto laserGenAngle = laserGen_ptr->getPosition().getAngle();
    for (auto i = 0; i != laserGenAngle; i++) player_ptr->move();
    
    collisionHandler.checkCollisions(gameObjects);
    bool isLaserGenAlive = gameObjects[0]->isAlive();
    bool isPlayerRespawnable = gameObjects[1]->getRespawn();
    
    CHECK_FALSE(isLaserGenAlive);
    CHECK_FALSE(isPlayerRespawnable);
}

TEST_CASE("Asteroid collides with player")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    shared_ptr<IMovingEntity> asteroid_ptr = make_shared<Asteroid>(grid);
    shared_ptr<Player> player_ptr = make_shared<Player>(grid);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(asteroid_ptr);
    gameObjects.push_back(player_ptr);
    
    while (asteroid_ptr->getPosition().getRadius() < grid.getRadius())
        asteroid_ptr->move();
    asteroid_ptr->move();
        
    player_ptr->setDirection(Direction::ANTICLOCKWISE);
    auto asteroidAngle = asteroid_ptr->getPosition().getAngle();
    for (auto i = 0; i != asteroidAngle; i++) player_ptr->move();
    
    collisionHandler.checkCollisions(gameObjects);
    bool isAsteroidGenAlive = gameObjects[0]->isAlive();
    bool isPlayerRespawnable = gameObjects[1]->getRespawn();
    
    CHECK_FALSE(isAsteroidGenAlive);
    CHECK_FALSE(isPlayerRespawnable);
}

TEST_CASE("Enemy collides with player")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
    shared_ptr<Player> player_ptr = make_shared<Player>(grid);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(enemy_ptr);
    gameObjects.push_back(player_ptr);
    
    while (enemy_ptr->getPosition().getRadius() < grid.getRadius())
        enemy_ptr->move();
    enemy_ptr->move();
        
    player_ptr->setDirection(Direction::ANTICLOCKWISE);
    auto asteroidAngle = enemy_ptr->getPosition().getAngle();
    for (auto i = 0; i != asteroidAngle; i++) player_ptr->move();
    
    collisionHandler.checkCollisions(gameObjects);
    bool isEnemyAlive = gameObjects[0]->isAlive();
    bool isPlayerRespawnable = gameObjects[1]->getRespawn();
    
    CHECK_FALSE(isEnemyAlive);
    CHECK_FALSE(isPlayerRespawnable);
}

TEST_CASE("Enemy Bullet collides with player")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    
    shared_ptr<Player> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> enemyBullet_ptr = make_shared<EnemyBullet>(player_ptr->getPosition(), grid);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(player_ptr);
    gameObjects.push_back(enemyBullet_ptr);

    collisionHandler.checkCollisions(gameObjects);
    bool isPlayerRespanable = gameObjects[0]->getRespawn();
    bool isEnemyBulletAlive = gameObjects[1]->isAlive();
    
    CHECK_FALSE(isEnemyBulletAlive);
    CHECK_FALSE(isPlayerRespanable);
    
}

TEST_CASE("Laser Field collides with player")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    int directionAngle = 20;
    int location = 1;
    shared_ptr<Player> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> laserField_ptr = make_shared<LaserField>(grid,directionAngle,location);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(player_ptr);
    gameObjects.push_back(laserField_ptr);

    collisionHandler.checkCollisions(gameObjects);
    bool isPlayerRespanable = gameObjects[0]->getRespawn();
    bool isLaserFieldAlive = gameObjects[1]->isAlive();
    
    CHECK_FALSE(isPlayerRespanable);
    CHECK_FALSE(isLaserFieldAlive);
}

TEST_CASE("Check Player Bullet can not collide with player")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<Player> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(player_ptr);
    gameObjects.push_back(playerBullet_ptr);

    collisionHandler.checkCollisions(gameObjects);
    bool isPlayerAlive = gameObjects[0]->isAlive();
    bool isPlayerBulletAlive = gameObjects[1]->isAlive();
    
    CHECK(isPlayerAlive);
    CHECK(isPlayerBulletAlive);
}

TEST_CASE("Check Player Bullet can not collide with player")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<Player> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(player_ptr);
    gameObjects.push_back(playerBullet_ptr);

    collisionHandler.checkCollisions(gameObjects);
    bool isPlayerAlive = gameObjects[0]->isAlive();
    bool isPlayerBulletAlive = gameObjects[1]->isAlive();
    
    CHECK(isPlayerAlive);
    CHECK(isPlayerBulletAlive);
}

TEST_CASE("Check Enemies cant collide with each other")
{
    CollisionHandler collisionHandler{};
    Grid grid{800, 600};
    int directionAngle = 20;
    int numSatellite= 1;
    int startAngle = 0;
    int laserGenNumber = 1;
    shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
    shared_ptr<IMovingEntity> enemyBullet_ptr = make_shared<EnemyBullet>(enemy_ptr->getPosition(), grid);    
    shared_ptr<IMovingEntity> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
    shared_ptr<IMovingEntity> laserGen_ptr = make_shared<LaserGenerator>(grid,startAngle,laserGenNumber);
    shared_ptr<IMovingEntity> asteroid_ptr = make_shared<Asteroid>(grid);
    
    vector<shared_ptr<IMovingEntity>> gameObjects;
    gameObjects.push_back(enemy_ptr);
    gameObjects.push_back(enemyBullet_ptr);
    gameObjects.push_back(satellite_ptr);
    gameObjects.push_back(laserGen_ptr);
    gameObjects.push_back(asteroid_ptr);

    collisionHandler.checkCollisions(gameObjects);
    bool isEnemyAlive = gameObjects[0]->isAlive();
    bool isEnemyBulletAlive = gameObjects[1]->isAlive();
    bool isSatelliteAlive = gameObjects[2]->isAlive();
    bool isLaserGenAlive = gameObjects[3]->isAlive();
    bool isAsteroidAlive = gameObjects[4]->isAlive();
    
    CHECK(isEnemyAlive);
    CHECK(isEnemyBulletAlive);
    CHECK(isSatelliteAlive);
    CHECK(isLaserGenAlive);
    CHECK(isAsteroidAlive);
}