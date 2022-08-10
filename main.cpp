#include <iostream>
#include "Melee.hpp"
#include "Ranged.hpp"
#include "Game.hpp"
#include "macros.hpp"
#include "Math.hpp"
#include "Goblin.hpp"
#include "Weapon.hpp"
#include "HealthGlobe.hpp"

int main()
{
    World* currentWorld = new World(V2(10,10));
    Player* playerChar = nullptr;
    Enemy* enemy1 = new Goblin(currentWorld);
    Enemy* enemy2 = new Goblin(currentWorld);
    Enemy* enemy3 = new Goblin(currentWorld);
    Object* wep = new Weapon(10, currentWorld);
    HealthGlobe* health1 = new HealthGlobe(20, currentWorld);
    HealthGlobe* health2 = new HealthGlobe(20, currentWorld);
    health1->SetPosition(V2(1,1));
    health2->SetPosition(V2(9,9));
    wep->SetPosition(V2(2,2));
    InitRandom(1);

    // Ask Which Class Section
    {
        char result = ' ';
        while (playerChar == nullptr)
        {
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
    }
    currentWorld->Spawn(playerChar);
    currentWorld->Spawn(enemy1);
    currentWorld->Spawn(enemy2);
    currentWorld->Spawn(enemy3);
    currentWorld->Spawn(wep);
    currentWorld->Spawn(health1);
    currentWorld->Spawn(health2);
    enemy1->SetTarget(playerChar);
    enemy2->SetTarget(playerChar);
    enemy3->SetTarget(playerChar);
    LoadPtr(currentWorld,playerChar);

    while (true)
    {
        system("CLS");
        if (!currentWorld->ECCHeck() || !currentWorld->GetPlayerVitals())
            break;
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

        currentWorld->StateCheck();
        TickNPC();
        currentWorld->UpdateAll();
    }

    if (!currentWorld->ECCHeck())
    {
        print("You Win");
        delete playerChar;
    }
    if (!currentWorld->GetPlayerVitals())
    {
        print("You Died");
        for (int i = 0; i < currentWorld->GetPopCap(); i++)
        {
            Entity* temp = currentWorld->GetInhabitants(i);
            if (temp == nullptr)
                continue;
            if (temp->GetType() == Entity::EntityType::Hostile)
            {
                currentWorld->Kill(temp);
            }
        }
    }
    delete currentWorld;
    delete wep;
    system("pause");
}
