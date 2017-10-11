#ifndef ASTEROID_H
#define ASTEROID_H

#include "IMovingEntity.h"
#include "Grid.h"
#include <stdlib.h>

class Asteroid : public IMovingEntity
{
public:
    Asteroid(const Grid& grid);
    ~Asteroid();
    virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
	virtual bool getRespawn() override;
    virtual void setDead() override;
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