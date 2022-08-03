#include <iostream>
#include "Melee.hpp"
#include "Ranged.hpp"
#include "Game.hpp"
#include "macros.hpp"

int main()
{
    World* currentWorld = new World(V2(10,10));
    Entity* playerChar;

    // Ask Which Class Section
    {
        print("Pick a Class")
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
                    query(result)
                    good = true;
                    break;
            }
        } while (good);
        currentWorld->Spawn(playerChar);
    }

    bool Running = true;
    while (Running)
    {
        char** mesPack = new char*[5];

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
                Info.SetMessages(mesPack);
                Info.SetIterations(2);
                Info.SetType(Move);
                print("INFO SET")
                Query(Info);
                break;
            case 'a':
                mesPack[0] = "Attack on X by?";
                mesPack[1] = "Attack on Y by?";
                Info.SetMessages(mesPack);
                Info.SetIterations(2);
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
        delete[] mesPack;
    }

    delete currentWorld;
    delete playerChar;
}
