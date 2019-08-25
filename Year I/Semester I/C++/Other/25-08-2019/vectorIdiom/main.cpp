#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int choice, n;

  cout << "Choice - (1) Array Idiom (2) STL Idiom: ";
  cin >> choice;

  if (choice == 2)
  {
    cout << "Enter any number of integers & end with <EOF>: \n";

    vector<int> ivec;

    // populating the vector
    while (cin >> n)
    {
      ivec.push_back(n);
    }

    // accessing the vector
    for (vector<int>::iterator i = ivec.begin(); i != ivec.end(); i++)
      cout << *i << " ";

    ivec.clear();
  } // STL Idiom

  else if (choice == 1)
  {
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;

    vector<int> ivec(size);

    // populating the vector
    for (int i = 0; i < ivec.size(); i++)
    {
      cin >> n;
      ivec[i] = n;
    }

    // accessing the vector
    for (int i = 0; i < ivec.size(); i++)
      cout << ivec[i] << " ";

    ivec.clear();
  } // Array Idiom

  cout << endl;

  return 0;
}
