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

        cout << (x ? "T" : "F") << "\t" << (y ? "T" : "F") << "\t"
             << ((x && y) ? "T" : "F") << "\t"
             << ((x || y) ? "T" : "F") << "\t"
             << (((x || y) && !(x && y)) ? "T" : "F") << "\t"
             << ((!x || y) ? "T" : "F") << "\t"
             << (((!x || y) && (!y || x)) ? "T" : "F") << "\t"
             << ((!((x || y) && !(x && y))) ? "T" : "F") << "\t"
             << (!x ? "T" : "F") << " " << (!y ? "T" : "F") << "\t"
             << (!(x && y) ? "T" : "F") << "\t"
             << (!(x || y) ? "T" : "F") << endl;
    }

    return 0;
}