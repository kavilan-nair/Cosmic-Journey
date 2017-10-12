#ifndef LASERFIELD_H
#define LASERFIELD_H

#include "IShootingMovingEntity.h"
#include "Grid.h"

/**
* LaserField class - represents the outer laser Field arc.
* Inherits from IMovingEntity class.
*/
class LaserField : public IMovingEntity
{
	public:
		/**
		* @brief Parameterized constructor. Inherits from the IMovingEntity class. Creates a LaserField at center of the circle.
		* @param grid is an object of type Grid which contains data about the height, width, center and radius.
		* @param Angle is an int which contains the angle the object will be created at.
		* @param Location is an int which tells the constructor where in the arc length the LaserField object is. 
		*/
		LaserField(const Grid& grid, int Angle, const int& Location);
		/**
		* @brief Default deconstructor. Destroys the LaserField once it has gone out of scope.
		*/
		~LaserField();
		/**
		* @brief Inherited from IMovingEntity. Gets a copy of the LaserField's positional data.
		* @return Position of the LaserField object containing center, current position, radius and angle.
		*/
		virtual Position getPosition() override;
		/**
		* @brief Inherited from IMovingEntity. Gets a copy of the type the LaserField is.
		* @return LASER_FIELD type of the strongly typed enum class EntityType.
		*/
		virtual EntityType getEntityType() override;
		/**
		* @brief Inherited from MovingEntity. Moves the LaserField radially outwards from center.
		*/
		virtual void move() override;
		/**
		* @brief Inherited from IMovingEntity. Returns a boolean whether LaserField is alive or not.
		* @return Boolean with either true or false.
		*/
		virtual bool isAlive() override;
		/** 
		* @brief Inherited from IMovingEntity. Returns false as it overrides base class but has no use.
		* @return Boolean with false.
		*/ 
		virtual bool getRespawn() override;
		/**
		* @brief Inherited from IMovingEntity. Sets the LaserField dead when killed. 
		*/
		virtual void setDead() override;
		/**
		* @brief Inherited from IMovingEntity. Returns the radius of the LaserField.
		* @return Float with radius of the LaserField.
		*/
		virtual float getHitRadius() override;
		
	private:
		Position _laserFieldPos;
		const Grid _grid;
		bool _aliveStatus;
		int _phase;
		float _radiusFactor;
		int _oscillationFactor;
		const int _hitRadius;
		const float _radiusIncrease;
};

#endif // LASERFIELD_H