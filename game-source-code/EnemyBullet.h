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
	    * Parameterized constructor. Creates EnemyBullet object at the position of the enemy with the same angle.
        * @param enemyPos is an object of type Position that contains the position of the Enemy that is to fire the bullet.
        * @param grid is an object of type Grid which contains data about the grid height, width, center and radius.
	    */
        EnemyBullet(const Position& enemyPos, const Grid& grid);
        /**
        * Default destructor. Destroys the object once it has gone out of scope.
	    */
        ~EnemyBullet();
	    /**
	    * Inherited from IMovingEntity.
	    * Returns a copy of the Position object of the EnemyBullet which contains data about the origin, current position, angle and radius.
	    */     
        virtual Position getPosition() override;
		/**
	    * Inherited from IMovingEntity.
	    * Returns a strongly typed enum of EntityType, ENEMYBULLET.
	    * @return EntityType enum.
	    */
        virtual EntityType getEntityType() override;
	    /**
	    * Inherited from IMovingEntity.
	    * Moves enemy bullet radially outwards until it is out of the grid radius and then sets the alive status to dead.
	    */
        virtual void move() override;
        /**
        * Inherited from IMovingEntity.
        * Returns a boolean member variable whether enemy bullet object is alive or not.
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
	    * Returns the float radius of the enemy bullet object that is used to check collisions.
	    * @return _hitRadius.
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