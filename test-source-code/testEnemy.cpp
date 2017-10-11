#include "Enemy.h"
#include "Grid.h"
#include "EntityType.h"
#include <memory>
#include "vector"

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Enemy is initialized with correct attributes")
{
	Grid grid{800, 600};
	shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
	
	CHECK(enemy_ptr->getEntityType() == EntityType::ENEMY);
	CHECK(enemy_ptr->isAlive() == true);
	CHECK(enemy_ptr->getRespawn() == false);
	CHECK(enemy_ptr->getHitRadius() == 24);
}

TEST_CASE("Enemy spawns at center of the grid")
{
	Grid grid{800, 600};
	shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
	
	CHECK(grid.getCenterX() == enemy_ptr->getPosition().getXpos());
	CHECK(grid.getCenterY() == enemy_ptr->getPosition().getYpos());
}

TEST_CASE("Enemy can move")
{
	Grid grid{800, 600};
	shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
	
	auto xPosBefore = enemy_ptr->getPosition().getXpos();
	auto yPosBefore = enemy_ptr->getPosition().getYpos();
	
	enemy_ptr->move();
	
	auto xPosAfter = enemy_ptr->getPosition().getXpos();
	auto yPosAfter = enemy_ptr->getPosition().getYpos();
	
	bool diffPosition = (xPosAfter != xPosBefore || yPosAfter != yPosBefore);
	
	CHECK(diffPosition == true);
}

TEST_CASE("Enemy dying at radius will indicate a respawn")
{
	Grid grid{800, 600};
	shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
	
	CHECK(enemy_ptr->getRespawn() == false);
	
	while(enemy_ptr->getPosition().getRadius() < grid.getRadius())
	{
		enemy_ptr->move();
	}
	
	enemy_ptr->move();
	CHECK(enemy_ptr->getRespawn() == true);
}

TEST_CASE("Enemy can be set dead")
{
    Grid grid{800, 600};
	shared_ptr<IMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
    
	CHECK(enemy_ptr->isAlive());
    enemy_ptr->setDead();
    CHECK_FALSE(enemy_ptr->isAlive());
}

TEST_CASE("Enemy can fire bullets")
{
	Grid grid{800, 600};
	shared_ptr<IShootingMovingEntity> enemy_ptr = make_shared<Enemy>(grid);
	
	auto bulletEnemy1 = enemy_ptr->shoot();
	auto bulletEnemy2 = enemy_ptr->shoot();
	
	bulletEnemy2.push_back(bulletEnemy1[0]);
	
	CHECK(bulletEnemy1.size() == 1);
	CHECK(bulletEnemy2.size() == 2);
	CHECK(bulletEnemy1[0]->getEntityType() == EntityType::ENEMY_BULLET);
}