#include "Game.hpp"
#include "macros.hpp"
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

void Parse(Turn result, Entity* curTurn)
{
    if (!result.IsPacked())
        return;
    int* packages = result.GetPackages();
    switch (result.GetType())
    {
        case Move:
            curTurn->Move(V2(packages[1],packages[0]));
            break;
        case Attack:
            curTurn->Attack(V2(packages[1],packages[0]));
            break;
        case Inventory:
            break;
    }
}

void Query(Turn &result)
{
    print("QUERYING")
    int* packs = result.GetPackages();
    std::string* list = result.GetMessages();
    for (int i = 0; i < result.GetIterations() + result.GetMessageCount(); i++)
    {
        if (i < result.GetMessageCount())
        {
            print(list[i])
        }
        else
        {
            print(list[i])
            query(packs[i])
        }
    }
    result.Pack();
    print("QUERIED")
}
