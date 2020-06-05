#include "../linkedLists/doublyLinkedList.hpp"

template <typename T>
class Queue
{
  DoublyLinkedList<T> list;

public:
  T top()
  {
    return list.getFront()->key;
  }

  void enqueue(T key)
  {
    list.pushBack(key);
  }

  T dequeue()
  {
    if (list.empty())
      throw;
    T el = top();
    list.popFront();
    return el;
  }
};

int main(void)
{
  Queue<int> queue;

  for (int i = 1; i <= 5; i++)
  {
    cout << "Enqueuing " << i << "...\n";
    queue.enqueue(i);
  }

  for (int i = 1; i <= 5; i++)
  {
    cout << "Dequeued " << queue.dequeue() << "...\n";
  }

  return 0;
}
