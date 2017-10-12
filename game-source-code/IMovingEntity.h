#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <cmath>
#include "Position.h"
#include "EntityType.h"

/**
* IMovingEntity class - contains pure virtual functions that need to be overriten by derived classes.
* Inherits from IMovingEntity class.
*/
class IMovingEntity
{
	public:
		/**
		* @brief Pure virutal function that returns position of the derived class.
		* @return Position of the derived object containing center, current position, radius and angle.
		*/
		virtual Position getPosition() = 0;
		/**
		* @brief Pure virtual function that returns the enum EntityType of the derived class.
		* @return enum type of the strongly typed enum class EntityType.
		*/
		virtual EntityType getEntityType() = 0;
		/**
		* @brief Pure virtual function that moves the object.
		*/
		virtual void move() = 0;
		/**
		* @brief Pure virtual function that returns whether an object is alive or not.
		* @return Boolean with either true or false.
		*/
		virtual bool isAlive() = 0;
		/**
		* @brief Pure virtual function that returns whether the object can respawn or not.
		* @return Boolean with either true or false.
		*/
		virtual void setDead() = 0;
		/**
		* @brief Pure virtual function that sets the object dead when killed. 
		*/
		virtual bool getRespawn() = 0;
		/**
		* @brief Pure virtual function that returns the radius of the object.
		* @return Float with radius of the object.
		*/
		virtual float getHitRadius() = 0;
};

#endif // IGAMEOBJECT_H
