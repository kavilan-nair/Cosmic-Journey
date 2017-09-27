#include "GameWindowProperties.h"
#include "Satellites.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Satellites spawn in the correct location")
{
	srand(time(0));
	GameWindowProperties gameWindow(800,600);
	int circleCenterX = gameWindow.getXOrigin();
	int circleCenterY = gameWindow.getYOrigin();
	int direction = rand()%360;
	
	for(int i = 1; i <= 3; i++)
	{
		Satellites spawnedSatellite(gameWindow,direction,i);
		
		int satelliteOriginX = spawnedSatellite.getPosition().getoriginX();
		int satelliteOriginY = spawnedSatellite.getPosition().getoriginY();
		
		CHECK(satelliteOriginX == circleCenterX);
		CHECK(satelliteOriginY == circleCenterY);
	}
}

TEST_CASE("Satellites expand first")
{
	GameWindowProperties gameWindow(800,600);
	int direction = rand()%360;	
	int toleranceBand = 2;
	int numberSequence = 9;
	int angleDeviation = 0;
	float PI = atan(1)*4;
	float factor = 0.45;
	
	
	for(int j = 1; j <= 3; j++)
	{
		Satellites spawnedSatellite(gameWindow,direction,j);
		for(int i = 1; i <= numberSequence; i++)
		{
			spawnedSatellite.move();
		}	
		
		if(j == 2) angleDeviation = 20;
		if(j == 3) angleDeviation = -20;
		
		auto radians = ((direction+angleDeviation) * PI/180);
		int satelliteX = gameWindow.getXOrigin() + factor*gameWindow.getRadius()*cos(radians);
		int satelliteY = gameWindow.getYOrigin() + factor*gameWindow.getRadius()*sin(radians);
	
		CHECK(spawnedSatellite.getPosition().getX() - satelliteX <= toleranceBand);
		CHECK(spawnedSatellite.getPosition().getY() - satelliteY <= toleranceBand);
	}
} 

TEST_CASE("Satellites change origin before gyrating")
{
	GameWindowProperties gameWindow(800,600);
	int direction = rand()%360;	
	while(direction%90 == 0)
	{
		direction = rand()%360;
	}
	
	int numberSequence = 10;
	
	for(int j = 1; j <= 3; j++)
	{
		Satellites spawnedSatellite(gameWindow,direction,j);
		
		int satelliteOriginXBefore = spawnedSatellite.getPosition().getoriginX();
		int satelliteOriginYBefore = spawnedSatellite.getPosition().getoriginY();
		
		for(int i = 1; i <= numberSequence; i++)
		{
			spawnedSatellite.move();
		}	
		
		int satelliteOriginXAfter = spawnedSatellite.getPosition().getoriginX();
		int satelliteOriginYAfter = spawnedSatellite.getPosition().getoriginY();
		
		CHECK_FALSE(satelliteOriginXBefore == satelliteOriginXAfter);
		CHECK_FALSE(satelliteOriginYBefore == satelliteOriginYAfter);
	}
}


TEST_CASE("Satellites gyrate correctly")
{
	GameWindowProperties gameWindow(800,600);
	int direction = rand()%360;	
	int toleranceBand = 2;
	int beginGyrating = 10;
	int numberSequence = rand()%10000+11;
	float PI = atan(1)*4;
	float gyrateRadius = 0.05*gameWindow.getRadius();
	
	for(int j = 1; j <= 3; j++)
	{
		Satellites spawnedSatellite(gameWindow,direction,j);
		
		for(int i = 1; i <= beginGyrating; i++)
		{
			spawnedSatellite.move();
		}	
		
		int satelliteOriginXAfter = spawnedSatellite.getPosition().getoriginX();
		int satelliteOriginYAfter = spawnedSatellite.getPosition().getoriginY();
		
		for(int i = 1; i <= numberSequence; i++)
		{
			spawnedSatellite.move();
		}	

		float radians = (spawnedSatellite.getPosition().getAngle() * PI/180)*3;
		auto additionX = gyrateRadius*cos(radians);
		auto additionY = gyrateRadius*sin(radians);
		int satelliteX = satelliteOriginXAfter + additionX;
		int satelliteY = satelliteOriginYAfter + additionY;
		
		CHECK(spawnedSatellite.getPosition().getX() - satelliteX <= toleranceBand);
		CHECK(spawnedSatellite.getPosition().getY() - satelliteY <= toleranceBand);
	}
}
