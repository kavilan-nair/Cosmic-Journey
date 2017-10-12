#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "IMovingEntity.h"
#include <vector>
#include <memory>
#include <cmath>

using std::vector;
using std::shared_ptr;

/**
* CollisionHandler class - detects whether objects collide and set there _aliveStatus to false. This class also checks whether the gun is viable for an uprade, calculates points scored and number of enemies killed for a frame.
*/

class CollisionHandler
{
	public:
		/**
		* Moves enemy bullet radially outwards until it is out of the grid radius and then sets the alive status to dead.
		* @param gameObjects is a vector of shared pointers of type IMovingEntity and contains all current active gameObjects.
		*/
		void checkCollisions(vector<shared_ptr<IMovingEntity>>& gameObjects);
		/**
		* Returns true of false depending on whether a group of 3 satellites has been destroyed.
		* @return true/false.
		*/
		bool isWeaponUpgradable();
		/**
		* Returns the number of points scored per frame and is of type int.   
		* @return _points
		*/
		int getPoints();
		/**
		* Returns the number of enemies killed per frame and is of type int.   
		* @return _enemiesKilled
		*/
		int getEnemiesKilled();
		
	private:
		/**
		* Returns float containing the distance between gameObject1 and gameObject2 using the distance formula.
		* @param gameObject1 is an object of type IMovingEntity
		* @param gameObject2 is an object of type IMovingEntity
		* @return float containing distance between the two gameObjects
		*/
		float getDistance(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
		/**
		* Checks whether the PlayerBullet object collides with the Enemy object, it then sets the alive status to dead for both objects
		* @param gameObject1 is an object of type IMovingEntity
		* @param gameObject2 is an object of type IMovingEntity
		*/
		void playerBulletCollidesWithEnemies(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
		/**
		* Checks whether the Enemy object collides with the Player object, it then sets the alive status to dead for both objects
		* @param gameObject1 is an object of type IMovingEntity
		* @param gameObject2 is an object of type IMovingEntity
		*/
		void enemyCollidesWithPlayers(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
		/**
		* Checks whether the PlayBullet object collides with the Satellite object, it then sets the alive status to dead for both objects
		* @param gameObject1 is an object of type IMovingEntity
		* @param gameObject2 is an object of type IMovingEntity
		*/
		void playerBulletCollidesWithSatellites(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
		/**
		* Checks whether the PlayBullet object collides with the LaserGenerator object, it then sets the alive status to dead for both objects
		* @param gameObject1 is an object of type IMovingEntity
		* @param gameObject2 is an object of type IMovingEntity
		*/
		void playerBulletCollidesWithLaserGenerator(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
		/**
		* Checks whether the LaserField object collides with the Player object, it then sets the alive status to dead for both objects
		* @param gameObject1 is an object of type IMovingEntity
		* @param gameObject2 is an object of type IMovingEntity
		*/
		void laserFieldCollidesWithPlayer(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
		/**
		* Checks whether the Asteroid object collides with the Player object, it then sets the alive status to dead for both objects
		* @param gameObject1 is an object of type IMovingEntity
		* @param gameObject2 is an object of type IMovingEntity
		*/
		void asteroidCollidesWithPlayer(shared_ptr<IMovingEntity>& gameObject1, shared_ptr<IMovingEntity>& gameObject2);
		/**
		* Checks whether there is more than one set of of LaserGenerators alive on the grid
		* @param gameObjects is a vector of  object of type IMovingEntity
		*/
		void updateLaserGenerators(vector<shared_ptr<IMovingEntity>>& gameObjects);
		/**
		* Resets the _pointsMultiplier to 1x
		*/
		void resetMultiplier();
		
		bool _areSatellitesDestroyed = false;
		int _satellitesKilled = 0;
		int _points = 0;
		int _pointsMultiplier = 1;
		int _enemiesKilled = 0;
};

#endif // COLLISIONHANDLER_H