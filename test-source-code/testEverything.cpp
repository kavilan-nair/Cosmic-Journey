#include "Game.h"
#include "GameWindowProperties.h"
#include "Enemy.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("360 degrees clockwise returns to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();

	for(int i = 1; i <= 72; i++)
	{
		game.getPlayer().moveClockwise();
	}
	
	int playerEndX = game.getPlayer().getPosition().getX();
	int playerEndY = game.getPlayer().getPosition().getY();
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("360 degrees anticlockwise returns to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();
	
	for(int i = 1; i <= 72; i++)
	{
		game.getPlayer().moveAntiClockwise();
	}
	
	int playerEndX = game.getPlayer().getPosition().getX()+1;
	int playerEndY = game.getPlayer().getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("18 Clockwise + 18 anticlockwise movements returns to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();
	
	for(int i = 1; i <= 18; i++)
	{
		game.getPlayer().moveClockwise();
	}
	
	for(int i = 1; i <= 18; i++)
	{
		game.getPlayer().moveAntiClockwise();
	}
	
	int playerEndX = game.getPlayer().getPosition().getX()+1;
	int playerEndY = game.getPlayer().getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("36 Clockwise + 36 anticlockwise movements returns to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();
	
	for(int i = 1; i <= 36; i++)
	{
		game.getPlayer().moveClockwise();
	}
	
	for(int i = 1; i <= 36; i++)
	{
		game.getPlayer().moveAntiClockwise();
	}
	
	int playerEndX = game.getPlayer().getPosition().getX()+1;
	int playerEndY = game.getPlayer().getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("54 Clockwise + 54 anticlockwise movements returns to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();
	
	for(int i = 1; i <= 54; i++)
	{
		game.getPlayer().moveClockwise();
	}
	
	for(int i = 1; i <= 54; i++)
	{
		game.getPlayer().moveAntiClockwise();
	}
	
	int playerEndX = game.getPlayer().getPosition().getX()+1;
	int playerEndY = game.getPlayer().getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("72 Clockwise + 72 anticlockwise movements returns to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();
	
	for(int i = 1; i <= 72; i++)
	{
		game.getPlayer().moveClockwise();
	}
	
	for(int i = 1; i <= 72; i++)
	{
		game.getPlayer().moveAntiClockwise();
	}
	
	int playerEndX = game.getPlayer().getPosition().getX()+1;
	int playerEndY = game.getPlayer().getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("Random Clockwise + identical random anticlockwise movements returns to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();
	
	srand(time(0));
	int randMovements = rand()%10000+1;
	for(int i = 1; i <= randMovements; i++)
	{
		game.getPlayer().moveClockwise();
	}
	
	for(int i = 1; i <= randMovements; i++)
	{
		game.getPlayer().moveAntiClockwise();
	}
	
	int playerEndX = game.getPlayer().getPosition().getX()+1;
	int playerEndY = game.getPlayer().getPosition().getY()+1;
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
}

TEST_CASE("Player dying at different angles causes return to origin")
{
	Game game;
	int playerStartX = game.getPlayer().getPosition().getX();
	int playerStartY = game.getPlayer().getPosition().getY();
	
	int randomMovements = rand()%10000 +1;
	for(int i = 1; i <= randomMovements; i++)
	{
		game.getPlayer().moveClockwise();
	}
	
	int playerCurrentX = game.getPlayer().getPosition().getX();
	int playerCurrentY = game.getPlayer().getPosition().getY();
	
	game.getPlayer().respawn();
	
	CHECK_FALSE(playerCurrentX == playerStartX);
	CHECK_FALSE(playerCurrentY == playerStartY);
	
	int playerRespawnX = game.getPlayer().getPosition().getX();
	int playerRespawnY = game.getPlayer().getPosition().getY();
	
	CHECK(playerRespawnX == playerStartX);
	CHECK(playerRespawnY == playerStartY);
}

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