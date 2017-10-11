#include "Player.h"
#include "Grid.h"
#include "Direction.h"
#include "EntityType.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Player is initialized with correct attributes")
{
	Grid grid{800, 600};
	shared_ptr<IMovingEntity> player_ptr = make_shared<Player>(grid);
	
	CHECK(player_ptr->getEntityType() == EntityType::PLAYER);
	CHECK(player_ptr->isAlive() == true);
	CHECK(player_ptr->getRespawn() == false);
	CHECK(player_ptr->getHitRadius() == 24);
}

TEST_CASE("Player can move left")
{
	Grid grid{800, 600};
	shared_ptr<Player> player_ptr = make_shared<Player>(grid);
	player_ptr->setDirection(Direction::CLOCKWISE);
	
	auto xPosBefore = player_ptr->getPosition().getXpos();
	auto yPosBefore = player_ptr->getPosition().getYpos();
	
	player_ptr->move();
	
	auto xPosAfter = player_ptr->getPosition().getXpos();
	auto yPosAfter = player_ptr->getPosition().getYpos();
	
	CHECK_FALSE(xPosBefore == xPosAfter);
	CHECK_FALSE(yPosBefore == yPosAfter);
	
	CHECK(xPosAfter == 397);
	CHECK(yPosAfter == 584);
}

TEST_CASE("Player can move right")
{
	Grid grid{800, 600};
	shared_ptr<Player> player_ptr = make_shared<Player>(grid);
	player_ptr->setDirection(Direction::ANTICLOCKWISE);
	
	auto xPosBefore = player_ptr->getPosition().getXpos();
	auto yPosBefore = player_ptr->getPosition().getYpos();
	
	player_ptr->move();
	
	auto xPosAfter = player_ptr->getPosition().getXpos();
	auto yPosAfter = player_ptr->getPosition().getYpos();
	
	CHECK_FALSE(xPosBefore == xPosAfter);
	CHECK_FALSE(yPosBefore == yPosAfter);
	
	CHECK(xPosAfter == 402);
	CHECK(yPosAfter == 584);
}

TEST_CASE("Player can stay in the same position")
{
	Grid grid{800, 600};
	shared_ptr<Player> player_ptr = make_shared<Player>(grid);
	player_ptr->setDirection(Direction::HOVER);
	
	auto xPosBefore = player_ptr->getPosition().getXpos();
	auto yPosBefore = player_ptr->getPosition().getYpos();
	
	player_ptr->move();
	
	auto xPosAfter = player_ptr->getPosition().getXpos();
	auto yPosAfter = player_ptr->getPosition().getYpos();
	
	CHECK(xPosBefore == xPosAfter);
	CHECK(yPosBefore == yPosAfter);
}

TEST_CASE("Player respawns in correct position")
{
	Grid grid{800, 600};
	shared_ptr<Player> player_ptr = make_shared<Player>(grid);
	player_ptr->setDirection(Direction::ANTICLOCKWISE);
	
	auto xPosBeforeRespawn = player_ptr->getPosition().getXpos();
	auto yPosBeforeRespawn = player_ptr->getPosition().getYpos();
	
	player_ptr->move();
	player_ptr->setDead();
	
	auto xPosAfterRespawn = player_ptr->getPosition().getXpos();
	auto yPosAfterRespawn = player_ptr->getPosition().getYpos();
	
	CHECK(xPosBeforeRespawn == xPosAfterRespawn);
	CHECK(yPosBeforeRespawn == yPosAfterRespawn);
}

TEST_CASE("Player can shoot different amounts of bullets depending on weapon upgrades")
{
	Grid grid{800, 600};
	shared_ptr<Player> player_ptr = make_shared<Player>(grid);
	auto bulletSingle = player_ptr->shoot();
	
	player_ptr->upgradeWeaponDouble();
	
	auto bulletDouble = player_ptr->shoot();
	
	CHECK(bulletSingle.size() == 1);
	CHECK(bulletDouble.size() == 2);
}