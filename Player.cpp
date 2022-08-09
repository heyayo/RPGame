#include "Player.hpp"
#include "macros.hpp"

Player::Player(World* live) : liveIn(live)
{
    live->Inhabit(this);
    live->UpdateLocation(this);
    model = 'T';
}
Player::~Player() {}

void Player::Move(V2 deltaPos)
{
    if ((pos + deltaPos).x < 0 || (pos + deltaPos).x >= liveIn->GetSize().x)
    {
        print("OUT OF BOUNDS MOVE")
        return;
    }
    if ((pos + deltaPos).y < 0 || (pos + deltaPos).y >= liveIn->GetSize().x)
    {
        print("OUT OF BOUNDS MOVE")
        return;
    }
    SetPosition(pos + deltaPos);
}
