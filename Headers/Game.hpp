#ifndef RPGAME_GAME_HPP
#define RPGAME_GAME_HPP

#include "World.hpp"
#include "Turn.hpp"

#define print(x) std::cout << x << std::endl;
#define query(x) std::cin >> x;

void Draw(World*);

template<typename T>
void Parse(Turn<T>);

template<typename T>
void Query(Turn<T>&);

#endif
