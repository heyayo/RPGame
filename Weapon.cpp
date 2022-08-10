#include "Weapon.hpp"

Weapon::Weapon(int dmg, World* w) : Object(w)
{
    type = EntityType::Weapons;
    damage = dmg;
    model = 'W';
}

// Equip Object While Removing from World
Object *Weapon::UseObject()
{
    liveIn->Dehabit(this);
    return this;
}
