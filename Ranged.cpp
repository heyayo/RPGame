#include "Ranged.hpp"

Ranged::Ranged(World * live) : Player(live) { model = 'R'; }
Ranged::~Ranged() {}

void Ranged::Attack(V2 spot)
{
    if (spot.x < 0)
        spot.x *= -1;
    if (spot.y < 0)
        spot.y *= -1;

    if (spot.Length() > range)
        return;

    Entity* target = liveIn->FindByLoc(spot);
}
