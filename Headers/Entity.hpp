#ifndef RPGAME_ENTITY_HPP
#define RPGAME_ENTITY_HPP

#include "V2.hpp"

class Entity
{
    V2 oldPos;

protected:
    int health;
    int damage;
    int range;

    char model;

    V2 pos;

public:
    Entity();
    ~Entity();

    void SetPosition(V2);

    V2 GetPosition();
    V2 GetOldPosition();
    char GetModel();
    int GetRange();
    int GetHealth();
    int GetDamage();

    virtual void Move(V2) = 0;
    virtual void Attack(V2) = 0;
    void Damage(int);
};


#endif
