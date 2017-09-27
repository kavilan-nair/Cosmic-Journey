#include "Game.h"

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
