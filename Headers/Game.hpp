#ifndef RPGAME_GAME_HPP
#define RPGAME_GAME_HPP

#include "World.hpp"
#include "Turn.hpp"

void Draw(World*);
void Parse(Turn, Entity*);
void Query(Turn&);

#endif
