#ifndef RPGAME_ENTITY_HPP
#define RPGAME_ENTITY_HPP

#include "V2.hpp"

class Entity
{
    V2 oldPos;
public:
    enum EntityType
    {
        Friendly,
        Hostile,
        Weapons,
        Consumable
    };
protected:
    int health;
    int damage;
    int range;
    EntityType type;

    char model;

    V2 pos;

public:
    Entity();
    virtual ~Entity();

    void SetPosition(V2);

    V2 GetPosition();
    V2 GetOldPosition();
    char GetModel();
    int GetRange();
    int GetHealth();
    int GetDamage();
    EntityType GetType();

    void Damage(int);
    virtual void Move(V2) = 0;
    virtual void Attack(V2) = 0;
    virtual void StateUpdate() = 0;
};


#endif
