#include "Entity.hpp"

Entity::Entity()
{
    pos = V2(0,0);
    oldPos = V2(0,0);
}
Entity::~Entity()
{
}

// Get Entity Position
V2 Entity::GetPosition()
{
    return pos;
}

// Get Old Entity Position
V2 Entity::GetOldPosition()
{
    return oldPos;
}

// Get Model of Entity
char Entity::GetModel()
{
    return model;
}

// Set Entity Position
void Entity::SetPosition(V2 newPos)
{
    oldPos = pos;
    pos = newPos;
}

// Deduct Health From Entity
void Entity::Damage(int dmg)
{
    health -= dmg;
}

// Get Range of Entity
int Entity::GetRange()
{
    return range;
}

// Get Health of Entity
int Entity::GetHealth()
{
    return health;
}

// Get Damage of Entity
int Entity::GetDamage()
{
    return damage;
}

// Get Type of Entity
Entity::EntityType Entity::GetType()
{
    return type;
}

// Set the Old Position of Entity
void Entity::SetOldPosition(V2 newOldPos)
{
    oldPos = newOldPos;
}
