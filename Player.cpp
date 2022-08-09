#include "Player.hpp"
#include "macros.hpp"
#include "Objects.hpp"

Player::Player(World* live) : liveIn(live)
{
    model = 'T';
    type = Friendly;
    weapon = nullptr;
}
Player::~Player() {}

void Player::Move(V2 deltaPos)
{
    V2 deltedPos = pos + deltaPos;
    if (deltedPos.x < 0 || deltedPos.x >= liveIn->GetSize().x)
    {
        print("OUT OF BOUNDS MOVE")
        return;
    }
    if (deltedPos.y < 0 || deltedPos.y >= liveIn->GetSize().x)
    {
        print("OUT OF BOUNDS MOVE")
        return;
    }
    Entity* temp = liveIn->FindByLoc(deltedPos);
    if (temp != nullptr)
    {
        switch (temp->GetType())
        {
            case Hostile:
                print("COLLIDED WITH OBJECT " << temp->GetModel())
                return;
            case Weapons:
                weapon = static_cast<Object*>(temp)->UseObject();
            case Consumable:
                health += static_cast<Object*>(temp)->GetHealth();
                delete temp;
        }
    }
    SetPosition(pos + deltaPos);
}

Object *Player::GetWeapon()
{
    return weapon;
}

void Player::StateUpdate()
{
    if (health <= 0)
        delete this;
}
