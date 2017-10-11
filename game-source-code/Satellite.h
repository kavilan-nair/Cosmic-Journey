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
