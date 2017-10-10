#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <cmath>
#include "Position.h"
#include "EntityType.h"

/**
 * @brief IGameObject Class - Is an interface class that does magical things
 */

class IMovingEntity
{
public:
        virtual Position getPosition() = 0;
        virtual EntityType getEntityType() = 0;
        virtual void move() = 0;
		virtual bool isAlive() = 0;
        virtual void setDead() = 0;
		virtual bool getRespawn() = 0;
        virtual float getHitRadius() = 0;
};

#endif // IGAMEOBJECT_H
