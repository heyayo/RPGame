#ifndef RPGAME_PLAYER_HPP
#define RPGAME_PLAYER_HPP
#include "World.hpp"
#include "Objects.hpp"
#include "Character.hpp"

class Player : public Character
{
protected:
    World *liveIn;
    Object* weapon;
public:
    Player(World *);

    ~Player();

    virtual void Move(V2);
    Object* GetWeapon();
};

#endif
