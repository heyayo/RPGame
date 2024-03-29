#include "DArray.hpp"
#include "Entity.hpp"
template struct DArray<Entity*>;

template<typename T, int size>
DArray<T,size>::DArray() : maxSize(size)
{
    dar = new T[maxSize];
    top = 0;
}

template<typename T, int size>
DArray<T,size>::~DArray() { delete dar; }

template<typename T, int size>
void DArray<T,size>::PushBack(T data)
{
    if (top >= maxSize)
    {
        T* temp = new T[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            temp[i] = dar[i];
        }
        delete dar;
        dar = new T[++maxSize];
        for (int i = 0; i < maxSize - 1; i++)
        {
            dar[i] = temp[i];
        }
    }
    dar[top++] = data;
}

template<typename T, int size>
void DArray<T,size>::Cut(int newSize)
{
    if (newSize > maxSize || newSize <= 0)
        return;
    
    T* temp = new T[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        temp[i] = dar[i];
    }
    delete dar;
    dar = new T[newSize];
    for (int i = 0; i < newSize - 1; i++)
    {
        dar[i] = temp[i];
    }
    maxSize = newSize;
    top = newSize;
}

template<typename T, int size>
T DArray<T,size>::ReturnLast()
{
    return dar[top - 1];
}

template<typename T, int size>
T DArray<T,size>::ReturnFirst()
{
    return dar[0];
}

template<typename T, int size>
T DArray<T,size>::operator[] (int id)
{
    return dar[id];
}

template<typename T, int size>
int DArray<T, size>::GetTopIndex()
{
    return top - 1;
}

template<typename T, int size>
void DArray<T, size>::Nullify(unsigned index)
{
    dar[index] = nullptr;
}

template<typename T, int size>
void DArray<T, size>::Delete(unsigned index)
{
    delete dar[index];
}

template<typename T, int size>
T DArray<T, size>::GetAtIndex(unsigned index)
{
    return dar[index];
}
