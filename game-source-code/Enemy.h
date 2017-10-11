#ifndef ENEMY_H
#define ENEMY_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "EnemyBullet.h"

class Enemy : public IShootingMovingEntity
{
public:
	Enemy(const Grid& grid);
    ~Enemy();
	virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
    virtual vector<shared_ptr<IMovingEntity>> shoot() override;
    virtual void setDead() override;
	virtual bool getRespawn() override;
    virtual float getHitRadius() override;
    
private:
    Position _enemyPos;
    const Grid _grid;
    EnemyBullet _enemyBullet;

	float _speed;
    float _radiusFactor;
    const float _radiusIncrease;
	bool _aliveStatus;
	bool _reSpawn;
};

#endif // ENEMY_H