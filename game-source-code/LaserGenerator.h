#ifndef LASERGENERATOR_H
#define LASERGENERATOR_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "LaserField.h"

class LaserGenerator : public IShootingMovingEntity
{
public:
	LaserGenerator(const Grid& grid, int inDirection, const int& typeSide);
	virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
    virtual vector<shared_ptr<IMovingEntity>> shoot() override; 
	virtual bool getRespawn() override;
	virtual void setDead() override;
    virtual float getHitRadius() override;
	~LaserGenerator();

private:
	Position _laserGeneratorPos;
	const Grid _grid;
	float _factor = 0.005;
	bool _aliveStatus;
	int _originalAngle;
	int _fieldLine;
	const float _hitRadius = 15;
};

#endif // LASERGENERATOR_H