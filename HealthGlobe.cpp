#include "HealthGlobe.hpp"

HealthGlobe::HealthGlobe(int hp, World* w) : Object(w)
{
    type = EntityType::Consumable;
    health = hp;
    model = 'H';
    damage = 0;
}
