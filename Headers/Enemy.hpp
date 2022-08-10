#ifndef RPGAME_ENEMY_HPP
#define RPGAME_ENEMY_HPP

#include "Character.hpp"
#include "World.hpp"

class Enemy : public Character
{
protected:
    World* liveIn;
    Entity* target;
public:
    Enemy(V2, World*);
    Enemy(World*);
    ~Enemy();

    void SetTarget(Entity*);
    void Move(V2);
    void Attack(V2);
    virtual void DoTurn() = 0;
};


#endif