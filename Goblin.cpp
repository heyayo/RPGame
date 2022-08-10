#include "Goblin.hpp"
#include "Math.hpp"
#include "Config.hpp"

Goblin::Goblin(V2 newPos, World* w) : Enemy(newPos, w)
{
    model = GoblinModel;
    range = GoblinRange;
    health = RandIntRange(GoblinHPMin,GoblinHPMax);
    damage = RandIntRange(GoblinDMGMin,GoblinDMGMax);
}

// Goblin "AI"
void Goblin::DoTurn()
{
    V2 dist = target->GetPosition() - pos;
    if (dist.Length() > range)
    {
        int deltaX, deltaY;
        if (dist.x < 0)
            deltaX = -1;
        else
            deltaX = 1;
        if (dist.y < 0)
            deltaY = 1;
        else
            deltaY = -1;

        Move(V2(
        deltaX,
        deltaY
        ));
        return;
    }
    Attack(V2(0,0));
}

Goblin::Goblin(World* w) : Enemy(w)
{
    while(true)
    {
        V2 temp = RandV2Range(V2(2,2), V2(9,9));
        if (w->FindByLoc(temp) == nullptr)
        {
            SetPosition(temp);
            break;
        }
    }
    model = GoblinModel;
    range = GoblinRange;
    health = RandIntRange(GoblinHPMin,GoblinHPMax);
    damage = RandIntRange(GoblinDMGMin,GoblinDMGMax);
}
