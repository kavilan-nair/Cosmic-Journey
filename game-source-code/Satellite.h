#ifndef SATELLITE_H
#define SATELLITE_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "EnemyBullet.h"

/**
* Satellite class - represents the Satellite ship.
* Inherits from IShootingMovingEntity class.
*/
class Satellite : public IShootingMovingEntity
{
    public:
        /**
        * @brief Parameterized constructor. Inherits from the IShootingMovingEntity class. Creates a Satellite at center of the circle.
        * @param grid is an object of type Grid which contains data about the height, width, center and radius.
        * @param inAngle is an int which contains the angle the object will be created at.
        * @param numSatellite is an int which tells the constructor which Satellite to in the group to create. 
        */
        Satellite(const Grid& grid, int& inAngle, const int& numSatellite);
        /**
        * @brief Default destructor. Destroys the Satellite object.
        */
        ~Satellite();
        /**
        * @brief Inherited from IShootingMovingEntity. Gets a copy of the Satellite's positional data.
        * @return Position of the Satellite Object containing center, current position, radius and angle.
        */
        virtual Position getPosition() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Gets a copy of the type the Satellite is.
        * @return SATELLITE type of the strongly typed enum class EntityType.
        */
        virtual EntityType getEntityType() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Moves the Satellite radially outwards from center and later gyrates it.
        */
        virtual void move() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns whether Satellite is alive or not.
        * @return bool with either true or false.
        */
        virtual bool isAlive() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns the amount of EnemyBullet fired.
        * @return vector of shared pointers of EnemyBullet type.
        */
        virtual vector<shared_ptr<IMovingEntity>>  shoot() override; 
        /**
        * @brief Inherited from IShootingMovingEntity. Returns false as it overrides base class but has no use.
        * @return bool with value of false.
        */ 
        virtual bool getRespawn() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Sets the Satellite dead when killed. 
        */
        virtual void setDead() override;
        /**
        * @brief Inherited from IShootingMovingEntity. Returns the radius of the Satellite.
        * @return float with radius value of the Satellite.
        */
        virtual float getHitRadius() override;
        /**
        * @brief Returns the current life-cycle of the Satellite.
        * @return int with life-cycle of the Satellite.
        */
        int getLifeCycle(){return _lifeCycle;};

    private:
        Position _satellitePos;
        const Grid _grid;		
        bool _aliveStatus;
        const float _hitRadius;
        float _radiusFactor;
        float _gyrationRadius;
        int _lifeCycle;
        const int _phase1;
        const int _phase2;
        const int _phase3;
        const float _radiusIncrease;
};

#endif // SATELLITE_H
