#include "Grid.h"
#include "Asteroid.h"
#include <memory>
#include <iostream>
using std::shared_ptr;
using std::make_shared;

using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>


TEST_CASE("Asteroid is initialized with the correct attributes")
{
    Grid grid{800, 600};
    shared_ptr<IMovingEntity> asteroid_ptr = make_shared<Asteroid>(grid);
    
    CHECK(asteroid_ptr->getEntityType() == EntityType::ASTEROID);
    CHECK(asteroid_ptr->isAlive());
    CHECK_FALSE(asteroid_ptr->getRespawn());
    CHECK(asteroid_ptr->getHitRadius() == 15);    
}


TEST_CASE("Asteroid Spawns from the center of the screen")
{
    Grid grid{800, 600};
    shared_ptr<IMovingEntity> asteroid_ptr = make_shared<Asteroid>(grid);
    
    auto asteroidXInitial = asteroid_ptr->getPosition().getXposInitial();
    auto asteroidYInitial = asteroid_ptr->getPosition().getYposInitial();
    auto gridCenterX = grid.getCenterX();
    auto gridCenterY = grid.getCenterY();
    
    CHECK(asteroidXInitial == gridCenterX);
    CHECK(asteroidYInitial == gridCenterY);
}


TEST_CASE("Asteroid movement test")
{
    Grid grid{800, 600};
    shared_ptr<IMovingEntity> asteroid_ptr = make_shared<Asteroid>(grid);
    
    auto initialX = asteroid_ptr->getPosition().getXposInitial();
    auto initialY = asteroid_ptr->getPosition().getYposInitial();
    
    asteroid_ptr->move();
    
    auto currentX = asteroid_ptr->getPosition().getXpos();
    auto currentY = asteroid_ptr->getPosition().getYpos();
	
	bool diffPosition = (currentX != initialX || currentY != initialY);
	
	CHECK(diffPosition);
} 

TEST_CASE("Asteroid status can be set to dead")
{
    Grid grid{800, 600};
    shared_ptr<IMovingEntity> asteroid_ptr = make_shared<Asteroid>(grid);
    
	CHECK(asteroid_ptr->isAlive());
    asteroid_ptr->setDead();
    CHECK_FALSE(asteroid_ptr->isAlive());
} 

TEST_CASE("Asteroid status is set to dead when out of bounds")
{
    Grid grid{800, 600};
    shared_ptr<IMovingEntity> asteroid_ptr = make_shared<Asteroid>(grid);
    //objects need to move till its out of bounds
    while (asteroid_ptr->getPosition().getRadius() < grid.getRadius())
        asteroid_ptr->move();
    //additional move function required to move out of bounds
    asteroid_ptr->move();

    CHECK_FALSE(asteroid_ptr->isAlive());
    CHECK_FALSE(asteroid_ptr->getRespawn());
} 
 



