#include "Game.hpp"
#include "macros.hpp"
#include <iostream>
#include <string>

// Save World Pointer for function use
World* currentWorld;

// Draw World
void Draw(World* w)
{
    V2 size = w->GetSize();
    char** world = w->GetContents();
    for (int i = 0; i < size.y; i++)
        std::cout << ' ' << i;
    std::cout << " X" << std::endl;
    for (int i = 0; i < size.y; i++)
    {
        std::cout << i;
        for (int j = 0; j < size.x; j++)
        {
            std::cout << world[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << 'Y' << std::endl;
}

// Do what the user wanted on the character
void Parse(Character* actor, Package box)
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

// Ask user in move turn
Package MoveStage()
{
    Package boxPack(Move);
    V2 temp = V2(0,0);
    for (int i = 2; i > 0; i--)
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

// Ask user in attack turn
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
        {
            print("Out Of Bounds Target")
            continue;
        }
        break;
    }
    boxPack.LoadPackage(temp);
    return boxPack;
}

// Load World Pointer for Function Use
void LoadPtr(World* w)
{
    currentWorld = w;
}

// Print Stats about Inhabitants
void PrintStats()
{
    for (int i = 0; i < currentWorld->GetPopCap(); i++)
    {
        Entity* temp = currentWorld->GetInhabitants(i);
        if (temp == nullptr)
            continue;
        int dmgnum, hpval;
        char modelChar;
        hpval = temp->GetHealth();
        modelChar = temp->GetModel();
        V2 pos = temp->GetPosition();
        std::string wepStat = "";
        if (temp->GetType() == Entity::EntityType::Friendly)
        {
            Player* pTemp = static_cast<Player*>(temp);
            if (pTemp->GetWeapon() != nullptr)
                wepStat = "+" + std::to_string(pTemp->GetWeapon()->GetDamage());
            dmgnum = pTemp->GetDamage();
        }
        else
            dmgnum = temp->GetDamage();
            print(modelChar << " | "
            << hpval << " HP | "
            << dmgnum << wepStat << " DMG | "
            << '[' << pos.x << ',' << pos.y << ']')
    }
}

// Run all Goblin AI
void TickNPC()
{
    for (int i = 0; i < currentWorld->GetPopCap(); i++)
    {
        Entity* temp = currentWorld->GetInhabitants(i);
        if (temp == nullptr)
            continue;
        if (temp->GetType() == Entity::EntityType::Hostile)
        {
            static_cast<Goblin*>(temp)->DoTurn();
        }
    }
}
