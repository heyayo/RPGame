#include "Entity.hpp"
#include "macros.hpp"

Entity::Entity()
{
    pos = V2(0,0);
    oldPos = V2(0,0);
}
Entity::~Entity()
{
    print("DEATH OF A DREAM")
}

V2 Entity::GetPosition()
{
    return pos;
}

V2 Entity::GetOldPosition()
{
    return oldPos;
}

char Entity::GetModel()
{
    return model;
}

void Entity::SetPosition(V2 newPos)
{
    oldPos = pos;
    pos = newPos;
}

void Entity::Damage(int dmg)
{
    health -= dmg;
}

int Entity::GetRange()
{
    return range;
}

int Entity::GetHealth()
{
    return health;
}

int Entity::GetDamage()
{
    return damage;
}

Entity::EntityType Entity::GetType()
{
    return type;
}
