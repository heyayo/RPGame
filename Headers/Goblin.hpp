#ifndef RPGAME_GOBLIN_HPP
#define RPGAME_GOBLIN_HPP

#include "Enemy.hpp"
#include "Math.hpp"

class Goblin : public Enemy
{
public:
    Goblin(V2, World*);
    Goblin(World*);
    void DoTurn();
};


#endif
