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

    void PushBack(T data); // Adds in an Element to Array, expands if necessary
    void Cut(int newSize); // Cuts the array down to size, Keep Elements based on FIFO
    void Nullify(unsigned); // Sets a place in Array to nullptr
    void Delete(unsigned); // Delete an Object in the Array, Safety Net
    int GetTopIndex(); // Gets the Top Index Keeping in Mind the Counting from Zero
    T GetAtIndex(unsigned); // Safety Net, Replaced By operator[] overload
    T ReturnLast(); // Unused but Useful
    T ReturnFirst(); // Unused but Useful

    T operator[] (int id); // Retrieve element via index
};

#endif