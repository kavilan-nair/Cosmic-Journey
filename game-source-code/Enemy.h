#ifndef ENEMY_H
#define ENEMY_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "EnemyBullet.h"

/**
* Enemy class - represents the Enemy ship.
* Inherits from IShootingMovingEntity class.
*/
class Enemy : public IShootingMovingEntity
{
    public:
        /**
        * @brief Parameterized constructor. Inherits from the IShootingMovingEntity class. Creates Enemy at center of the circle.
        * @param grid is an object of type Grid which contains data about the height, width, center and radius.
        */
        Enemy(const Grid& grid);
        /**
        * @brief Default deconstructor. Destroys the Enemy once it has gone out of scope.
        */
        ~Enemy();
        /**
        * @brief Inherited from IShootingMovingEntity. Gets a copy of the Enemy's positional data.
        * @return Position of the Enemy Object containing center, current position, radius and angle.
        */
        virtual Position getPosition() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Gets a copy of the type the Enemy is.
        * @return ENEMY type of the strongly typed enum class EntityType.
        */
        virtual EntityType getEntityType() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Moves the Enemy radially outwards from center.
        */
        virtual void move() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns a boolean whether Enemy is alive or not.
        * @return Boolean with either true or false.
        */
        virtual bool isAlive() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns the amount of EnemyBullet fired.
        * @return Vector of shared pointers of EnemyBullet type.
        */
        virtual vector<shared_ptr<IMovingEntity>> shoot() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns whether Enemy is respawning or not.
        * @return Boolean with true or false.
        */
        virtual bool getRespawn() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Sets the Enemy dead when killed. 
        */
        virtual void setDead() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns the radius of the Enemy.
        * @return Float with radius of the Enemy.
        */
        virtual float getHitRadius() override;
        
    private:
        Position _enemyPos;
        const Grid _grid;
        EnemyBullet _enemyBullet;
        float _speed;
        float _radiusFactor;
        const float _radiusIncrease;
        float _hitRadius;
        bool _aliveStatus;
        bool _reSpawn;
};

#endif // ENEMY_H