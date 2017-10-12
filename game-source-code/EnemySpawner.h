#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "Enemy.h"
#include "EnemyBullet.h"
#include "Grid.h"
#include "Satellite.h"
#include "LaserGenerator.h"
#include "Asteroid.h"

/**
* EnemySpawner class - Holds the logic to spawn the non-user controlled entities.
*/
class EnemySpawner
{
    public:
        /**
        * @brief Parameterized constructor. Creates an instance of the enemy spawner for Logic to control.
        * @param grid is an object of type Grid which contains data about the height, width, center and radius.
        */
        EnemySpawner(const Grid& grid);
        /**
        * @brief Default destructor. Destroys the EnemySpawner once it has gone out of scope.
        */
        ~EnemySpawner();
        /**
        * @brief Function that spawns a normal Enemy based on a random number generator.
        * @return vector of shared pointers of type IMovingEntity for enemies spawned.
        */
        vector<shared_ptr<IMovingEntity> > spawnEnemyNormal();
        /**
        * @brief Function that spawns an Asteroid based on a random number generator.
        * @return vector of shared pointers of type IMovingEntity for asteroids spawned.
        */
        vector<shared_ptr<IMovingEntity> > spawnAsteroid();
        /**
        * @brief Function that checks if an enemy is ready for respawning and then spawns a new one.
        * @return vector of shared pointers of type IMovingEntity for enemies respawned.
        */
        vector<shared_ptr<IMovingEntity> > respawnEnemyNormal(vector<shared_ptr<IMovingEntity> >& gameObjects);
        /**
        * @brief Function that spawns a Satellite based on a random number generator.
        * @return vector of shared pointers of type IMovingEntity for group of 3 Satellites spawned.
        */
        vector<shared_ptr<IMovingEntity> > spawnEnemySatellite();
        /**
        * @brief Function that spawns a LaserGenerator group based on a random number generator.
        * @return vector of shared pointers of type IMovingEntity for group of 2 LaserGenerators and 7 LaserFields.
        */
        vector<shared_ptr<IMovingEntity> > spawnLaserGenerator();
        /**
        * @brief Function that makes Enemy and Satellite objects shoot based on a random number generator.
        * @return vector of shared pointers of type IMovingEntity of EnemyBullets fired.
        */
        vector<shared_ptr<IMovingEntity> > enemyShoot(vector<shared_ptr<IMovingEntity> >& gameObjects);
        /**
        * @brief Function that checks how many Satellite and LaserGenerator objects exist and limits spawning of them if they exist.
        */
        void checkLaserGenAndSat(vector<shared_ptr<IMovingEntity> >& gameObjects);
        /**
        * @brief Function that checks how many objects still have to be spawned in the current game iteration.
        * @return int contained the amount of objects that will still be spawned.
        */
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
        shared_ptr<Asteroid> _asteroid;
};

#endif // ENEMYSPAWNER_H