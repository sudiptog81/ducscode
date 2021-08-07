#include "./listQueue.hpp"

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
