#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <math.h>
#include "Game.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

TEST_CASE("Window size is correct")
{
	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);
	
	Game game;
	int gameX = game.getPlayer().getWindowProperties().getWidth();
	int gameY = game.getPlayer().getWindowProperties().getHeight();
	
	CHECK(screenX == gameX);
	CHECK(screenY == gameY);	
}

TEST_CASE("360 degrees movement = starting position")
{
	Game game;
	auto playerStartX = game.getPlayer().getPosition().getX();
	auto playerStartY = game.getPlayer().getPosition().getY();
	
	for(int i = 1; i < 73; i++)
	{
		game.getPlayer().moveAntiClockwise();
	}
	
	auto playerEndX = game.getPlayer().getPosition().getX();
	auto playerEndY = game.getPlayer().getPosition().getY();
	
	CHECK(playerEndX == playerStartX);
	CHECK(playerEndY == playerStartY);
} 

TEST_CASE("Can only move on circumference of circle")
{
	Game game;
	int angleX[4] = {0};
	int angleY[4] = {0};
	
	auto originX = game.getPlayer().getWindowProperties().getXOrigin();
	auto originY = game.getPlayer().getWindowProperties().getYOrigin();
	
	for(int j = 0; j < 4; j++)
	{
		for(int i = 1; i < 19; i++){game.getPlayer().moveClockwise();}
		angleX[j] = game.getPlayer().getPosition().getX();
		angleY[j] = game.getPlayer().getPosition().getY();
	}
	
	auto radius = game.getPlayer().getWindowProperties().getRadius();

	CHECK(angleX[0] == (originX+radius));
	CHECK(angleX[2] == (originX-radius));
	CHECK(angleY[1] == (originY-radius));
	CHECK(angleY[3] == (originY+radius));
}