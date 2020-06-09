#include <iostream>

using namespace std;

int main()
{
    /* Explicit Type Casting Methofs
     *  - static_cast: common casting method (safe)
     *  - dynamic_cast: used to safely cast a super-
     * class pointer (or reference) into a pointer 
     * (or reference) to a subclass in a class hier-
     * archy (not common)
     *  - const_cast: casts away the const-ness
     * of a constant and volatilty of a volatile
     * object
     *  - reinterpret_cast: performs low-level
     * reinterpretation of the bit pattern of
     * the operands (unsafe)
     * 
     * General Form
     *  cast_name<type> expression
     */

    // static_cast
    int i = 1;
    int j = 2;

    cout << static_cast<float>(i) / static_cast<float>(j) << endl;

    // reinterpret_cast
    char *ptrA = new char('A');
    cout << *ptrA << " " << *(reinterpret_cast<int *>(ptrA)) << endl;

    // const_cast
    const int valConst = 10;
    int *ptrB = const_cast<int *>(&valConst);
    int valNotConst = *ptrB;
    valNotConst++;
    cout << valConst << " " << valNotConst << endl;

    return 0;
}