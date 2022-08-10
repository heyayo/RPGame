#ifndef RPGAME_GAME_HPP
#define RPGAME_GAME_HPP

#include "World.hpp"
#include "Package.hpp"
#include "Player.hpp"
#include "Goblin.hpp"

void Draw(World*);
void PrintStats();
void Parse(Character*, Package);
void LoadPtr(World*, Character*);
void TickNPC();
Package MoveStage();
Package AttackStage();

#endif
