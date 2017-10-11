#include "Grid.h"
#include "PlayerBullet.h"
#include "Player.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("PlayerBullet is initialized with the correct attributes")
{
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);
    
    CHECK(playerBullet_ptr->getEntityType() == EntityType::PLAYER_BULLET);
    CHECK(playerBullet_ptr->isAlive());
    CHECK_FALSE(playerBullet_ptr->getRespawn());
    CHECK(playerBullet_ptr->getHitRadius() == 6);    
}

TEST_CASE("PlayerBullet spawns at player position")
{
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);
    
    auto playerPosX = player_ptr->getPosition().getXpos();
    auto playerPosY = player_ptr->getPosition().getYpos();
    auto playerBulletPosX = playerBullet_ptr->getPosition().getXpos();
    auto playerBulletPosY = playerBullet_ptr->getPosition().getYpos();
    
    CHECK(playerBulletPosX == playerPosX);
    CHECK(playerBulletPosY  == playerPosY);
}

TEST_CASE("PlayerBullet moves from its original position")
{
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);
    
    auto xPosBefore = playerBullet_ptr->getPosition().getXpos();
    auto yPosBefore = playerBullet_ptr->getPosition().getYpos();
    playerBullet_ptr->move();
    auto xPosAfter = playerBullet_ptr->getPosition().getXpos();
    auto yPosAfter = playerBullet_ptr->getPosition().getYpos();
    
    bool isPositionDifferent = (xPosAfter != xPosBefore || yPosAfter != yPosBefore);
    
    CHECK(isPositionDifferent);
}

TEST_CASE("PlayerBullet can be set dead")
{
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);

    playerBullet_ptr->setDead();
    CHECK_FALSE(playerBullet_ptr->isAlive());
}

TEST_CASE("PlayerBullet is set dead when it reaches near centre of grid")
{
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);
    
   while (playerBullet_ptr->getPosition().getRadius() > 15)
       playerBullet_ptr->move();
   playerBullet_ptr->move();
    
    CHECK_FALSE(playerBullet_ptr->isAlive());
}

TEST_CASE("PlayerBullet is fired at the correct angle")
{
    Grid grid{800, 600};
    auto bulletNumber = 0;
    shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber);
    
    auto playerAngle = player_ptr->getPosition().getAngle();
    auto playerBulletAngle = playerBullet_ptr->getPosition().getAngle();
    
    CHECK(playerBulletAngle == playerAngle);
}

TEST_CASE("PlayerBullets from upgraded gun is fired at the correct angle")
{
    Grid grid{800, 600};
    auto bulletNumber1 = 2;
    auto bulletNumber2 = 3;
    
    shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
    shared_ptr<IMovingEntity> playerBullet1_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber1);
    shared_ptr<IMovingEntity> playerBullet2_ptr = make_shared<PlayerBullet>(player_ptr->getPosition() ,grid, bulletNumber2);
    
    auto correctAngle1 = player_ptr->getPosition().getAngle() + 10;
    auto correctAngle2 = player_ptr->getPosition().getAngle() - 10;
    auto playerBullet1Angle = playerBullet1_ptr->getPosition().getAngle();
    auto playerBullet2Angle = playerBullet2_ptr->getPosition().getAngle();
    
    CHECK(playerBullet1Angle == correctAngle1);
    CHECK(playerBullet2Angle == correctAngle2);
}