#include "./node.h"
#include "./singlyLinkedList.hpp"
#include "./doublyLinkedList.hpp"

void singlyLinkedList()
{
     SinglyLinkedList<char> list;

     list.pushFront('A');
     list.pushFront('B');
     list.pushFront('C');

     list.popFront();

     list.pushBack('X');
     list.pushBack('Y');
     list.pushBack('Z');

     list.popBack();

     list.insertAfter(list.at(1), 'D');
     list.insertBefore(list.at(1), 'W');

     list.display();

     cout << "list contains X: "
          << (list.contains('X') ? "yes" : "no")
          << endl;
     cout << "list contains C: "
          << (list.contains('C') ? "yes" : "no")
          << endl;

     cout << "index of X: "
          << list.indexOf('X')
          << endl;
     cout << "value at index 1: "
          << list.at(1)->key
          << endl;
}

void doublyLinkedList()
{
     DoublyLinkedList<char> list;

     list.pushFront('A');
     list.pushFront('B');
     list.pushFront('C');

     list.popFront();

     list.pushBack('X');
     list.pushBack('Y');
     list.pushBack('Z');

     list.popBack();

     list.insertAfter(list.at(1), 'D');
     list.insertBefore(list.at(1), 'W');

     list.display();

     cout << "list contains X: "
          << (list.contains('X') ? "yes" : "no")
          << endl;
     cout << "list contains C: "
          << (list.contains('C') ? "yes" : "no")
          << endl;

     cout << "index of X: "
          << list.indexOf('X')
          << endl;
     cout << "value at index 1: "
          << list.at(1)->key
          << endl;
}

int main(void)
{
     cout << "Singly Linked List:" << endl;
     singlyLinkedList();

     cout << endl;

     cout << "Doubly Linked List:" << endl;
     doublyLinkedList();

     return 0;
}

