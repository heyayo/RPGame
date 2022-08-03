#include "Ranged.hpp"
#include "macros.hpp"

Ranged::Ranged(World * live) : Player(live) { model = 'R'; }
Ranged::~Ranged() {}

void Ranged::Attack(V2 spot)
{
    Entity* target = liveIn->FindByLoc(spot);
    if (target == nullptr)
    {
        print("No Target on Location")
        return;
    }

    V2 temp = spot - pos;
    if (temp.Length() > range)
        return;

    target->Damage(damage);
}
