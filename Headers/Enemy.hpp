#ifndef RPGAME_ENEMY_HPP
#define RPGAME_ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Enemy(V2);

    virtual void DoTurn() = 0;
};


#endif