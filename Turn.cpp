#include "Turn.hpp"

template<typename T>
Turn<T>::Turn(const char** book, int repeats, TurnType type)
: messages(book), iterations(repeats), tType(type)
{
    packages = new T[iterations];
    packed = false;
}

template<typename T>
Turn<T>::~Turn() { delete packages; delete messages;}

template<typename T>
int Turn<T>::GetIterations()
{
    return iterations;
}

template<typename T>
const char **Turn<T>::GetMessages()
{
    return messages;
}

template<typename T>
T *Turn<T>::GetPackages()
{
    return packages;
}

template<typename T>
void Turn<T>::Pack()
{
    packed = true;
}

template<typename T>
void Turn<T>::Reset(const char** mesgPack, int iter)
{
    ClearPackages();
    SetMessages(mesgPack);
    SetIterations(iter);
}

template<typename T>
void Turn<T>::SetIterations(int iter)
{
    iterations = iter;
}

template<typename T>
void Turn<T>::SetMessages(const char** mesgPack)
{
    messages = mesgPack;
}

template<typename T>
void Turn<T>::ClearPackages()
{
    delete packages;
    packages = new T[iterations];
}

template<typename T>
TurnType Turn<T>::GetType()
{
    return tType;
}
