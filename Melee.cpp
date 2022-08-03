#include "Melee.hpp"
#include "macros.hpp"

Melee::Melee(World* live) : Player(live) { model = 'M'; }
Melee::~Melee() {}

void Melee::Attack(V2 spot)
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
