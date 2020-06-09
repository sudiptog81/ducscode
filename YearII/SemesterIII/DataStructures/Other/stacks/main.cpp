#include "./listStack.hpp"

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
