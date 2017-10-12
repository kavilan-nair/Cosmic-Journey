#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(const Grid& grid) 
    : _grid(grid),
      _maxEnemies(50),
      _satelliteSpawned(false), 
      _laserGeneratorSpawned(false), 
      _allEnemiesSpawned(false), 
      _allSatellitesSpawned(false)
{
}

EnemySpawner::~EnemySpawner()
{
}

vector<shared_ptr<IMovingEntity>> EnemySpawner::spawnEnemyNormal()
{
    vector<shared_ptr<IMovingEntity>> enemiesNormal; 
    int randomSpawnFactor = rand()%2000;
    if(_maxEnemies > 0 && randomSpawnFactor == 1)
    {		
        _enemy = std::make_shared<Enemy>(_grid);
        enemiesNormal.push_back(_enemy);     
        _maxEnemies -= 1;
    }
    if(_maxEnemies == 0)
    {
        _allEnemiesSpawned = true;
    }
    return enemiesNormal;
}

vector<shared_ptr<IMovingEntity>> EnemySpawner::spawnAsteroid()
{
    vector<shared_ptr<IMovingEntity>> asteroids; 
    int randomSpawnFactor = rand()%8000;
    if(randomSpawnFactor == 1 && _allEnemiesSpawned == false)
    {
        _asteroid = std::make_shared<Asteroid>(_grid);
        asteroids.push_back(_asteroid);
    }
    return asteroids;
}

vector<shared_ptr<IMovingEntity>> EnemySpawner::respawnEnemyNormal(vector<shared_ptr<IMovingEntity>>& gameObjects)
{
    vector<shared_ptr<IMovingEntity>> enemiesNormal; 
    for (auto &gameObject : gameObjects)
    {
        if(gameObject->getRespawn() == true)
        {
            _enemy = std::make_shared<Enemy>(_grid);
            enemiesNormal.push_back(_enemy);
        }
    }
    return enemiesNormal;
}

vector<shared_ptr<IMovingEntity>> EnemySpawner::spawnEnemySatellite()
{
    vector<shared_ptr<IMovingEntity>> satelliteEnemies; 
    int randomSpawnFactor = rand()%7500;
    if(randomSpawnFactor == 1 && _maxEnemies > 0 && _satelliteSpawned == false && !(_maxEnemies-3 <= 0))
    {
        int spawnAngle = rand()%360;
        for (auto i = 1; i != 4; i++)
        {
            _satellite = std::make_shared<Satellite>(_grid,spawnAngle,i);
            satelliteEnemies.push_back(_satellite);
            for (auto &enemyBullet :  _satellite->shoot() ) satelliteEnemies.push_back(enemyBullet);
        }
        _maxEnemies -= 3;
    }
    if(_maxEnemies == 0) _allSatellitesSpawned = true;
    
    return satelliteEnemies;
}

vector<shared_ptr<IMovingEntity>> EnemySpawner::spawnLaserGenerator()
{
    vector<shared_ptr<IMovingEntity>> laserGenerators; 
    int randomSpawnFactor = rand()%6000;
    if(randomSpawnFactor == 1 && _laserGeneratorSpawned == false && _allEnemiesSpawned == false)
    {
        int startAngle = rand()%360;
        _laserGenerator = std::make_shared<LaserGenerator>(_grid,startAngle,1);
        laserGenerators.push_back(_laserGenerator);
        _laserGenerator = std::make_shared<LaserGenerator>(_grid,startAngle,2);
        laserGenerators.push_back(_laserGenerator);
        for(int i = 1; i <= 7;i++)
        {
            for (auto &laser :  _laserGenerator->shoot() ) laserGenerators.push_back(laser);
        }
    }
    return laserGenerators;
}

void EnemySpawner::checkLaserGenAndSat(vector<shared_ptr<IMovingEntity>>& gameObjects )
{
    int laserGenCount = 0;
    int satteliteCount = 0;
    for (auto &i : gameObjects)
    {
        if (i->getEntityType() == EntityType::LASER_GENERATOR)
            laserGenCount++;
        if (i->getEntityType() == EntityType::SATELLITE)
            satteliteCount++;
    }
    
    if (laserGenCount > 0)
        _laserGeneratorSpawned = true;
    else
        _laserGeneratorSpawned = false;
        
    if (satteliteCount > 0)
        _satelliteSpawned = true;
    else
        _satelliteSpawned = false;
}

vector<shared_ptr<IMovingEntity>> EnemySpawner::enemyShoot(vector<shared_ptr<IMovingEntity>>& gameObjects)
{
    vector<shared_ptr<IMovingEntity>> projectilesFired; 
    for(auto &i : gameObjects)
    {
        if(i->getEntityType() == EntityType::ENEMY)
        {
            int shootChance = rand()%2000;
            if(shootChance == 1)
            {
                std::shared_ptr<IShootingMovingEntity> entity = std::dynamic_pointer_cast<IShootingMovingEntity>(i);
                for (auto &enemyBullet :  entity->shoot() ) projectilesFired.push_back(enemyBullet);
            }
        }
    }
    
    for(auto &i :gameObjects)
    {
        if(i->getEntityType() == EntityType::SATELLITE)
        {
            std::shared_ptr<Satellite> entitySat = std::dynamic_pointer_cast<Satellite>(i);
            if(entitySat->getLifeCycle() > 11)
            {
                int shootChance = rand()%10000;
                if(shootChance == 1)
                {
                    for (auto &satBullet :  entitySat->shoot() ) projectilesFired.push_back(satBullet);
                }
            }
        }
    }
    return projectilesFired;
}