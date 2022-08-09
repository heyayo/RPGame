#include <iostream>
#include "Melee.hpp"
#include "Ranged.hpp"
#include "Game.hpp"
#include "macros.hpp"
#include "Math.hpp"
#include "Goblin.hpp"

int main()
{
    World* currentWorld = new World(V2(10,10));
    Player* playerChar = nullptr;
    Enemy* enemy1 = new Goblin(currentWorld);
    Enemy* enemy2 = new Goblin(currentWorld);
    Enemy* enemy3 = new Goblin(currentWorld);
    InitRandom(1);

    // Ask Which Class Section
    while (playerChar == nullptr)
    {
        char result;
        switch (result)
        {
            case 'r':
                playerChar = new Ranged(currentWorld);
                break;
            case 'm':
                playerChar = new Melee(currentWorld);
                break;
            default:
                print("Pick a Class")
                print("r For Ranged | m For Melee")
                query(result)
        }
    }
    currentWorld->Spawn(playerChar);
    currentWorld->Spawn(enemy1);
    currentWorld->Spawn(enemy2);
    currentWorld->Spawn(enemy3);
    enemy1->SetTarget(playerChar);
    enemy2->SetTarget(playerChar);
    enemy3->SetTarget(playerChar);
    LoadPtr(currentWorld,playerChar);

    bool Running = true;
    while (Running)
    {
        print("ROUND")
        currentWorld->UpdateAll();
        Draw(currentWorld);
        PrintStats();
        char queryResult;
        print("Enter a Move")
        print("m to move | a to attack")
        query(queryResult)
        switch (queryResult)
        {
            case 'm':
                Parse(playerChar, MoveStage());
                break;
            case 'a':
                Parse(playerChar, AttackStage());
                break;
            default:
                print("INVALID OPTION")
        }

        TickNPC();
        currentWorld->StateCheck();
    }

    delete currentWorld;
    delete playerChar;
}
