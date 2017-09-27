#include "GameWindowProperties.h"
#include "Enemy.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

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

