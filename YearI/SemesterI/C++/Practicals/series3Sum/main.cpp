/**
 *  WAP to find sum upto n terms of the series: 
 *   S = 1 - 1/(2^2) + 1/(3^3) - ... 1/(n^n)
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

//

#include <iostream>

using namespace std;

int power(int);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: ./main number_of_terms";
        return -1;
    }

    float sum = 0;

    for (int i = 1; i <= atoi(argv[1]); i++)
    {
        if (i % 2 == 0)
        {
            sum -= 1.0 / static_cast<float>(power(i));
        }
        else
        {
            sum += 1.0 / static_cast<float>(power(i));
        }
    }

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Sum: " << sum << endl;

    return 0;
}

int power(int a)
{
    int t = 1;
    for (int i = 1; i <= a; i++)
        t *= a;
    return t;
}