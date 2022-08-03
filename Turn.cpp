#include "Turn.hpp"

Turn::Turn()
{
    packed = false;
    packages = nullptr;
}

Turn::~Turn() { delete packages;}

int Turn::GetIterations()
{
    return iterations;
}

std::string* Turn::GetMessages()
{
    return messages;
}

int* Turn::GetPackages()
{
    return packages;
}

void Turn::Pack()
{
    packed = true;
}

void Turn::Reset(std::string* mesgPack, int iter)
{
    ClearPackages();
    SetMessages(mesgPack);
    SetIterations(iter);
}

void Turn::SetIterations(int iter)
{
    iterations = iter;
    if (packages == nullptr)
    {
        packages = new int[iterations];
        return;
    }
    delete packages;
    packages = new int[iterations];
}

void Turn::SetMessages(std::string* mesgPack)
{
    messages = mesgPack;
}

void Turn::ClearPackages()
{
    delete packages;
    packages = new int[iterations];
}

TurnType Turn::GetType()
{
    return tType;
}

void Turn::SetType(TurnType type)
{
    tType = type;
}

bool Turn::IsPacked()
{
    return packed;
}
