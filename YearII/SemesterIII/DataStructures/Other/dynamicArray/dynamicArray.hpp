#include <iostream>

using namespace std;

template <typename T>
class DynamicArray
{
protected:
    T *arr;
    int size;
    int capacity;

public:
    DynamicArray()
    {
        arr = new T[1];
        size = 0;
        capacity = 1;
    }

    ~DynamicArray()
    {
        delete arr;
    }

    T get(int index)
    {
        if (index < 0 || index >= size)
            throw;
        return arr[index];
    }

    void set(int index, int val)
    {
        if (index < 0 || index >= size)
            throw;
        arr[index] = val;
    }

    void pushBack(int val)
    {
        if (size == capacity)
        {
            T *newArr = new T[2 * capacity];
            for (int i = 0; i < size; i++)
                newArr[i] = arr[i];
            delete arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[size] = val;
        size++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
            throw;
        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    void display()
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "]\nsize: " << size
             << " capacity: " << capacity
             << endl;
    }
};