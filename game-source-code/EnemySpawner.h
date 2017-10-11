#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "Enemy.h"
#include "EnemyBullet.h"
#include "Grid.h"
#include "Satellite.h"
#include "LaserGenerator.h"
#include "Asteroid.h"

class EnemySpawner
{
public:
    EnemySpawner(const Grid& grid);
    ~EnemySpawner();
    
    vector<shared_ptr<IMovingEntity>> spawnEnemyNormal();
    vector<shared_ptr<IMovingEntity>> spawnAsteroid();
    vector<shared_ptr<IMovingEntity>> respawnEnemyNormal(vector<shared_ptr<IMovingEntity>>& gameObjects);
    vector<shared_ptr<IMovingEntity>> spawnEnemySatellite();
    vector<shared_ptr<IMovingEntity>> spawnLaserGenerator();
	vector<shared_ptr<IMovingEntity>> enemyShoot(vector<shared_ptr<IMovingEntity>>& gameObjects);
    
    void checkLaserGenAndSat(vector<shared_ptr<IMovingEntity>>& gameObjects );
    int getEnemyReserves(){return _maxEnemies;};
    
private:
    const Grid _grid;
    
    int _maxEnemies;
    bool _satelliteSpawned;
    bool _laserGeneratorSpawned;
    bool _allEnemiesSpawned;
    bool _allSatellitesSpawned;

    shared_ptr<Enemy> _enemy;
    shared_ptr<Satellite> _satellite;
    shared_ptr<LaserGenerator> _laserGenerator;
    shared_ptr<Asteroid> _asteroid ;
};

#endif // ENEMYSPAWNER_H