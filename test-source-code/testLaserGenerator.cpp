#include "LaserGenerator.h"
#include "Grid.h"
#include "EntityType.h"
#include <memory>
#include "vector"

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("LaserGenerator is initialized with correct attributes")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int typeSide = 1;
	shared_ptr<IMovingEntity> laserGenerator_ptr = make_shared<LaserGenerator>(grid,directionAngle,typeSide);
	
	CHECK(laserGenerator_ptr->getEntityType() == EntityType::LASER_GENERATOR);
	CHECK(laserGenerator_ptr->isAlive() == true);
	CHECK(laserGenerator_ptr->getRespawn() == false);
	CHECK(laserGenerator_ptr->getHitRadius() == 15);
}

TEST_CASE("LaserGenerator spawns at center of the grid")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int typeSide = 1;
	shared_ptr<IMovingEntity> laserGenerator_ptr = make_shared<LaserGenerator>(grid,directionAngle,typeSide);
	
	CHECK(grid.getCenterX() == laserGenerator_ptr->getPosition().getXpos());
	CHECK(grid.getCenterY() == laserGenerator_ptr->getPosition().getYpos());
}

TEST_CASE("LaserGenerator can move outward from center")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int typeSide = 1;
	shared_ptr<IMovingEntity> laserGenerator_ptr = make_shared<LaserGenerator>(grid,directionAngle,typeSide);
	
	auto xPosBefore = laserGenerator_ptr->getPosition().getXpos();
	auto yPosBefore = laserGenerator_ptr->getPosition().getYpos();
	
	laserGenerator_ptr->move();
	
	auto xPosAfter = laserGenerator_ptr->getPosition().getXpos();
	auto yPosAfter = laserGenerator_ptr->getPosition().getYpos();
	
	bool diffPosition = (xPosAfter != xPosBefore || yPosAfter != yPosBefore);
	
	CHECK(diffPosition == true);
}

TEST_CASE("LaserGenerator can be set dead")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int typeSide = 1;
	shared_ptr<IMovingEntity> laserGenerator_ptr = make_shared<LaserGenerator>(grid,directionAngle,typeSide);
    
    laserGenerator_ptr->setDead();
    CHECK_FALSE(laserGenerator_ptr->isAlive());
}

TEST_CASE("LaserGenerator can project laser field")
{
	Grid grid{800, 600};
	int directionAngle = 20;
	int typeSide = 1;
	shared_ptr<IShootingMovingEntity> laserGenerator_ptr = make_shared<LaserGenerator>(grid,directionAngle,typeSide);
	
	auto laserFieldProjectile = laserGenerator_ptr->shoot();
	
	CHECK(laserFieldProjectile.size() == 1);
	CHECK(laserFieldProjectile[0]->getEntityType() == EntityType::LASER_FIELD);
}