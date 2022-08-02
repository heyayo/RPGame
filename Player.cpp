#include "Player.hpp"

Player::Player(World* live) : liveIn(live)
{
    live->Inhabit(this);
    live->UpdateLocation(this);
    model = 'T';
}
Player::~Player() {}

void Player::Move(V2 deltaPos)
{
    SetPosition(pos += deltaPos);
}
