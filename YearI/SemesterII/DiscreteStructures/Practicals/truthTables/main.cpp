/**
 * Write a Program to accept the truth values of variables x and y, 
 * and print the truth table of the following logical operations: 
 * Conjunction, Disjunction, Exclusive OR, Conditional, Bi-conditional, 
 * Exclusive NOR, Negation, NAND, NOR.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
using namespace std;
int main()
{
    int m;
    char x, y;
    cout << "Enter number of trials: ";
    cin >> m;
    bool inputs[m][2];
    for (int i = 0; i < m; i++)
    {
        cout << "Enter truth value pair"
             << " x" << i + 1 << " y" << i + 1
             << " : ";
        cin >> x >> y;
        inputs[i][0] = (x == 'T' || x == 't');
        inputs[i][1] = (y == 'T' || y == 't');
    }
    cout << "x\ty\tAND\tOR\tXOR\t"
         << "x->y\tx<->y\tXNOR\t"
         << "NOT\tNAND\tNOR\n------------------------"
         << "-----------------------------------------"
         << "---------------------\n";
    for (int i = 0; i < m; i++)
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