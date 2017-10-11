#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "IMovingEntity.h"
#include "Grid.h"

class EnemyBullet : public IMovingEntity
{
public:
    EnemyBullet(const Position& enemyPos, const Grid& grid);
    ~EnemyBullet();
    virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
	virtual bool getRespawn() override;
    virtual void setDead() override;
    virtual float getHitRadius() override;
    
private:
    Position _enemyBulletPos;
	const Grid _grid;
    
    bool _aliveStatus;
	bool _reSpawn;
    float _radiusFactor;
    const float _radiusIncrease;
    const float _hitRadius;
};

#endif // ENEMYBULLET_H