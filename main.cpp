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
    // Initialize Randomizer
    InitRandom(time(NULL));
    // Create Game Variables Part One
    World* currentWorld = new World(V2(10,10)); // Game World
    Player* playerChar = nullptr; // Empty Player Placeholder

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
    Enemy* enemy1 = new Goblin(currentWorld); // First Enemy
    currentWorld->Spawn(enemy1);
    Enemy* enemy2 = new Goblin(currentWorld); // Second Enemy
    currentWorld->Spawn(enemy2);
    Enemy* enemy3 = new Goblin(currentWorld); // Third Enemy
    currentWorld->Spawn(enemy3);
    Object* wep = new Weapon(10, currentWorld); // One Weapon
    currentWorld->Spawn(wep);
    HealthGlobe* health1 = new HealthGlobe(20, currentWorld); // First Health Globe
    currentWorld->Spawn(health1);
    HealthGlobe* health2 = new HealthGlobe(20, currentWorld); // Second Health Globe
    currentWorld->Spawn(health2);
    enemy1->SetTarget(playerChar);
    enemy2->SetTarget(playerChar);
    enemy3->SetTarget(playerChar);

    LoadPtr(currentWorld); // Save World Pointer to Game Functions
    while (true)
    {
        system("CLS"); // Clear Screen
        if (!currentWorld->ECCheck() || !currentWorld->GetPlayerVitals())
            break; // Check Game Status
        Draw(currentWorld); // Print World
        PrintStats(); // Print Statistics
        // Query Player on Move
        char queryResult;
        print("Enter a Move")
        print("m to move | a to attack")
        query(queryResult)
        switch (queryResult)
        {
            // Parse Player Move
            case 'm':
                Parse(playerChar, MoveStage());
                break;
            case 'a':
                Parse(playerChar, AttackStage());
                break;
            default:
                print("INVALID OPTION")
        }

        // Check if any entity died
        currentWorld->StateCheck();
        // Tick Goblin AI
        TickNPC();
        // Update All Entity Positions
        currentWorld->UpdateAll();
    }

    // Determine who Won and cleanup
    if (!currentWorld->ECCheck())
    {
        print("You Win")
        delete playerChar;
    }
    if (!currentWorld->GetPlayerVitals())
    {
        print("You Died");
        for (int i = 0; i < currentWorld->GetPopCap(); i++)
        {
            // Delete remaining Goblins
            Entity* temp = currentWorld->GetInhabitants(i);
            if (temp == nullptr)
                continue;
            if (temp->GetType() == Entity::EntityType::Hostile)
            {
                currentWorld->Kill(temp);
            }
        }
    }
    //delete world
    delete currentWorld;
    //delete weapon
    delete wep;
    system("pause");
}
