#include "Ranged.hpp"
#include "macros.hpp"
#include "Math.hpp"

Ranged::Ranged(World * live) : Player(live)
{
    model = 'R';
    range = 5;
    health = RandIntRange(80,100);
    damage = RandIntRange(15,20);
}
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
    {
        print("Out of Range")
        return;
    }

    if (weapon != nullptr)
    {
        target->Damage(damage + weapon->GetDamage());
        print("Damaged " << target->GetModel() << " By " << damage + weapon->GetDamage())
        return;
    }
    target->Damage(damage);
    print("Damaged " << target->GetModel() << " By " << damage)
}
