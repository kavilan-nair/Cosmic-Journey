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
        * @brief Parameterized constructor. Creates PlayerBullet object at the position of the Player depending on bulletNumber.
        * @param playerPos is an object of type Position that contains the position of the Player that is to fire the bullet.
        * @param grid is an object of type Grid which contains data about the height, width, center and radius.
        * @param bulletNumber is of type int, if this value is 0, it creates the bullet at the angle of the player. If this value is 1, it creates it +10 degrees away from player and -10 degrees if the number is 3. This is to allow the functionality for the player to fire 2 bullets with a weapon upgrade.
        */
        PlayerBullet(const Position& playerPos, const Grid& grid, const int& bulletNumber);
        /**
        * @brief Default destructor. Destroys the PlayerBullet object.
        */
        ~PlayerBullet();
        /**
        * @brief Inherited from IMovingEntity. Gets a copy of the PlayerBullet positional data.
        * @return Position of the PlayerBullet which contains data about the origin, current position, angle and radius.
        */     
        virtual Position getPosition() override;
        /**
        * @brief Inherited from IMovingEntity. Gets a copy of the type the PlayerBullet is.
        * @return PLAYERBULLET type of the strongly typed enum class EntityType.
        */
        virtual EntityType getEntityType() override;
        /**
        * @brief Inherited from IMovingEntity. Moves PlayerBullet radially inwards.
        */
        virtual void move() override;
        /**
        * @brief Inherited from IMovingEntity. Returns a boolean whether PlayerBullet object is alive or not.
        * @return bool with value of true or false.
        */
        virtual bool isAlive() override;
        /**
        * @brief Inherited from IMovingEntity. Returns false as it overrides inherited interface but has no use.
        * @return bool with value of false.
        */
        virtual bool getRespawn() override;
        /**
        * @brief Inherited from IMovingEntity. Sets the PlayerBullet object dead.
        */
        virtual void setDead() override;
        /**
        * @brief Inherited from IMovingEntity. Returns the radius of the enemy PlayerBullet object that is used to check collisions.
        * @return float with value of radius of PlayerBullet object.
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