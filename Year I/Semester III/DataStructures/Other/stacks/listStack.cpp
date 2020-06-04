#include "../linkedLists/node.h"
#include "../linkedLists/doublyLinkedList.hpp"

template <typename T>
class Stack
{
  DoublyLinkedList<T> list;

public:
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

int main(void)
{
  Stack<int> stack;

  for (int i = 1; i <= 5; i++)
  {
    cout << "Pushing " << i << "...\n";
    stack.push(i);
  }

  for (int i = 1; i <= 5; i++)
  {
    cout << "Popped " << stack.pop() << "...\n";
  }

  return 0;
}

