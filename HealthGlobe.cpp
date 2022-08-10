#include "HealthGlobe.hpp"

HealthGlobe::HealthGlobe(int hp, World* w) : Object(w)
{
    type = Consumable;
    health = hp;
    model = 'H';
}
