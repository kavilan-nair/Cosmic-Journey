#ifndef ENTITYTYPES_H
#define ENTITYTYPES_H

/**
* EntityType is a strongly typed enum used to by the objects that inherit from IMovingEntity
*/
enum class EntityType
{
    PLAYER = 0,
    ENEMY,
    SATELLITE,
    LASER_GENERATOR,
    PLAYER_BULLET,
    ENEMY_BULLET,
    LASER_FIELD,
    ASTEROID
};

#endif // ENTITYTYPES_H