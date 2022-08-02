#ifndef DARRAY_H
#define DARRAY_H

template<typename T, int size = 1>
struct DArray
{
    T* dar;
    int maxSize;
    int top;

    DArray();
    ~DArray();

    void PushBack(T data);
    void Cut(int newSize);
    T ReturnLast();
    T ReturnFirst();

    T operator[] (int id);
};

#endif