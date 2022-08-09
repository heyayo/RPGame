#include "Goblin.hpp"
#include "Math.hpp"
#include "macros.hpp"

Goblin::Goblin(V2 newPos, World* w) : Enemy(newPos, w)
{
    model = 'G';
    health = RandIntRange(10,20);
    damage = RandIntRange(5,10);
    range = 1;
}

void Goblin::DoTurn()
{
    V2 dist = target->GetPosition() - pos;
    if (dist.Length() > 1)
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
        print("MOVED" << deltaX << deltaY)
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
    model = 'G';
    health = RandIntRange(10,20);
    damage = RandIntRange(5,10);
    range = 1;
}
