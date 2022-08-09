#ifndef RPGAME_GAME_HPP
#define RPGAME_GAME_HPP

#include "World.hpp"
#include "Package.hpp"

void Draw(World*);
void Parse(Entity*, Package);
void LoadPtr(World*, Entity*);
Package MoveStage();
Package AttackStage();

#endif
