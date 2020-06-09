#include "../linkedLists/doublyLinkedList.hpp"

template <typename T>
class Queue
{
  DoublyLinkedList<T> list;

public:
  bool empty()
  {
    return list.empty();
  }

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
