#ifndef ASTEROID_H
#define ASTEROID_H

#include "IMovingEntity.h"
#include "Grid.h"
#include <stdlib.h>

/**
* Asteroid class - represents the asteroid that cant be shot.
* Inherits from IMovingEntity class.
*/
class Asteroid : public IMovingEntity
{
	public:
		/**
		* Parameterized constructor. Creates Asteroid object at the centre of the grid, the asteroid is also assigned a random angle between 0-360 degreess.
		* @param grid is an object of type Grid which contains data about the grid height, width, center and radius.
		*/
		Asteroid(const Grid& grid);
		/**
		* Default destructor. Destroys the object once it has gone out of scope.
		*/
		~Asteroid();
		/**
		* Inherited from IMovingEntity.
		* Returns a copy of the Position object of the asteroid which contains data about the origin, current position, angle and radius.
		*/      
		virtual Position getPosition() override;
		/**
		* Inherited from IMovingEntity.
		* Returns a strongly typed enum, EntityType.
		* @return EntityType enum.
		*/
		virtual EntityType getEntityType() override;
		/**
		* Inherited from IMovingEntity.
		* Moves asteroid radially outwards until it is out of the grid radius and then sets the alive status to dead.
		*/
		virtual void move() override;
		/**
		* Inherited from IMovingEntity.
		* Returns a boolean member variable whether asteroid object is alive or not.
		* @return _aliveStatus.
		*/
		virtual bool isAlive() override;
		/**
		* Inherited from IMovingEntity.
		* Returns false as it overrides inherited interface but has no use.
		* @return false.
		*/
		virtual bool getRespawn() override;
		/**
		* Inherited from IMovingEntity.
		* Sets the boolean _aliveStatus member variable to false.
		*/
		virtual void setDead() override;
		/**
		* Inherited from IMovingEntity.
		* Returns the float radius of the asteroid object that is used to check collisions.
		* @return _hitRadius.
		*/
		virtual float getHitRadius() override;
		
	private:
		const Grid _grid;
		Position _asteroidPos;
		bool _aliveStatus;
		float _radiusFactor;
		const float _radiusIncrease;
		const float _hitRadius; 
};

#endif // ASTEROID_H