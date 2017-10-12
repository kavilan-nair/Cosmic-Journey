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
        * @brief Parameterized constructor. Creates Asteroid object at the centre of the grid, the asteroid is also assigned a random angle between 0-360 degreess.
        * @param grid is an object of type Grid which contains data about the grid height, width, center and radius.
        */
        Asteroid(const Grid& grid);
        /**
        * @brief Default destructor. Destroys the object once it has gone out of scope.
        */
        ~Asteroid();
        /**
        * @brief Inherited from IMovingEntity.  Gets a copy of the Asteroid positional data.
        * @return Position of the Asteroid Object containing center, current position, radius and angle.
        */      
        virtual Position getPosition() override;
        /**
        * @brief Inherited from IMovingEntity. Returns a strongly typed enum, EntityType.
        * @return ASTEROID which is a strongly typed enum class EntityType.
        */
        virtual EntityType getEntityType() override;
        /**
        * @brief Inherited from IMovingEntity. Moves Asteroid radially outwards until it is out of the grid radius and then sets the alive status to dead.
        */
        virtual void move() override;
        /**
        * @brief Inherited from IMovingEntity. Returns a bool member variable whether Asteroid object is alive or not.
        * @return bool
        */
        virtual bool isAlive() override;
        /**
        * @brief Inherited from IMovingEntity. Returns a bool whether Asteroid is alive or not.
        * @return bool
        */
        virtual bool getRespawn() override;
        /**
        * @brief Inherited from IMovingEntity. Sets the Asteroid dead when killed. 
        */
        virtual void setDead() override;
        /**
        * @brief Inherited from IMovingEntity. Returns the radius of the Asteroid.
        * @return float with radius of the Asteroid.
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