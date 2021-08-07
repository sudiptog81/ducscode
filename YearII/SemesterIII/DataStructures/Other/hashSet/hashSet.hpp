#include "../linkedLists/doublyLinkedList.hpp"

class HashSet
{
protected:
  DoublyLinkedList<char> *arr;

public:
  HashSet()
  {
    arr = new DoublyLinkedList<char>[26];
  }

  ~HashSet()
  {
    delete arr;
  }

  int hash(char ch)
  {
    return (ch - 97) % 26;
  }

  int find(char ch)
  {
    DoublyLinkedList<char> list = arr[hash(ch)];
    if (list.contains(ch))
      return true;
    return false;
  }

  void add(char ch)
  {
    DoublyLinkedList<char> list = arr[hash(ch)];
    if (list.contains(ch))
      return;
    list.pushBack(ch);
  }
};
