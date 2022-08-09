#ifndef RPGAME_ENEMY_HPP
#define RPGAME_ENEMY_HPP

#include "Entity.hpp"
#include "World.hpp"

class Enemy : public Entity
{
protected:
    World* liveIn;
    Entity* target;
public:
    Enemy(V2, World*);
    Enemy(World*);

    void SetTarget(Entity*);
    void Move(V2);
    void Attack(V2);
    void StateUpdate();
    virtual void DoTurn() = 0;
};


#endif