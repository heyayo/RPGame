#ifndef RPGAME_OBJECTS_HPP
#define RPGAME_OBJECTS_HPP

#include "Entity.hpp"
#include "World.hpp"

class Object : public Entity
{
protected:
    World* liveIn;
public:
    Object(World*);
    void SetPosition(V2);
    virtual Object* UseObject();
};


#endif
