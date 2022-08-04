#include "Turn.hpp"

Turn::Turn()
{
    packed = false;
    packages = nullptr;
    messageCount = 0;
}

Turn::~Turn() { delete packages;}

int Turn::GetIterations()
{
    return packCount;
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
    SetMessage(mesgPack, 0);
    SetIterations(iter);
}

void Turn::SetIterations(int iter)
{
    packCount = iter + messageCount;
    if (packages == nullptr)
    {
        packages = new int[packCount];
        return;
    }
    delete packages;
    packages = new int[packCount];
}

void Turn::ClearPackages()
{
    delete packages;
    packages = new int[packCount];
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

int Turn::GetMessageCount()
{
    return messageCount;
}

void Turn::SetMessageCount(int count)
{
    messageCount = count;
}

void Turn::SetMessage(std::string message, unsigned int index)
{
    packages[index] = message;
}
