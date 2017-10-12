#include "EnemySpawner.h"
#include "Grid.h"
#include "Enemy.h"
#include "EntityType.h"
#include <memory>
#include "vector"
#include "Satellite.h"

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("EnemySpawner can spawn a normal enemy")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);

	auto spawnedEnemyNormal = enemyspawner_ptr->spawnEnemyNormal();
	
	CHECK(spawnedEnemyNormal.size() == 1);
	CHECK(spawnedEnemyNormal[0]->getEntityType() == EntityType::ENEMY);
}

TEST_CASE("EnemySpawner can spawn a asteroid")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);

	auto spawnedAsteroid = enemyspawner_ptr->spawnAsteroid();
	
	CHECK(spawnedAsteroid.size() == 1);
	CHECK(spawnedAsteroid[0]->getEntityType() == EntityType::ASTEROID);
}

TEST_CASE("EnemySpawner can spawn 3 satellites")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);

	auto spawnedEnemySatellite = enemyspawner_ptr->spawnEnemySatellite();
	
	CHECK(spawnedEnemySatellite.size() == 3);
	CHECK(spawnedEnemySatellite[0]->getEntityType() == EntityType::SATELLITE);
	CHECK(spawnedEnemySatellite[1]->getEntityType() == EntityType::SATELLITE);
	CHECK(spawnedEnemySatellite[2]->getEntityType() == EntityType::SATELLITE);
}

TEST_CASE("EnemySpawner can spawn the group that makes up a laser generator")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);

	auto spawnedLaserGenerator = enemyspawner_ptr->spawnLaserGenerator();
	
	CHECK(spawnedLaserGenerator.size() == 9);
	CHECK(spawnedLaserGenerator[0]->getEntityType() == EntityType::LASER_GENERATOR);
	CHECK(spawnedLaserGenerator[1]->getEntityType() == EntityType::LASER_GENERATOR);
	CHECK(spawnedLaserGenerator[2]->getEntityType() == EntityType::LASER_FIELD);
	CHECK(spawnedLaserGenerator[3]->getEntityType() == EntityType::LASER_FIELD);
	CHECK(spawnedLaserGenerator[4]->getEntityType() == EntityType::LASER_FIELD);
	CHECK(spawnedLaserGenerator[5]->getEntityType() == EntityType::LASER_FIELD);
	CHECK(spawnedLaserGenerator[6]->getEntityType() == EntityType::LASER_FIELD);
	CHECK(spawnedLaserGenerator[7]->getEntityType() == EntityType::LASER_FIELD);
	CHECK(spawnedLaserGenerator[8]->getEntityType() == EntityType::LASER_FIELD);
}

TEST_CASE("EnemySpawner cannot spawn more than one group of laser generators and satellites at a time")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);
	
	vector<shared_ptr<IMovingEntity>> enemyVector;
	
	auto spawnedLaserGenerator = enemyspawner_ptr->spawnLaserGenerator();
	for(auto& i : spawnedLaserGenerator)
	{
		enemyVector.push_back(i);
	}
	
	auto spawnedEnemySatellite = enemyspawner_ptr->spawnEnemySatellite();
	for(auto& i : spawnedEnemySatellite)
	{
		enemyVector.push_back(i);
	}
	
	CHECK(enemyVector.size() == 12);
	enemyspawner_ptr->checkLaserGenAndSat(enemyVector);
	
	auto spawnedLaserGeneratorWhenPresent = enemyspawner_ptr->spawnLaserGenerator();
	auto spawnedEnemySatelliteWhenPresent = enemyspawner_ptr->spawnEnemySatellite();
	
	CHECK(spawnedLaserGeneratorWhenPresent.size() == 0);
	CHECK(spawnedEnemySatelliteWhenPresent.size() == 0);
}

TEST_CASE("EnemySpawner will spawn new enemy if current enemy is respawnable")
{
	Grid grid{800, 600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);
	
	shared_ptr<IMovingEntity> enemy_ptr_forRespawn = make_shared<Enemy>(grid);
	shared_ptr<IMovingEntity> enemy_ptr_noRespawn = make_shared<Enemy>(grid);
	
	vector<shared_ptr<IMovingEntity>> vectorEnemyRespawn;
	vector<shared_ptr<IMovingEntity>> vectorEnemyNoRespawn;
	
	while(enemy_ptr_forRespawn->getPosition().getRadius() < grid.getRadius())
	{
		enemy_ptr_forRespawn->move();
	}
	enemy_ptr_forRespawn->move();
	
	vectorEnemyRespawn.push_back(enemy_ptr_forRespawn);
	auto respawnedEnemy = enemyspawner_ptr->respawnEnemyNormal(vectorEnemyRespawn);
	
	
	vectorEnemyNoRespawn.push_back(enemy_ptr_noRespawn);
	auto noRespawnedEnemy = enemyspawner_ptr->respawnEnemyNormal(vectorEnemyNoRespawn);
	
	CHECK(vectorEnemyRespawn.size() == 1);
	CHECK(vectorEnemyNoRespawn.size() == 1);
	CHECK(respawnedEnemy.size() == 1);
	CHECK(noRespawnedEnemy.size() == 0);
}

TEST_CASE("Enemy spawner can make normal enemies and satellites shoot")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);
	vector<shared_ptr<IMovingEntity>> enemyVector;
	
	auto spawnedEnemyNormal = enemyspawner_ptr->spawnEnemyNormal();
	auto spawnedEnemySatellite = enemyspawner_ptr->spawnEnemySatellite();
	
	enemyVector.push_back(spawnedEnemyNormal[0]);
	enemyVector.push_back(spawnedEnemySatellite[0]);
	enemyVector.push_back(spawnedEnemySatellite[1]);
	enemyVector.push_back(spawnedEnemySatellite[2]);
	
	std::shared_ptr<Satellite> conditionSatellite = std::dynamic_pointer_cast<Satellite>(enemyVector[1]);
	while(conditionSatellite->getLifeCycle() < 12)
	{
		enemyVector[1]->move();
		enemyVector[2]->move();
		enemyVector[3]->move();
	}

	auto vectorProjectiles = enemyspawner_ptr->enemyShoot(enemyVector);
	
	CHECK(vectorProjectiles.size() == 4);
	CHECK(vectorProjectiles[0]->getEntityType() == EntityType::ENEMY_BULLET);
}

TEST_CASE("Enemy Spawner can only spawn 50 enemies per game")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);
	vector<shared_ptr<IMovingEntity>> enemyVector;
	
	while(enemyVector.size() != 50)
	{
		enemyVector.push_back(enemyspawner_ptr->spawnEnemyNormal()[0]);
	}
	
	CHECK(enemyVector.size() == 50);
	auto spawnedAnotherEnemy = enemyspawner_ptr->spawnEnemyNormal();
	CHECK(spawnedAnotherEnemy.size() == 0);
	CHECK(enemyspawner_ptr->getEnemyReserves() == 0);
}