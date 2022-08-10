#include "Enemy.hpp"

Enemy::Enemy(V2 newPos, World* w) : liveIn(w)
{
    SetPosition(newPos);
    type = EntityType::Hostile;
}

void Enemy::SetTarget(Entity * tart)
{
    target = tart;
}

void Enemy::Move(V2 deltaPos)
{
    V2 deltedPos = pos + deltaPos;
    if (liveIn->FindByLoc(deltedPos) != nullptr)
        return;
    SetPosition(pos+deltaPos);
}

Enemy::Enemy(World * w) : liveIn(w)
{
    type = EntityType::Hostile;
}

void Enemy::Attack(V2)
{
    target->Damage(damage);
}

Enemy::~Enemy()
{
    liveIn->TickEnemyCount(-1);
}
