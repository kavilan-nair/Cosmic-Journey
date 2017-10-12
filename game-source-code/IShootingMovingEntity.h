#ifndef ISHOOTINGGAMEOBJECT_H
#define ISHOOTINGGAMEOBJECT_H

#include "IMovingEntity.h"
#include "PlayerBullet.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

/**
* IShootingMovingEntity class - Interface class, containing pure virtual functions that need to be overriten by derived classes.
* Inherits from IMovingEntity class.
*/
class IShootingMovingEntity: public IMovingEntity
{
    public:
        /**
        * @brief Inherited from IMovingEntity. Pure virtual function that returns Position of the derived class.
        * @return Position of the derived object containing center, current position, radius and angle.
        */
        virtual Position getPosition() = 0;
        /**
        * @brief Inherited from IMovingEntity. Pure virtual function that returns the enum EntityType of the derived class.
        * @return enum type of the strongly typed enum class EntityType.
        */
        virtual EntityType getEntityType() = 0;
        /**
        * @brief Inherited from IMovingEntity. Pure virtual function that moves the object.
        */
        virtual void move() = 0;
        /**
        * @brief Inherited from IMovingEntity. Pure virtual function that returns whether an object is alive or not.
        * @return bool
        */
        virtual bool isAlive() = 0;
        /**
        * @brief Pure virtual function that returns a vector of shared pointers of the protectile.
        * @return Vector of shared pointers of IMovingEntity type.
        */
        virtual vector<shared_ptr<IMovingEntity>>  shoot() = 0;
        /**
        * @brief Inherited from IMovingEntity. Pure virtual function that returns whether the object can respawn or not.
        * @return bool
        */ 
        virtual bool getRespawn() = 0;
        /**
        * @brief Inherited from IMovingEntity. Pure virtual function that sets the object dead when killed. 
        */
        virtual void setDead() = 0;
        /**
        * @brief Inherited from IMovingEntity. Pure virtual function that returns the radius of the object.
        * @return float with radius of the object.
        */
        virtual float getHitRadius() = 0;
};

#endif // ISHOOTINGGAMEOBJECT_H