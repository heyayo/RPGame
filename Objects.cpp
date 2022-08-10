#include "Objects.hpp"
#include "Math.hpp"

// Return Object Pointer when "Using Object"
Object *Object::UseObject()
{
    return this;
}

void Object::SetPosition(V2 newPos)
{
    pos = newPos;
    SetOldPosition(newPos);
}

Object::Object(World * w) : liveIn(w)
{
    health = 1;
    while(true)
    {
        V2 temp = RandV2Range(V2(6,0), V2(9,3));
        if (w->FindByLoc(temp) == nullptr)
        {
            SetPosition(temp);
            break;
        }
    }
}
