#ifndef RPGAME_PLAYER_HPP
#define RPGAME_PLAYER_HPP
#include "World.hpp"

class Player : public Entity
{
protected:
    World* liveIn;
public:
    Player(World*);
    ~Player();

    void Move(V2);
};

#endif
