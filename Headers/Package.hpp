#ifndef RPGAME_PACKAGE_HPP
#define RPGAME_PACKAGE_HPP

#include "V2.hpp"

enum TurnType
{
    Move,
    Attack
};

class Package
{
    V2 pack;
    TurnType tt;
public:
    Package(TurnType);
    ~Package();

    void LoadPackage(V2);

    V2 GetPackage();
    TurnType GetType();
};


#endif
