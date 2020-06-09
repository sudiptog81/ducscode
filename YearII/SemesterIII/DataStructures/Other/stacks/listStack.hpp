#include "../linkedLists/doublyLinkedList.hpp"

template <typename T>
class Stack
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

  void push(T key)
  {
    list.pushFront(key);
  }

  T pop()
  {
    if (list.empty())
      throw;
    T el = top();
    list.popFront();
    return el;
  }
};
