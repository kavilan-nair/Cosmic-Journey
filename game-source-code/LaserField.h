#ifndef LASERFIELD_H
#define LASERFIELD_H

#include "IShootingMovingEntity.h"
#include "Grid.h"

class LaserField : public IMovingEntity
{
public:
	LaserField(const Grid& grid, int Angle, const int& Location);
	virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
	virtual bool getRespawn() override;
	virtual void setDead() override;
    virtual float getHitRadius() override;
	~LaserField();

private:
	Position _laserFieldPos;
    const Grid _grid;
	float _factor = 0.005;
	bool _aliveStatus;
	int _phase;
	int _oscillationFactor;
    const int _hitRadius = 6;
};

#endif // LASERFIELD_H