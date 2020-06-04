template <typename T>
struct Node
{
  T key;
  struct Node *next;
  struct Node *prev;
};