/**
 * Generic Stack Implementation
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cstdlib>
#include <iostream>
#include <exception>

using namespace std;

template <class T>
class Stack
{
private:
  int tos;
  int size;
  T *array;

public:
  Stack(int size)
  {
    this->tos = -1;
    this->size = size;
    this->array = new T[100];
  }

  void push(T element)
  {
    if (this->tos == this->size - 1)
    {
      throw overflow_error("Stack Overflow: Could not push last element");
    }
    else
    {
      this->array[++(this->tos)] = element;
    }
  }  
  
  T pop()
  {
    if (this->tos < 0)
    {
      throw underflow_error("Stack Underflow: Could not pop from the stack");
    }
    else
    {
      return this->array[(this->tos)--];  
    }
  }

  int getTOS()
  {
    return this->tos;
  }
};

int main()
{
  srand(1);
  Stack<int> array(10);

  for (int i = 0; i <= 10; i++)
  {
    int j = rand();
    cout << "Pushing " << j << "..." << endl;
    try
    {
      array.push(j);
      cout << "TOS = " << array.getTOS() << endl;
    }
    catch (const overflow_error &e)
    {
      cerr << e.what() << endl;
    }
  }

  for (int i = 0; i <= 10; i++)
  {
    cout << "TOS = " << array.getTOS() << endl;
    try
    {
      int j = array.pop();
      cout << "Popped " << j << "..." << endl;
    }
    catch (const underflow_error &e)
    {
      cerr << e.what() << endl;
    }
  }

  return 0;
}
