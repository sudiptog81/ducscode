#include <iostream>

using namespace std;

int main()
{
  int n;

  cout << "Compiled at " << __TIME__ << " on "
       << __DATE__ << endl;
  cout << "Enter an integer: ";
  cin >> n;

#ifdef DEBUG
  if (n == 0)
    cerr << "\nError: " << __FILE__ << " (" << __LINE__ << ") "
         << "\n\t => n should not be 0\n";
#endif

  return 0;
}
