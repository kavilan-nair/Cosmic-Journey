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
    float _factor = 0.00001;
    const float _hitRadius = 6;
};

#endif // ENEMYBULLET_H