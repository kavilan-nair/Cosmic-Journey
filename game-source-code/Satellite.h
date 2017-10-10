#ifndef SATELLITE_H
#define SATELLITE_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "EnemyBullet.h"

class Satellite : public IShootingMovingEntity
{
public:
	Satellite(const Grid& grid, int& inDirection,const int& numSatellite);
    ~Satellite();
	virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
    virtual vector<shared_ptr<IMovingEntity>>  shoot() override; 
	virtual bool getRespawn() override;
    virtual void setDead() override;
    virtual float getHitRadius() override;
    int getLifeCycle(){return _lifeCycle;};

private:
	Position _satellitePos;
    const Grid _grid;
    
    const float _hitRadius = 24;
	float _factor = 0.005;
	float _gyrationRadius;
    bool _aliveStatus;
    int _lifeCycle = 1;
};

#endif // SATELLITE_H
