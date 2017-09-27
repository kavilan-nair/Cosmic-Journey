#include "GameWindowProperties.h"
#include "Bullet.h"
#include "Player.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Bullet spawns at player position")
{
	GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber = 1;
    Bullet bullet(player.getPosition(), gameWindow, bulletNumber);

	int playerPosX = player.getPosition().getX();
    int playerPosY = player.getPosition().getY();
    
	int bulletPosX = bullet.getPosition().getX();
	int bulletPosY = bullet.getPosition().getY();
	
	CHECK(bulletPosX == playerPosX);
	CHECK(bulletPosY == playerPosY);
} 

TEST_CASE("Bullet has the correct radius for proper movement")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber = 1;
    Bullet bullet(player.getPosition(), gameWindow, bulletNumber);
    
    int radiusGameWindow = gameWindow.getRadius();
    int radiusBullet = bullet.getBulletRadius();
    
    CHECK(radiusBullet == radiusGameWindow);
}

TEST_CASE("Bullet status is set to dead")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber = 1;
    Bullet bullet(player.getPosition(), gameWindow, bulletNumber);

    bullet.setBulletDead();
    bool aliveStatus = false;
    bool isBulletAlive = bullet.isBulletAlive();
    
    CHECK(isBulletAlive == aliveStatus);
}

TEST_CASE("Bullet status is set to alive when created")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber = 1;
    Bullet bullet(player.getPosition(), gameWindow, bulletNumber);
    
    bool isBulletAlive = bullet.isBulletAlive();
    bool aliveStatus = true;
    
    CHECK(isBulletAlive == aliveStatus);
}

//We should have a test for bullet hitting player but hey oh well
TEST_CASE("Bullet status is alive after bullet update")  
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber = 1;
    Bullet bullet(player.getPosition(), gameWindow, bulletNumber);
    
    bullet.updateBullet();
    
    bool isBulletAlive = bullet.isBulletAlive();
    bool aliveStatus = true;
    
    CHECK(isBulletAlive == aliveStatus);
}
    
TEST_CASE("Bullet status is dead after bullet reaches near the center ")  
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber = 1;
    Bullet bullet(player.getPosition(), gameWindow, bulletNumber);
      //number of loops ensures that the bullet will reach the center of the playing circle
    for (int i = 0; i != 100; i++) { bullet.updateBullet(); }
    
    bool isBulletAlive = bullet.isBulletAlive();
    bool aliveStatus = false;
    
    CHECK(isBulletAlive == aliveStatus);
}

TEST_CASE("Bullet is fired at correct angle")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber1 = 1;
    Bullet bullet1(player.getPosition(), gameWindow, bulletNumber1);
    
    int correctAngle1 = player.getPosition().getAngle();
    int bullet1Angle = bullet1.getPosition().getAngle();
    
    CHECK(bullet1Angle == correctAngle1);   
}
    


TEST_CASE("Double bullets are fired at correct angle")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber2 = 2;
    int bulletNumber3 = 3;
    Bullet bullet2(player.getPosition(), gameWindow, bulletNumber2);
    Bullet bullet3(player.getPosition(), gameWindow, bulletNumber3);
    
    int correctAngle2 = player.getPosition().getAngle() + 1;
    int correctAngle3 = player.getPosition().getAngle() - 1;
    
    int bullet2Angle = bullet2.getPosition().getAngle();
    int bullet3Angle = bullet3.getPosition().getAngle();
    
    CHECK(bullet2Angle == correctAngle2);
    CHECK(bullet3Angle == correctAngle3);
}

TEST_CASE("Triple bullets are fired at correct angle")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    int bulletNumber1 = 1;
    int bulletNumber2 = 2;
    int bulletNumber3 = 3;
    Bullet bullet1(player.getPosition(), gameWindow, bulletNumber1);
    Bullet bullet2(player.getPosition(), gameWindow, bulletNumber2);
    Bullet bullet3(player.getPosition(), gameWindow, bulletNumber3);
    
    int correctAngle1 = player.getPosition().getAngle();
    int correctAngle2 = player.getPosition().getAngle() + 1;
    int correctAngle3 = player.getPosition().getAngle() - 1;
    
    int bullet1Angle = bullet1.getPosition().getAngle();
    int bullet2Angle = bullet2.getPosition().getAngle();
    int bullet3Angle = bullet3.getPosition().getAngle();
    
    CHECK(bullet1Angle == correctAngle1);
    CHECK(bullet2Angle == correctAngle2);
    CHECK(bullet3Angle == correctAngle3);
}