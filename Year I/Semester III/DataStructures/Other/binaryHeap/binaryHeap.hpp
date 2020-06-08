#include <cmath>
#include <iostream>

using namespace std;

class BinaryHeap
{
protected:
  int size = 0;
  static const int maxSize = 1e3;
  int *arr;

  int parent(int index)
  {
    return (index - 1) / 2;
  }

  int leftChild(int index)
  {
    return 2 * index + 1;
  }

  int rightChild(int index)
  {
    return 2 * index + 2;
  }

  void swap(int &a, int &b)
  {
    int t = a;
    a = b;
    b = t;
  }

  void siftUp(int index)
  {
    while (index > 0 && arr[parent(index)] < arr[index])
    {
      swap(arr[parent(index)], arr[index]);
      index = parent(index);
    }
  }

  void siftDown(int index)
  {
    int maxIndex = index;
    int l = leftChild(index);
    if (l < size && arr[l] > arr[maxIndex])
      maxIndex = l;
    int r = rightChild(index);
    if (r < size && arr[r] > arr[maxIndex])
      maxIndex = r;
    if (index != maxIndex)
    {
      swap(arr[maxIndex], arr[index]);
      siftDown(maxIndex);
    }
  }

public:
  BinaryHeap()
  {
    arr = new int[maxSize];
  }

  ~BinaryHeap()
  {
    delete arr;
  }

  static BinaryHeap *buildHeap(int *arr, int size)
  {
    BinaryHeap *heap = new BinaryHeap;
    heap->arr = arr;
    heap->size = size;
    for (int i = size / 2 - 1; i >= 0; i--)
      heap->siftDown(i);
    return heap;
  }

  static void heapSort(int *arr, int size)
  {
    BinaryHeap *heap = buildHeap(arr, size);
    for (int i = 0; i < size - 1; i++)
    {
      heap->swap(arr[0], arr[--heap->size]);
      heap->siftDown(0);
    }
  }

  void insert(int priority)
  {
    if (size == maxSize)
      throw;
    arr[size++] = priority;
    siftUp(size);
  }

  int extractMax()
  {
    int result = arr[0];
    arr[0] = arr[size-- - 1];
    siftDown(0);
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
    for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
    cout << "]\nsize: " << size
         << " root: " << arr[0]
         << endl;
  }
};