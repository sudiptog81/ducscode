#include <iostream>

using namespace std;

/**
 * Void (No Value, No Operation)
 */
void someFunction()
{
    cout << "void" << endl;
}

int main()
{
    /**
     * Integer
     *     - short (2 bytes)
     *     - int   (2 bytes)
     *     - long  (4 bytes)
     */
    short a = 3256;
    int b = 65412;
    long c = 34123432LU;

    /**
     * Float
     *      - float       (4 bytes)
     *      - double      (8 bytes)
     *      - long double (10 bytes)
     */
    float d = 31313.23123223f;
    double e = 1.324234332f;
    long double f = 3132767656355353213.312315245764536475867846345453245f;

    /**
     * Character (1 byte)
     */
    char g = 'A';

    /**
     * Boolean (1 bit)
     */
    bool h = true;

    cout << "Integer (short): " << a << endl;
    cout << "Integer (int): " << b << endl;
    cout << "Integer (long): " << c << endl;

    cout << "Float (float): " << d << endl;
    cout << "Float (double): " << e << endl;
    cout << "Float (long double): " << f << endl;

    cout << "Character: " << g << " (" << (int)g << ")" << endl;
    cout << "Boolean: " << h << endl;

    return 0;
}