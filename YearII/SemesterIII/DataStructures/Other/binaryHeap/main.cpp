#include "./binaryHeap.hpp"

int main(void)
{
  BinaryHeap heap;

  /*
  Consider the given tree with 0-indexing:

                42
              /   \
            29       18
          /   \     /  \
        14     7  18    12
      /   \
    11     13  
  */

  heap.insert(42);
  heap.insert(29);
  heap.insert(18);
  heap.insert(14);
  heap.insert(7);
  heap.insert(18);
  heap.insert(12);
  heap.insert(11);
  heap.insert(13);

  cout << "initial state:\n";
  heap.display();

  cout << "\nmax extracted: "
       << heap.extractMax();

  /*
  After extracting max:

                29
              /   \
            14       18
          /   \     /  \
        13     7  18    12
      / 
    11
  */

  cout << "\nafter extracting max:\n";
  heap.display();

  heap.remove(2);

  /*
  After removing:

                29
              /   \
            14       18
          /   \     /  \
        13     7  11    12
  */

  cout << "\nafter removing 18:\n";
  heap.display();

  heap.changePriority(5, 1);

  /*
  After changing:

                29
              /   \
            14       18
          /   \     /  \
        13     7  1     12
  */

  cout << "\nafter changing priority:\n";
  heap.display();

  cout << "\narray [10..1] sorted using heap sort:\n";
  int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  BinaryHeap::heapSort(arr, 10);
  cout << "[ ";
  for (int i = 0; i < 10; i++)
    cout << arr[i] << " ";
  cout << "]\n";

  return 0;
}