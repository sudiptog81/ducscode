#include <iostream>

#include "./disjointSet.hpp"

using namespace std;

int main(void)
{
  DisjointSet sets;

  sets.makeSet(1);
  sets.makeSet(2);
  sets.makeSet(3);
  sets.makeSet(4);

  cout << "1 and 4 are in same set? "
       << (sets.find(1) == sets.find(4) ? "yes" : "no")
       << endl;

  cout << "1 and 3 are in same set? "
       << (sets.find(1) == sets.find(3) ? "yes" : "no")
       << endl;

  cout << "union of 1 and 4...\n";

  sets.Union(1, 4);

  cout << "1 and 4 are in same set? "
       << (sets.find(1) == sets.find(4) ? "yes" : "no")
       << endl;

  cout << "1 and 3 are in same set? "
       << (sets.find(1) == sets.find(3) ? "yes" : "no")
       << endl;

  cout << "union of 3 and 4...\n";

  sets.Union(3, 4);

  cout << "1 and 3 are in same set? "
       << (sets.find(1) == sets.find(3) ? "yes" : "no")
       << endl;

  return 0;
}
