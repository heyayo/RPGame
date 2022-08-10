#include "Weapon.hpp"

Weapon::Weapon(int dmg, World* w) : Object(w)
{
    type = EntityType::Weapons;
    damage = dmg;
    model = 'W';
}

Object *Weapon::UseObject()
{
    liveIn->Dehabit(this);
    return this;
}
