#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "IMovingEntity.h"
#include "Grid.h"

/**
* EnemyBullet class - represents the projectile that can be fired by enemies.
* Inherits from IMovingEntity class.
*/
class EnemyBullet : public IMovingEntity
{
    public:
        /**
        * @brief Parameterized constructor. Creates EnemyBullet object at the position of the enemy with the same angle.
        * @param enemyPos is an object of type Position that contains the position of the Enemy that is to fire the bullet.
        * @param grid is an object of type Grid which contains data about the grid height, width, center and radius.
        */
        EnemyBullet(const Position& enemyPos, const Grid& grid);
        /**
        * Default destructor. Destroys the object once it has gone out of scope.
        */
        ~EnemyBullet();
        /**
        * @brief Inherited from IMovingEntity.  Gets a copy of the EnemyBullet positional data.
        * @return Position of the EnemyBullet Object containing center, current position, radius and angle.
        */      
        virtual Position getPosition() override;
        /**
        * @brief Inherited from IMovingEntity. Returns a strongly typed enum, EntityType.
        * @return ENEMY_BULLET which is a strongly typed enum class EntityType.
        */
        virtual EntityType getEntityType() override;
        /**
        * @brief Inherited from IMovingEntity. Returns a bool member variable whether EnemyBullet object is alive or not.
        * @return _aliveStatus.
        */
        virtual void move() override;
        /**
        * @brief Inherited from IMovingEntity. Returns a bool member variable whether EnemyBullet object is alive or not.
        * @return bool
        */
        virtual bool isAlive() override;
        /** 
        * @brief Inherited from IMovingEntity. Returns false as it overrides base class but has no use.
        * @return bool
        */ 
        virtual bool getRespawn() override;
         /**
        * @brief Inherited from IMovingEntity. Sets the EnemyBullet dead when killed. 
        */
        virtual void setDead() override;
        /**
        * @brief Inherited from IMovingEntity. Returns the radius of the EnemyBullet.
        * @return float with radius of the EnemyBullet.
        */
        virtual float getHitRadius() override;
        
    private:
        Position _enemyBulletPos;
        const Grid _grid;
        bool _aliveStatus;
        bool _reSpawn;
        float _radiusFactor;
        const float _radiusIncrease;
        const float _hitRadius;
};

#endif // ENEMYBULLET_H