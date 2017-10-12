#ifndef LASERGENERATOR_H
#define LASERGENERATOR_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "LaserField.h"

/**
* LaserGenerator class - represents the outer laser generator ships.
* Inherits from IShootingMovingEntity class.
*/
class LaserGenerator : public IShootingMovingEntity
{
public:
	/**
	* @brief Parameterized constructor. Inherits from the IShootingMovingEntity class. Creates a LaserGenerator at center of the circle.
	* @param grid is an object of type Grid which contains data about the height, width, center and radius.
	* @param inAngle is an int which contains the angle the object will be created at.
	* @param typeSide is an int which tells the constructor which side the LaserGenerator object is. 
	*/
	LaserGenerator(const Grid& grid, int inAngle, const int& typeSide);
	/**
	* @brief Default deconstructor. Destroys the LaserGenerator once it has gone out of scope.
	*/
	~LaserGenerator();
	/**
	* @brief Inherited from IShootingMovingEntity. Gets a copy of the LaserGenerator's positional data.
	* @return Position of the LaserGenerator Object containing center, current position, radius and angle.
	*/
	virtual Position getPosition() override;
	/**
	* @brief Inherited from IShootingMovingEntity. Gets a copy of the type the LaserGenerator is.
	* @return LASER_GENERATOR type of the strongly typed enum class EntityType.
	*/
    virtual EntityType getEntityType() override;
	/**
	* @brief Inherited from IShootingMovingEntity. Moves the LaserGenerator radially outwards from center.
	*/
    virtual void move() override;
	/**
	* @brief Inherited from IShootingMovingEntity. Returns a boolean whether LaserGenerator is alive or not.
	* @return Boolean with either true or false.
	*/
	virtual bool isAlive() override;
	/**
	* @brief Inherited from IShootingMovingEntity. Returns the amount of LaserField fired.
	* @return Vector of shared pointers of LaserField type.
	*/
    virtual vector<shared_ptr<IMovingEntity>> shoot() override; 
	/** 
	* @brief Inherited from IShootingMovingEntity. Returns false as it overrides base class but has no use.
	* @return Boolean with false.
	*/ 
	virtual bool getRespawn() override;
	/**
	* @brief Inherited from IShootingMovingEntity. Sets the LaserGenerator dead when killed. 
	*/
	virtual void setDead() override;
	/**
	* @brief Inherited from IShootingMovingEntity. Returns the radius of the LaserGenerator.
	* @return Float with radius of the LaserGenerator.
	*/
    virtual float getHitRadius() override;


private:
	Position _laserGeneratorPos;
	const Grid _grid;
	int _fieldLine;
	bool _aliveStatus;
	int _originalAngle;
	float _radiusFactor;
	const float _hitRadius;
	const float _radiusIncrease;
};

#endif // LASERGENERATOR_H