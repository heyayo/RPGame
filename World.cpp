#include "World.hpp"
#include <iostream>

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
        Replace(oldLoc, ' ');
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
    Replace(e->GetPosition(), e->GetModel());
}

V2 World::GetSize() { return size; }
char** World::GetContents() { return content; }

Entity *World::FindByLoc(V2 loc)
{
    for (int i = 0; i < Inhabitants.top; i++)
    {
        if (Inhabitants[i]->GetPosition() == loc)
            return Inhabitants[i]
    }
}
