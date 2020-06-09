#include <iostream>

using namespace std;

int main()
{
    int n, large, count;

    while (cin >> n)
    {
        if (n > large)
        {
            large = n;
            count = 1;
        }
        else if (n == large)
            count++;
    }

    cout << "Largest: " << large << endl;
    cout << "Frequency: " << count << endl;

    return 0;
}