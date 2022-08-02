#include "Game.hpp"
#include <iostream>

void Draw(World* w)
{
    V2 size = w->GetSize();
    char** world = w->GetContents();
    for (int i = 0; i < size.y; i++)
    {
        for (int j = 0; j < size.x; j++)
        {
            std::cout << world[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Parse(Turn<T> result, Entity* curTurn)
{
    if (!result.Pack())
        return;
    T* packages = result.GetPackages();
    switch (result.GetType())
    {
        case Move:
            curTurn->Move(V2(packages[1],packages[0]));
            break;
        case Attack:
            break;
        case Inventory:
            break;
    }
}

template<typename T>
void Query(Turn<T> &result)
{
    T* packs = result.GetPackages();
    const char** list = result.GetMessages();
    for (int i = 0; i < result.GetIterations(); i++)
    {
        print(list[i])
        query(packs[i])
    }
    result.Pack();
}
