#ifndef RPGAME_CHARACTER_HPP
#define RPGAME_CHARACTER_HPP

#include "Entity.hpp"

class Character : public Entity
{
public:
    virtual void Move(V2) = 0;
    virtual void Attack(V2) = 0;
};


#endif
