#ifndef RPGAME_RANGED_HPP
#define RPGAME_RANGED_HPP

#include "Player.hpp"

class Ranged : public Player
{
    int CalculateRange(V2);
public:
    Ranged(World*);
    ~Ranged();

    void Attack(V2);
};


#endif
