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
    unsigned EnemyCount;
    bool PlayerAlive;

    void Replace(V2, char);
    char GetAtLoc(V2);

public:
    World(V2);
    ~World();

    void Inhabit(Entity*);
    void Dehabit(Entity*);
    void UpdateLocation(Entity*);
    void UpdateAll();
    void Spawn(Entity*);
    void TickEnemyCount(int);
    void StateCheck();

    V2 GetSize();
    char** GetContents();
    Entity* GetInhabitants(unsigned);
    unsigned GetPopCap();

    Entity* FindByLoc(V2);
    unsigned FindByPointer(Entity*);

    bool ECCHeck();
    bool GetPlayerVitals();
};

#endif
