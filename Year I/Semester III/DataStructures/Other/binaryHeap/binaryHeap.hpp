#include <cmath>
#include <iostream>

using namespace std;

class BinaryHeap
{
protected:
  int size = 0;
  static const int maxSize = 1e3;
  int arr[maxSize] = {0};

  int parent(int index)
  {
    return index / 2;
  }

  int leftChild(int index)
  {
    return 2 * index;
  }

  int rightChild(int index)
  {
    return 2 * index + 1;
  }

  void swap(int &a, int &b)
  {
    int t = a;
    a = b;
    b = t;
  }

  void siftUp(int index)
  {
    while (index > 1 && arr[parent(index)] < arr[index])
    {
      swap(arr[parent(index)], arr[index]);
      index = parent(index);
    }
  }

  void siftDown(int index)
  {
    int maxIndex = index;
    int l = leftChild(index);
    if (l <= size && arr[l] > arr[maxIndex])
      maxIndex = l;
    int r = rightChild(index);
    if (r <= size && arr[r] > arr[maxIndex])
      maxIndex = r;
    if (index != maxIndex)
    {
      swap(arr[maxIndex], arr[index]);
      siftDown(maxIndex);
    }
  }

public:
  void insert(int priority)
  {
    if (size == maxSize)
      throw;
    arr[++size] = priority;
    siftUp(size);
  }

  int extractMax()
  {
    int result = arr[1];
    arr[1] = arr[size--];
    siftDown(1);
    return result;
  }

  void remove(int index)
  {
    arr[index] = 1e3;
    siftUp(index);
    extractMax();
  }

  void changePriority(int index, int priority)
  {
    int oldPriority = arr[index];
    arr[index] = priority;
    if (priority > oldPriority)
      siftUp(index);
    else
      siftDown(index);
  }

  void display()
  {
    cout << "[ ";
    for (int i = 1; i <= size; i++)
      cout << arr[i] << " ";
    cout << "]\nsize: " << size
         << " root: " << arr[1]
         << endl;
  }
};