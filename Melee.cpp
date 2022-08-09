#include "Melee.hpp"
#include "macros.hpp"
#include "Math.hpp"

Melee::Melee(World* live) : Player(live)
{
    model = 'M';
    range = 1;
    health = RandIntRange(120,150);
    damage = RandIntRange(25,40);
}
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
