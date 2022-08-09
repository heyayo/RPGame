#include "Game.hpp"
#include "macros.hpp"
#include <iostream>

World* currentWorld;
Entity* player;

void Draw(World* w)
{
    V2 size = w->GetSize();
    char** world = w->GetContents();
    for (int i = 0; i < size.y; i++)
        std::cout << ' ' << i;
    std::cout << std::endl;
    for (int i = 0; i < size.y; i++)
    {
        std::cout << i;
        for (int j = 0; j < size.x; j++)
        {
            std::cout << world[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Parse(Entity* actor, Package box)
{
    V2 boxpack = box.GetPackage();
    switch (box.GetType())
    {
        case Move:
        {
            actor->Move(boxpack);
            break;
        }
        case Attack:
            actor->Attack(boxpack);
            break;
    }
}

Package MoveStage()
{
    Package boxPack(Move);
    V2 temp = V2(0,0);
    for (int i = 5; i > 0; i--)
    {
        print("WASD To Move | Invalid Means Skip")
        print("You have " << i << " Turns Left")
        char ui;
        query(ui);
        switch (ui)
        {
            case 'w':
                temp.y += 1;
                break;
            case 's':
                temp.y -= 1;
                break;
            case 'a':
                temp.x -= 1;
                break;
            case 'd':
                temp.x += 1;
                break;
            default:
                print("Skipping")
                break;
        }
        print("MOVING BY")
        print('[' << temp.x << ',' << temp.y << ']')
    }
    boxPack.LoadPackage(temp);
    return boxPack;
}

Package AttackStage()
{
    Package boxPack(Attack);
    V2 temp;
    V2 worldSize = currentWorld->GetSize();
    while (true)
    {
        print("Enter X Coordinate of Target")
        query(temp.x)
        print("Enter Y Coordinate of Target")
        query(temp.y)
        if (temp.x < 0 || temp.y < 0 || temp.x > worldSize.x || temp.y > worldSize.y)
            continue;
        break;
    }
    boxPack.LoadPackage(temp);
    return boxPack;
}

void LoadPtr(World* w, Entity* e)
{
    currentWorld = w;
    player = e;
}
