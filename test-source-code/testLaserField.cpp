#include "LaserField.h"
#include "Grid.h"
#include "EntityType.h"
#include <memory>
#include "vector"

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Laser Field is initialized with correct attributes")
{
    Grid grid{800, 600};
    int directionAngle = 20;
    int location = 1;
    shared_ptr<IMovingEntity> laserField_ptr = make_shared<LaserField>(grid,directionAngle,location);
    
    CHECK(laserField_ptr->getEntityType() == EntityType::LASER_FIELD);
    CHECK(laserField_ptr->isAlive() == true);
    CHECK(laserField_ptr->getRespawn() == false);
    CHECK(laserField_ptr->getHitRadius() == 6);
}

TEST_CASE("Laser Field spawns at center of the grid")
{
    Grid grid{800, 600};
    int directionAngle = 20;
    int location = 1;
    shared_ptr<IMovingEntity> laserField_ptr = make_shared<LaserField>(grid,directionAngle,location);
    
    CHECK(grid.getCenterX() == laserField_ptr->getPosition().getXpos());
    CHECK(grid.getCenterY() == laserField_ptr->getPosition().getYpos());
}

TEST_CASE("Laser Field can move outwards from center")
{
    Grid grid{800, 600};
    int directionAngle = 20;
    int location = 1;
    shared_ptr<IMovingEntity> laserField_ptr = make_shared<LaserField>(grid,directionAngle,location);
    
    auto xPosBefore = laserField_ptr->getPosition().getXpos();
    auto yPosBefore = laserField_ptr->getPosition().getYpos();
    
    laserField_ptr->move();
    
    auto xPosAfter = laserField_ptr->getPosition().getXpos();
    auto yPosAfter = laserField_ptr->getPosition().getYpos();
    
    bool diffPosition = (xPosAfter != xPosBefore || yPosAfter != yPosBefore);
    
    CHECK(diffPosition == true);
}

TEST_CASE("Laser Field can be set dead")
{
    Grid grid{800, 600};
    int directionAngle = 20;
    int location = 1;
    shared_ptr<IMovingEntity> laserField_ptr = make_shared<LaserField>(grid,directionAngle,location);
    
    laserField_ptr->setDead();
    CHECK_FALSE(laserField_ptr->isAlive());
}

TEST_CASE("Laser Field is set dead when it reaches the circumference")
{
    Grid grid{800, 600};
    int directionAngle = 20;
    int location = 1;
    shared_ptr<IMovingEntity> laserField_ptr = make_shared<LaserField>(grid,directionAngle,location);
        
    while(laserField_ptr->getPosition().getRadius() < grid.getRadius()) laserField_ptr->move();
    laserField_ptr->move();
    
    CHECK_FALSE(laserField_ptr->isAlive());
    CHECK_FALSE(laserField_ptr->getRespawn());
}