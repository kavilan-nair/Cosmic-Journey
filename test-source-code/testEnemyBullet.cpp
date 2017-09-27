#include "GameWindowProperties.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Player.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Enemy Bullet spawns at Enemy position")
{
	GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    Enemy enemy(gameWindow);
    EnemyBullet enemyBullet(enemy.getPosition(), gameWindow, player.getPosition());
    
	int enemyPosX = enemy.getPosition().getX();
    int enemyPosY = enemy.getPosition().getY();
    
	int enemyBulletPosX = enemyBullet.getPosition().getX();
	int enemyBulletPosY = enemyBullet.getPosition().getY();
	
	CHECK(enemyBulletPosX == enemyPosX);
	CHECK(enemyBulletPosY == enemyPosY);
} 

TEST_CASE("Enemy Bullet has the correct radius for proper movement")
{
	GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    Enemy enemy(gameWindow);
    EnemyBullet enemyBullet(enemy.getPosition(), gameWindow, player.getPosition());
    
    int radiusEnemy = enemy.getPosition().getRadius();
    int radiusEnemyBullet = enemyBullet.getPosition().getRadius();
    
    CHECK(radiusEnemyBullet == radiusEnemy);
}

TEST_CASE("Bullet status is set to alive when created")
{
	GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    Enemy enemy(gameWindow);
    EnemyBullet enemyBullet(enemy.getPosition(), gameWindow, player.getPosition());
    
    bool isEnemyBulletAlive = enemyBullet.isEnemyBulletAlive();
    bool aliveStatus = true;
    
    CHECK(isEnemyBulletAlive == aliveStatus);
}

TEST_CASE("Bullet status is set to dead")
{
	GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    Enemy enemy(gameWindow);
    EnemyBullet enemyBullet(enemy.getPosition(), gameWindow, player.getPosition());

    enemyBullet.setEnemyBulletDead();
    bool aliveStatus = false;
    bool isEnemyBulletAlive = enemyBullet.isEnemyBulletAlive();
    
    CHECK(isEnemyBulletAlive == aliveStatus);
}

//The bullet should be set to dead when it goes off the screen, implement this when the great refactoring of 2017 takes place

TEST_CASE("Enemy Bullet status is alive after bullet update")  
{
	GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    Enemy enemy(gameWindow);
    EnemyBullet enemyBullet(enemy.getPosition(), gameWindow, player.getPosition());

    enemyBullet.updateEnemyBullet();
    
    bool isEnemyBulletAlive = enemyBullet.isEnemyBulletAlive();
    bool aliveStatus = true;
    
    CHECK(isEnemyBulletAlive == aliveStatus);
}
    

TEST_CASE("Enemy Bullet is fired at correct angle")
{
	GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
    Enemy enemy(gameWindow);
    EnemyBullet enemyBullet(enemy.getPosition(), gameWindow, player.getPosition());
    
    int correctAngle = enemy.getPosition().getAngle();
    int enemyBullet1Angle = enemyBullet.getPosition().getAngle();
    
    CHECK(enemyBullet1Angle == correctAngle);   
}

