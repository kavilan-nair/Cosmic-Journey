#ifndef PLAYER_H
#define PLAYER_H

#include "IShootingMovingEntity.h"
#include "Grid.h"
#include "Direction.h"
#include "PlayerBullet.h"
#include "WeaponType.h"

class Player : public IShootingMovingEntity
{
public:
    Player(const Grid& grid);
    ~Player();
    virtual Position getPosition() override;
    virtual EntityType getEntityType() override;
    virtual void move() override;
	virtual bool isAlive() override;
    virtual vector<shared_ptr<IMovingEntity>>  shoot() override;    
    virtual bool getRespawn() override;
    virtual void setDead() override;
    virtual float getHitRadius() override;
	
    Direction getDirection(); 
    WeaponType getWeaponType(); 
	
    void setDirection(const Direction& direction); 
    void upgradeWeaponDouble();
    void upgradeWeaponTriple();
    bool isGameOver();
    int getLives();
    int addScore(const int& points);
    int getScore();
    
private:
    
    void respawn();
    Position _playerPos;
	bool _aliveStatus;
	Direction _direction;
	Grid _grid;
	PlayerBullet _playerBullet;
    WeaponType _weaponType = WeaponType::SINGLE;
	bool _reSpawn;
    const float _hitRadius = 24;
    int _lives = 3;
    int _score = 0;
};

#endif // PLAYER_H