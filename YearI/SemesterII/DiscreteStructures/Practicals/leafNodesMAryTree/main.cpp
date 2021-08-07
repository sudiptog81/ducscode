/**
 * Given a full m-ary tree with i internal vertices, WAP 
 * to find the number of leaf nodes in the tree
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
using namespace std;
int calculateLeafNodes(int m, int i)
{
  /**
   * Let T be the number of total nodes in the full m-ary tree.
   * Let L be the number of leaf nodes in the full m-ary tree.
   * Let i be the number of internal vertives in the full m-ary tree.
   *
   * L + i = T       ..(1)
   * m * i = T - 1   ..(2)
   * => m * i - i + 1 = L
   * => L = i * (m - 1) + 1
   */

  return i * (m - 1) + 1;
}

int main()
{
  int m, i;

  cout << "Enter the maximum number of children in the full m-ary tree: ";
  cin >> m;

  cout << "Enter the number of internal vertices: ";
  cin >> i;

  cout << "Number of Leaf Nodes in the full " << m << "-ary tree: "
       << calculateLeafNodes(m, i) << endl;

  return 0;
}
