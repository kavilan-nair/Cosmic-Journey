#include "Grid.h"
#include <memory>
#include "IMovingEntity.h"
#include "vector"
#include "EnemySpawner.h"
#include <algorithm>

using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Logic deletion function removes dead objects from vector")
{
	Grid grid{800,600};
	shared_ptr<EnemySpawner> enemyspawner_ptr = make_shared<EnemySpawner>(grid);
	vector<shared_ptr<IMovingEntity>> enemyVector;
	
	while(enemyVector.size() != 50)
	{
		enemyVector.push_back(enemyspawner_ptr->spawnEnemyNormal()[0]);
	}
	
	for(auto &i : enemyVector)
	{
		i->setDead();
	}
	
	enemyVector.erase(remove_if(enemyVector.begin(),enemyVector.end(),[]( shared_ptr<IMovingEntity>& gameObject){ return (!gameObject->isAlive()); }), enemyVector.end());
	CHECK(enemyVector.size() == 0);
}