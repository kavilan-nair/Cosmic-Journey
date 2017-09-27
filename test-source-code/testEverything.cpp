#include "GameWindowProperties.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyBullet.h"
#include "Bullet.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

//----------------------------Player Test ---------------------------------------------
TEST_CASE("360 degrees clockwise returns to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();

	for(int i = 1; i <= 72; i++)
	{
		player.moveClockwise();
	}
	
	int playerEndX = player.getPosition().getX();
	int playerEndY = player.getPosition().getY();
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("360 degrees anticlockwise returns to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();
	
	for(int i = 1; i <= 72; i++)
	{
		player.moveAntiClockwise();
	}
	
	int playerEndX = player.getPosition().getX()+1;
	int playerEndY = player.getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("18 Clockwise + 18 anticlockwise movements returns to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();
	
	for(int i = 1; i <= 18; i++)
	{
		player.moveClockwise();
	}
	
	for(int i = 1; i <= 18; i++)
	{
		player.moveAntiClockwise();
	}
	
	int playerEndX = player.getPosition().getX()+1;
	int playerEndY = player.getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("36 Clockwise + 36 anticlockwise movements returns to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();
	
	for(int i = 1; i <= 36; i++)
	{
		player.moveClockwise();
	}
	
	for(int i = 1; i <= 36; i++)
	{
		player.moveAntiClockwise();
	}
	
	int playerEndX = player.getPosition().getX()+1;
	int playerEndY = player.getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("54 Clockwise + 54 anticlockwise movements returns to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();
	
	for(int i = 1; i <= 54; i++)
	{
		player.moveClockwise();
	}
	
	for(int i = 1; i <= 54; i++)
	{
		player.moveAntiClockwise();
	}
	
	int playerEndX = player.getPosition().getX()+1;
	int playerEndY = player.getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("72 Clockwise + 72 anticlockwise movements returns to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();
	
	for(int i = 1; i <= 72; i++)
	{
		player.moveClockwise();
	}
	
	for(int i = 1; i <= 72; i++)
	{
		player.moveAntiClockwise();
	}
	
	int playerEndX = player.getPosition().getX()+1;
	int playerEndY = player.getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("Random Clockwise + identical random anticlockwise movements returns to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();
	
	
	srand(time(0));
	int randMovements = rand()%10000+1;
	for(int i = 1; i <= randMovements; i++)
	{
		player.moveClockwise();
	}
	
	for(int i = 1; i <= randMovements; i++)
	{
		player.moveAntiClockwise();
	}
	
	int playerEndX = player.getPosition().getX()+1;
	int playerEndY = player.getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
}

TEST_CASE("Player dying at different angles causes return to origin")
{
    GameWindowProperties gameWindow(800,600);
    Player player(gameWindow);
	int playerStartX = player.getPosition().getX();
	int playerStartY = player.getPosition().getY();
	
	
	int randomMovements = rand()%10000 +1;
	for(int i = 1; i <= randomMovements; i++)
	{
		player.moveClockwise();
	}
	
	int playerCurrentX = player.getPosition().getX();
	int playerCurrentY = player.getPosition().getY();
	
	player.respawn();
	
	CHECK_FALSE(playerCurrentX == playerStartX);
	CHECK_FALSE(playerCurrentY == playerStartY);
	
	int playerRespawnX = player.getPosition().getX();
	int playerRespawnY = player.getPosition().getY();
	
	CHECK(playerRespawnX == playerStartX);
	CHECK(playerRespawnY == playerStartY);
}


//----------------------------Enemy Test ---------------------------------------------

TEST_CASE("Enemy spawn coordinates correct")
{
	srand(time(0));
	GameWindowProperties gameWindow(800,600);
	Enemy spawnedEnemy(gameWindow);
	
	int enemyOriginX = spawnedEnemy.getPosition().getoriginX();
	int enemyOriginY = spawnedEnemy.getPosition().getoriginY();
	
	int circleCenterX = gameWindow.getXOrigin();
	int circleCenterY = gameWindow.getYOrigin();
	
	CHECK(enemyOriginX == circleCenterX);
	CHECK(enemyOriginY == circleCenterY);
} 

TEST_CASE("Half movement correct location")
{
	GameWindowProperties gameWindow(800,600);
	Enemy spawnedEnemy(gameWindow);
	float PI = atan(1)*4;
	int stepSize = 99;
	int toleranceBand = 2;
	
	for(int i = 1; i <= stepSize; i++)
	{
		spawnedEnemy.move();
	}
	
	auto radians = (spawnedEnemy.getPosition().getAngle() * PI/180);
	int enemyCurrentX = gameWindow.getXOrigin() + 0.5*gameWindow.getRadius()*cos(radians);
	int enemyCurrentY = gameWindow.getYOrigin() + 0.5*gameWindow.getRadius()*sin(radians);

	CHECK(enemyCurrentX - spawnedEnemy.getPosition().getX() <= toleranceBand);
	CHECK(enemyCurrentY - spawnedEnemy.getPosition().getY() <= toleranceBand);
}

TEST_CASE("Full movement correct location")
{
	GameWindowProperties gameWindow(800,600);
	Enemy spawnedEnemy(gameWindow);
	float PI = atan(1)*4;
	int stepSize = 199;
	int toleranceBand = 2;
	
	for(int i = 1; i <= stepSize; i++)
	{
		spawnedEnemy.move();
	}
	
	auto radians = (spawnedEnemy.getPosition().getAngle() * PI/180);
	int enemyCurrentX = gameWindow.getXOrigin() + gameWindow.getRadius()*cos(radians);
	int enemyCurrentY = gameWindow.getYOrigin() + gameWindow.getRadius()*sin(radians);

	CHECK(enemyCurrentX - spawnedEnemy.getPosition().getX() <= toleranceBand);
	CHECK(enemyCurrentY - spawnedEnemy.getPosition().getY() <= toleranceBand);
}

TEST_CASE("Enemy dies when it reaches the circumference and is flagged for respawn")
{
	GameWindowProperties gameWindow(800,600);
	Enemy spawnedEnemy(gameWindow);
	int stepSize = 300; 
	
	CHECK(spawnedEnemy.isAlive() == true);
	CHECK(spawnedEnemy.isRespawn() == false);
	
	for(int i = 1; i <= stepSize; i++)
	{
		spawnedEnemy.move();
	}
	
	CHECK(spawnedEnemy.isAlive() == false);
	CHECK(spawnedEnemy.isRespawn() == true);
}

//----------------------------Bullet Test ---------------------------------------------


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

//----------------------------Enemy Bullet Test ---------------------------------------------

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