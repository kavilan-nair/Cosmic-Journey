#ifndef PLAYER_H
#define PLAYER_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "Direction.h"
#include "PlayerBullet.h"
#include "WeaponType.h"

/**
* Player class - represents the Player ship.
* Inherits from IShootingMovingEntity class.
*/
class Player : public IShootingMovingEntity
{
    public:	
        /**
        * @brief Parameterized constructor. Inherits from the IShootingMovingEntity class. Creates Player object on the circumference of the cicle at the bottom.
        * @param grid is an object of type Grid which contains data about the height, width, center and radius.
        */
        Player(const Grid& grid);
        /**
        * @brief Default deconstructor. Destroys the object once it has gone out of scope.
        */
        ~Player();
        /**
        * @brief Inherited from IShootingMovingEntity. Gets a copy of the Player's positional data.
        * @return Position of the Player Object containing center, current position, radius and angle.
        */
        virtual Position getPosition() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Gets a copy of the type the Player is.
        * @return PLAYER type of the strongly typed enum class EntityType.
        */
        virtual EntityType getEntityType() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Moves the Player clockwise, anticlockwise or not at all depending on Direction set.
        */
        virtual void move() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns a boolean whether Player is alive or not.
        * @return Boolean with either true or false.
        */
        virtual bool isAlive() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns the amount of PlayerBullet fired.
        * @return Vector of shared pointers of PlayerBullet type.
        */
        virtual vector<shared_ptr<IMovingEntity>> shoot() override;   
        /**
        * @brief Inherited from IShootingMovingEntity. Returns false as it overrides base class but has no use.
        * @return Boolean with false.
        */ 
        virtual bool getRespawn() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Sets the Player dead when killed. 
        */
        virtual void setDead() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns the radius of the Player.
        * @return Float with radius of the Player.
        */
        virtual float getHitRadius() override;
        /**
        * @brief Returns the Direction of the Player.
        * @return Enum type of the strongly typed enum class Direction.
        */
        Direction getDirection(); 
        /**
        * @brief Returns the current weapon type of the Player.
        * @return Enum type of the strongly typed enum class WeaponType.
        */
        WeaponType getWeaponType(); 
        /**
        * @brief Sets the direction of the Player.
        * @param direction is an enum of the strongly typed enum class Direction.
        */
        void setDirection(const Direction& direction); 
        /**
        * @brief Upgrades the Players weapon from SINGLE to DOUBLE.
        */
        void upgradeWeaponDouble();
        /**
        * @brief Returns whether the Player has a life or not.
        * @return Boolean with either true or false;
        */
        bool isGameOver();
        /**
        * @brief Returns the amount of lives the Player has.
        * @return int with the amount of lives left.
        */
        int getLives();
        /**
        * @brief Keeps track of the Player score by adding to the previous score.
        * @param points is an int variable which has the amount of points earned during the last frame.
        */
        int addScore(const int& points);
        /**
        * @brief Returns the current score of the Player.
        * @return int with the score.
        */
        int getScore();
        
    private:
        /**
        * @brief Sets the Player back to the initial parameters and decreases amount of lives.
        */
        void respawn();

        Position _playerPos;
        bool _aliveStatus;
        Direction _direction;
        const Grid _grid;
        PlayerBullet _playerBullet;
        WeaponType _weaponType;
        bool _reSpawn;
        const float _hitRadius;
        int _lives;
        int _score;
};

#endif // PLAYER_H