#include "Player.h"
#include "GameWindowProperties.h"
#include "Game.h"


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

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
