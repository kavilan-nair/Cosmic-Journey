#include "Satellite.h"
#include "Grid.h"
#include "EntityType.h"
#include <memory>
#include <iostream>
#include "vector"

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Satellite is initialized with correct attributes")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int numSatellite= 1;
	shared_ptr<IMovingEntity> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);

	CHECK(satellite_ptr->getEntityType() == EntityType::SATELLITE);
	CHECK(satellite_ptr->isAlive() == true);
	CHECK(satellite_ptr->getRespawn() == false);
	CHECK(satellite_ptr->getHitRadius() == 24);
}

TEST_CASE("Satellite spawns in center of grid")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int numSatellite= 1;
	shared_ptr<IMovingEntity> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
	
	CHECK(grid.getCenterX() == satellite_ptr->getPosition().getXpos());
	CHECK(grid.getCenterY() == satellite_ptr->getPosition().getYpos());
}

TEST_CASE("Satellite can expand for first 10 life-cycles")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int numSatellite= 1;
	shared_ptr<IMovingEntity> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
	
	auto xPosBefore = satellite_ptr->getPosition().getXpos();
	auto yPosBefore = satellite_ptr->getPosition().getYpos();
	
	satellite_ptr->move();
	
	auto xPosAfter = satellite_ptr->getPosition().getXpos();
	auto yPosAfter = satellite_ptr->getPosition().getYpos();
	
	bool diffPosition = (xPosAfter != xPosBefore || yPosAfter != yPosBefore);
	
	CHECK(diffPosition == true);
}

TEST_CASE("Satellite sets new origin at 11th life-cycle")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int numSatellite= 1;
	shared_ptr<Satellite> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
	
	auto xPosBefore = satellite_ptr->getPosition().getXposInitial();
	auto yPosBefore = satellite_ptr->getPosition().getYposInitial(); 
	
	while(satellite_ptr->getLifeCycle() < 11)
	{
		satellite_ptr->move();
	}
	
	auto xPosAfter = satellite_ptr->getPosition().getXposInitial();
	auto yPosAfter = satellite_ptr->getPosition().getYposInitial();
	
	bool diffPosition = (xPosAfter != xPosBefore || yPosAfter != yPosBefore);
	
	CHECK(diffPosition == true);
}

TEST_CASE("Satellite gyrates in circle above 11th life-cycle")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int numSatellite= 1;
	shared_ptr<Satellite> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
	
	while(satellite_ptr->getLifeCycle() < 15)
	{
		satellite_ptr->move();
	}
	
	auto xPosBefore = satellite_ptr->getPosition().getXpos();
	auto yPosBefore = satellite_ptr->getPosition().getYpos();
	
	for(auto i = 1; i <= 3; i++) satellite_ptr->move();
	
	auto xPosAfter = satellite_ptr->getPosition().getXpos();
	auto yPosAfter = satellite_ptr->getPosition().getYpos();
	
	bool diffPosition = (xPosAfter != xPosBefore || yPosAfter != yPosBefore);
	
	CHECK(diffPosition == true);
}

TEST_CASE("Satellite can shoot above 11th life-cycle")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int numSatellite= 1;
	shared_ptr<Satellite> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
	
	while(satellite_ptr->getLifeCycle() < 12)
	{
		satellite_ptr->move();
	}
	
	auto satelliteBullet = satellite_ptr->shoot();
	CHECK(satelliteBullet.size() == 1);
	CHECK(satelliteBullet[0]->getEntityType() == EntityType::ENEMY_BULLET);
}

TEST_CASE("Satellite can be set dead")
{
   	Grid grid{800, 600};
	int directionAngle = 20;
	int numSatellite= 1;
	shared_ptr<Satellite> satellite_ptr = make_shared<Satellite>(grid,directionAngle,numSatellite);
    
	CHECK(satellite_ptr->isAlive());
    satellite_ptr->setDead();
    CHECK_FALSE(satellite_ptr->isAlive());
}