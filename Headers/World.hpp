#ifndef RPGAME_WORLD_HPP
#define RPGAME_WORLD_HPP

#include "V2.hpp"
#include "Entity.hpp"
#include "DArray.hpp"

class World
{
    V2 size;
    char** content;
    DArray<Entity*> Inhabitants;

    void Replace(V2, char);
    char GetAtLoc(V2);

public:
    World(V2);
    ~World();

    void Inhabit(Entity*);
    void UpdateLocation(Entity*);
    void Spawn(Entity*);

    V2 GetSize();
    char** GetContents();

    Entity* FindByLoc(V2);
};

#endif
