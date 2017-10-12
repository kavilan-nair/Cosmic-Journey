#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "IMovingEntity.h"
#include "Grid.h"

/**
* PlayerBullet class - represents the projectile that can be fired by the player.
* Inherits from IMovingEntity class.
*/
class PlayerBullet : public IMovingEntity
{
    public:
        /**
        * Parameterized constructor. Creates PlayerBullet object at the position of the player depending on bulletNumber.
        * @param playerPos is an object of type Position that contains the position of the Player that is to fire the bullet.
        * @param grid is an object of type Grid which contains data about the grid height, width, center and radius.
        * @param bulletNumber is of type int, if this value is 0, it creates the bullet at the angle of the player. If this value is 1, it creates it +10 degrees away from player and -10 degrees if the number is 3. This is to allow the functionality for the player to fire 2 bullets with a weapon upgrade.
        */
        PlayerBullet(const Position& playerPos, const Grid& grid, const int& bulletNumber);
        /**
        * Default destructor. Destroys the object once it has gone out of scope.
        */
        ~PlayerBullet();
        /**
        * Inherited from IMovingEntity.
        * Returns a copy of the Position object of the PlayerBullet which contains data about the origin, current position, angle and radius.
        */     
        virtual Position getPosition() override;
        /**
        * Inherited from IMovingEntity.
        * Returns a strongly typed enum of EntityType, PLAYERBULLET.
        * @return EntityType enum.
        */
        virtual EntityType getEntityType() override;
        /**
        * Inherited from IMovingEntity.
        * Moves player bullet radially intwards until it is near the centre of the grid sets the alive status to dead once past this point.
        */
        virtual void move() override;
        /**
        * Inherited from IMovingEntity.
        * Returns a boolean member variable whether player bullet object is alive or not.
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
        Position _playerBulletPos;
        const Grid _grid;
        bool _aliveStatus;
        bool _reSpawn;
        const float _hitRadius;
        const float _radiusIncrease;
        const int _movementCondition;
};

#endif // PLAYERBULLET_H