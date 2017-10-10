#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "IMovingEntity.h"
#include "Grid.h"

class PlayerBullet : public IMovingEntity
{
public:
    PlayerBullet(const Position& playerPos, const Grid& grid, const int& bulletNumber);
    ~PlayerBullet();
    virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
	virtual bool getRespawn() override;
    virtual void setDead() override;
    virtual float getHitRadius() override;
	
private:
    Position _playerBulletPos;
    const Grid _grid;
    bool _aliveStatus;
	bool _reSpawn;
    const float _hitRadius = 6;
};

#endif // PLAYERBULLET_H