#include "Package.hpp"

Package::Package(TurnType type) : tt(type)
{
}

void Package::LoadPackage(V2 package)
{
    pack = package;
}

TurnType Package::GetType()
{
    return tt;
}

V2 Package::GetPackage()
{
    return pack;
}

Package::~Package()
{
}
