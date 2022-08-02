cmake_minimum_required(VERSION 3.23)
project(RPGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPGame main.cpp Entity.cpp Headers/Entity.hpp V2.cpp Headers/V2.hpp Headers/World.hpp World.cpp Player.cpp Headers/Player.hpp DArray.cpp Game.cpp Headers/Game.hpp Melee.cpp Headers/Melee.hpp Ranged.cpp Headers/Ranged.hpp Turn.cpp Headers/Turn.hpp Math.cpp Headers/Math.hpp)

target_include_directories(RPGame PUBLIC Headers)
