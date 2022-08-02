#include "Entity.hpp"

Entity::Entity() {}
Entity::~Entity() {}

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
