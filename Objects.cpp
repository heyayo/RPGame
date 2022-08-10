#include "Objects.hpp"
#include "macros.hpp"

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
}
