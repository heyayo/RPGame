#include <iostream>
#include "Melee.hpp"
#include "Ranged.hpp"
#include "Game.hpp"
#include "macros.hpp"
#include "Math.hpp"

int main()
{
    World* currentWorld = new World(V2(10,10));
    Entity* playerChar = nullptr;
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
    LoadPtr(currentWorld,playerChar);

    print(playerChar->GetRange())
    bool Running = true;
    while (Running)
    {
        Draw(currentWorld);
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

        currentWorld->UpdateLocation(playerChar);
    }

    delete currentWorld;
    delete playerChar;
}
