#ifndef ISHOOTINGGAMEOBJECT_H
#define ISHOOTINGGAMEOBJECT_H

#include "IMovingEntity.h"
#include "PlayerBullet.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
class IShootingMovingEntity: public IMovingEntity
{
    public:
        virtual Position getPosition() = 0;
        virtual EntityType getEntityType() = 0;
        virtual void move() = 0;
		virtual bool isAlive() = 0;
        virtual vector<shared_ptr<IMovingEntity>>  shoot() = 0;
		virtual bool getRespawn() = 0;
        virtual void setDead() = 0;
        virtual float getHitRadius() = 0;
};

#endif // ISHOOTINGGAMEOBJECT_H
