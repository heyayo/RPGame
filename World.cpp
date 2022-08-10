#include "World.hpp"
#include <iostream>
#include "macros.hpp"

World::World(V2 newSize) : size(newSize)
{
    content = new char*[size.y];
    for (int i = 0; i < size.y; i++)
    {
        content[i] = new char[size.x];
        for (int j = 0; j < size.x; j++)
        {
            content[i][j] = ' ';
        }
    }
    EnemyCount = 0;
    PlayerAlive = true;
}

World::~World()
{
    for (int i = 0; i < size.y; i++)
    {
        delete [] content[i];
    }
    delete [] content;
}

void World::Inhabit(Entity* e)
{
    if (e->GetType() == Entity::Hostile)
        EnemyCount++;
    Inhabitants.PushBack(e);
    UpdateLocation(e);
}

void World::UpdateLocation(Entity* e)
{
    V2 oldLoc = e->GetOldPosition();
    V2 loc = e->GetPosition();
    char eModel = e->GetModel();
    char eAtOldLoc = GetAtLoc(oldLoc);

    Replace(loc, eModel);
    if (eAtOldLoc == eModel)
    {
        if (loc == oldLoc)
            return;
        Replace(oldLoc, ' ');
    }
}

void World::Replace(V2 loc, char r)
{
    content[loc.y][loc.x] = r;
}

char World::GetAtLoc(V2 loc)
{
    return content[loc.y][loc.x];
}

void World::Spawn(Entity* e)
{
    Inhabit(e);
    Replace(e->GetPosition(), e->GetModel());
}

V2 World::GetSize() { return size; }
char** World::GetContents() { return content; }

Entity *World::FindByLoc(V2 loc)
{
    for (int i = 0; i < Inhabitants.top; i++)
    {
        if (Inhabitants[i] == nullptr)
            continue;
        if (Inhabitants[i]->GetPosition() == loc)
            return Inhabitants[i];
    }
    return nullptr;
}

Entity *World::GetInhabitants(unsigned index)
{
    return Inhabitants[index];
}

unsigned World::GetPopCap()
{
    return Inhabitants.top;
}

void World::StateCheck()
{
    for (int i = 0; i < Inhabitants.top; i++)
    {
        if (Inhabitants[i] == nullptr)
            continue;
        if (Inhabitants[i]->GetHealth() <= 0)
        {
            Entity* temp = Inhabitants[i];
            if (temp->GetType() == Entity::Friendly)
                PlayerAlive = false;
            Replace(temp->GetPosition(),' ');
            print(temp->GetModel() << " Died At Position " << temp->GetPosition().x <<','<<temp->GetPosition().y)
            Inhabitants.Nullify(i);
            delete temp;
        }
    }
}

void World::UpdateAll()
{
    for (int i = 0; i < Inhabitants.top; i++)
    {
        if (Inhabitants[i] == nullptr)
            continue;
        UpdateLocation(Inhabitants[i]);
    }
}

void World::Dehabit(Entity * e)
{
    unsigned index = FindByPointer(e);
    if (index == -1)
        return;
    Entity* temp = Inhabitants[index];
    Replace(temp->GetPosition(), ' ');
    Inhabitants.Nullify(index);
    delete temp;
}

unsigned World::FindByPointer(Entity * e)
{
    for (int i = 0; i < Inhabitants.top; i++)
    {
        if (Inhabitants[i] == nullptr)
            continue;
        if (Inhabitants[i] == e)
            return i;
    }
    return -1;
}

void World::TickEnemyCount(int delta)
{
    EnemyCount += delta;
}

bool World::ECCHeck()
{
    return (EnemyCount>0);
}

bool World::GetPlayerVitals()
{
    return PlayerAlive;
}
