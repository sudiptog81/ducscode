#include "./binaryHeap.hpp"

int main(void)
{
  BinaryHeap heap;

  /*
  Consider the given tree:

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

  cout << "\nafter extracting max:\n";
  heap.display();

  heap.remove(3);

  cout << "\nafter removing 18:\n";
  heap.display();

  heap.changePriority(6, 1);

  cout << "\nafter changing priority:\n";
  heap.display();

  return 0;
}