#include <iostream>
#include "Melee.hpp"
#include "Ranged.hpp"
#include "Game.hpp"
#include "macros.hpp"
#include "Math.hpp"

int main()
{
    World* currentWorld = new World(V2(10,10));
    Entity* playerChar;
    InitRandom(1);

    // Ask Which Class Section
    {
        char result = ' ';
        bool good;
        do
        {
            good = false;
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
                    query(result)
                    good = true;
                    break;
            }
        } while (good);
        currentWorld->Spawn(playerChar);
    }

    print(playerChar->GetRange())
    bool Running = true;
    while (Running)
    {
        char queryResult;
        print("Enter a move")
        print("m to move | a to attack")
        query(queryResult)

        Turn Info;
        switch (queryResult)
        {
            case 'm':
                mesPack[0] = "Move on X by?";
                mesPack[1] = "Move on Y by?";
                Info.SetMessage(mesPack, 0);
                Info.SetIterations(2);
                Info.SetType(Move);
                print("INFO SET")
                Query(Info);
                break;
            case 'a':
                mesPack[0] = "Attacking with Range of " + playerChar->GetRange();
                mesPack[1] = "Attack on X by?";
                mesPack[2] = "Attack on Y by?";
                Info.SetMessage(mesPack, 0);
                Info.SetIterations(2);
                Info.SetMessageCount(0);
                Info.SetType(Attack);
                Query(Info);
                break;
            default:
                break;
        }
        print("ATTEMPTING PARSE")
        Parse(Info, playerChar);
        print("PARSED")
        print("DRAWING")
        Draw(currentWorld);
        print("DRAWN")
    }

    delete currentWorld;
    delete playerChar;
}
