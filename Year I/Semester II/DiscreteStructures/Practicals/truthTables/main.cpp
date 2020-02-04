#include <iostream>

using namespace std;

int main()
{
    bool x, y;
    bool inputs[4][2] = {
        {true, true},
        {true, false},
        {false, true},
        {false, false}};

    cout << "x\ty\tAND\tOR\tXOR\t"
         << "x->y\tx<->y\tXNOR\t"
         << "NOT\tNAND\tNOR\n------------------------"
         << "-----------------------------------------"
         << "---------------------\n";

    for (int i = 0; i < 4; i++)
    {
        int x = inputs[i][0], y = inputs[i][1];

        cout << x << "\t" << y << "\t"
             << (x && y) << "\t"
             << (x || y) << "\t"
             << ((x || y) && !(x && y)) << "\t"
             << (!x || y) << "\t"
             << ((!x || y) && (!y || x)) << "\t"
             << (!((x || y) && !(x && y))) << "\t"
             << !x << " " << !y << "\t"
             << !(x && y) << "\t"
             << !(x || y) << endl;
    }

    return 0;
}