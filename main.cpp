#include <iostream>
#include "Melee.hpp"
#include "Ranged.hpp"
#include "Game.hpp"

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
    }

    playerChar->SetPosition(V2(5,3));
    currentWorld->Spawn(playerChar);

    Draw(currentWorld);

    playerChar->SetPosition(V2(2,1));
    currentWorld->UpdateLocation(playerChar);

    Draw(currentWorld);

    delete currentWorld;
    delete playerChar;
}
