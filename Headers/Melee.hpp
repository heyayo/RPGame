#ifndef RPGAME_MELEE_HPP
#define RPGAME_MELEE_HPP

#include "Player.hpp"

class Melee : public Player
{
public:
    Melee(World*);
    ~Melee();

    void Attack(V2);
};

#endif
