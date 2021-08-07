/**
 * Create a class Set and take two sets as input from user to 
 * perform following Set operations: Subset, Union, Complement, 
 * Set Difference, Symmetric Difference, Cartesian Product of 
 * two Sets.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/**
 * Set Class Declaration
 */
class Set
{
private:
    int *ar, size;

public:
    Set(int);
    Set(int *, int);
    void getinput();
    int at(int);
    void display();
    int getcardinality();
    static bool ismember(int, Set *);
    static bool subset(Set *, Set *);
    static Set setUnion(Set *, Set *);
    static Set complement(Set *);
    static Set difference(Set *, Set *);
    static Set symmetricdifference(Set *, Set *);
    static string cartesianproduct(Set *, Set *);
};

/**
 * Clears the console
 */
void clrscr();

/**
 * Displays the menu
 */
void handleMenu(Set *, Set *);

/**
 * Insertion Sort
 */
int *insertionSort(int array[], int size)
{
    int i, j, k, key, iterCompCount, count = 0;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        iterCompCount = 0;
        for (j = i - 1; j >= 0; j--)
        {
            count++;
            iterCompCount++;
            if (array[j] > key)
                array[j + 1] = array[j];
            else
                break;
        }
        array[j + 1] = key;
    }
    return array;
}

/**
 * Public Constructor for a Set object using size
 */
Set::Set(int size)
{
    this->size = size;
    this->ar = new int[this->size];
}

/**
 * Public Constructor for a Set object using array
 */
Set::Set(int *array, int size)
{
    this->size = size;
    this->ar = array;
}

/**
 * Populates the Set with user input
 */
void Set::getinput()
{
    cout << "Enter elements of the set: ";
    for (int i = 0; i < this->size; i++)
        cin >> this->ar[i];
}

/**
 * Prints the Set to the console
 */
void Set::display()
{
    cout << "{ ";
    for (int i = 0; i < this->size; i++)
    {
        cout << this->ar[i];
        if (i == size - 1)
            cout << " ";
        else
            cout << ", ";
    }
    cout << "}";
}

/**
 * Returns the ith element in a Set
 */
int Set::at(int i)
{
    return this->ar[i];
}

/**
 * Returns the cardinality of Set s
 */
int Set::getcardinality()
{
    return this->size;
}

/**
 * Checks if an element el is in a Set s
 */
bool Set::ismember(int el, Set *s)
{
    // Iterate over the entire set
    for (int i = 0; i < s->getcardinality(); i++)
    {
        // Return true if match found
        if (el == s->at(i))
            return true;
    }
    return false;
}

/**
 * Checks if a Set X is a subset of Set Y
 */
bool Set::subset(Set *X, Set *Y)
{
    int i = 0, j = 0;
    // Iterate over Set Y
    for (i = 0; i < Y->getcardinality(); i++)
    {
        // Iterate over Set X
        for (j = 0; j < X->getcardinality(); j++)
            // Check if Y[i] matches X[j]
            if (Y->at(i) == X->at(j))
                break;
        // Return false no match found during entire iteration
        if (j == X->getcardinality())
            return false;
    }
    // Return true otherwise
    return true;
}

/**
 * Returns union of Set X and Set Y
 */
Set Set::setUnion(Set *X, Set *Y)
{
    // Declare counters and an empty array
    int size = X->getcardinality() + Y->getcardinality();
    int i = 0, j = 0, k = 0, flag, *array = new int[size];
    // Add all elements of the first set
    for (i = 0; i < X->getcardinality();)
        array[k++] = X->at(i++);
    // Add all elements of the second set not in first set
    for (i = 0; i < Y->getcardinality(); i++)
    {
        flag = 1;
        for (j = 0; j < X->getcardinality(); ++j)
            if (Y->at(i) == X->at(j))
            {
                flag = 0;
                break;
            }
        if (flag)
            array[k++] = Y->at(i);
    }
    // Adjust size of union set
    size = k;
    // Sort the union set
    array = insertionSort(array, size);
    // Return merged union set
    return Set(array, size);
}

/**
 * Returns the Complement of a Set s wrt Universe Set
 */
Set Set::complement(Set *s)
{
    // Declare variables and arrays
    int flag, max, size = 0, universeLen, *universe, *complement;
    // Determine max(s)
    max = s->at(0);
    for (int i = 1; i < s->getcardinality(); i++)
        if (s->at(i) > max)
            max = s->at(i);
    // Construct array for universe set elems
    // Suppose U = {x | x is a +ve integer less than max(s)}
    universe = new int[max + 1];
    for (universeLen = 0; universeLen < max; universeLen++)
        universe[universeLen] = universeLen + 1;
    // Allocate memory for complement set elems
    complement = new int[universeLen];
    // Sort the original set using Insertion Sort
    int *sorted = new int[s->getcardinality()];
    for (int k = 0; k < s->getcardinality(); k++)
        sorted[k] = s->at(k);
    sorted = insertionSort(sorted, s->getcardinality());
    // Iterate over universe and sorted set
    int i = 0, j = 0;
    while (i < universeLen && j < s->getcardinality())
    {
        // Add elements smaller than sorted[j] in universe set
        if (universe[i] < sorted[j])
        {
            complement[size++] = universe[i++];
        }
        // Skip smaller elements of sorted set
        else if (universe[i] > sorted[j])
        {
            j++;
        }
        // Skip identical elements
        else if (universe[i] == sorted[j])
        {
            i++;
            j++;
        }
    }
    // Return the complement set
    return Set(complement, size);
}

/**
 * Return Set Difference X - Y
 */
Set Set::difference(Set *X, Set *Y)
{
    // Declare variables and arrays
    int size = 0, flag, *difference, *sortedX, *sortedY;
    // Allocate memory for arrays
    int max = X->getcardinality() > Y->getcardinality() ? X->getcardinality() : Y->getcardinality();
    difference = new int[max];
    sortedX = new int[X->getcardinality()];
    sortedY = new int[Y->getcardinality()];
    // Sort the original sets using Insertion Sort
    for (int k = 0; k < X->getcardinality(); k++)
        sortedX[k] = X->at(k);
    for (int k = 0; k < Y->getcardinality(); k++)
        sortedY[k] = Y->at(k);
    sortedX = insertionSort(sortedX, X->getcardinality());
    sortedY = insertionSort(sortedY, Y->getcardinality());
    // Iterate over sorted set X
    for (int i = 0; i < X->getcardinality(); i++)
    {
        flag = 0;
        // Iterate over sorted set Y
        for (int j = 0; j < Y->getcardinality(); j++)
        {
            // Skip identical elements
            if (sortedX[i] == sortedY[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        // Add elements in X which were not found in Y
        if (flag == 1)
        {
            difference[size++] = sortedX[i];
        }
    }
    // Return the set difference
    return Set(difference, size);
}

/**
 * Returns the Symmetric Difference X (+) Y
 */
Set Set::symmetricdifference(Set *X, Set *Y)
{
    // Declare variables and arrays
    int size = 0, flag, *symmetricdifference;
    // Allocate memory for arrays
    int max = X->getcardinality() > Y->getcardinality() ? X->getcardinality() : Y->getcardinality();
    symmetricdifference = new int[max];
    // Traverse the Set X and add elements not in Set Y
    for (int i = 0; i < X->getcardinality(); i++)
    {
        flag = 0;
        for (int j = 0; j < Y->getcardinality(); j++)
        {
            if (X->at(i) == Y->at(j))
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
            symmetricdifference[size++] = X->at(i);
    }
    // Traverse the Set Y and add elements not in Set X
    for (int k = 0; k < Y->getcardinality(); k++)
    {
        flag = 0;
        for (int h = 0; h < X->getcardinality(); h++)
        {
            if (Y->at(k) == X->at(h))
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
            symmetricdifference[size++] = Y->at(k);
    }
    // Return the symmetric difference
    return Set(symmetricdifference, size);
}

/**
 * Return the Cartesian Product X x Y
 */
string Set::cartesianproduct(Set *X, Set *Y)
{
    // Declare a stringstream object
    stringstream sout;
    sout << "{ ";
    for (int i = 0; i < X->getcardinality(); i++)
        for (int j = 0; j < Y->getcardinality(); j++)
            // Build the string representaion of the product
            sout << "(" << X->at(i) << ", " << Y->at(j) << ")"
                 << ", ";
    sout << "\b\b }";
    // Return a string object of the product
    return sout.str();
}

int main()
{
    Set *A, *B;
    handleMenu(A, B);
    return 0;
}

void handleMenu(Set *A, Set *B)
{
    int size, choice, flag = 1;

    cout << "Enter Size of Set A: ";
    cin >> size;
    A = new Set(size);
    A->getinput();

    cout << "Enter Size of Set B: ";
    cin >> size;
    B = new Set(size);
    B->getinput();

    while (flag)
    {
        clrscr();

        cout << "Set A: ";
        A->display();
        cout << endl;
        cout << "Set B: ";
        B->display();

        cout << "\n\n==== MENU ==================\n";
        cout << "  (1) Subset\n";
        cout << "  (2) Union\n";
        cout << "  (3) Complement\n";
        cout << "  (4) Set Difference\n";
        cout << "  (5) Symmetric Difference\n";
        cout << "  (6) Cartesian Product\n";
        cout << "  (7) Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            bool subsetAB, subsetBA;

            subsetAB = Set::subset(B, A);
            subsetBA = Set::subset(A, B);

            if (subsetAB && subsetBA)
                cout << "A is equal to B" << endl;
            else if (subsetAB)
                cout << "A is a subset of B" << endl;
            else if (subsetBA)
                cout << "B is a subset of A" << endl;
            else
                cout << "A is not a subset of B\n"
                     << "B is not a subset of A\n";
            break;
        case 2:
            cout << "Union A U B: ";
            Set::setUnion(A, B).display();
            cout << endl;
            break;
        case 3:
            cout << "Complement of A wrt U: ";
            Set::complement(A).display();
            cout << endl;
            cout << "Complement of B wrt U: ";
            Set::complement(B).display();
            cout << endl;
            break;
        case 4:
            cout << "Set Difference A - B: ";
            Set::difference(A, B).display();
            cout << endl;
            cout << "Set Difference B - A: ";
            Set::difference(B, A).display();
            cout << endl;
            break;
        case 5:
            cout << "Symmetric Difference A (+) B: ";
            Set::symmetricdifference(A, B).display();
            cout << endl;
            cout << "Symmetric Difference B (+) A: ";
            Set::symmetricdifference(B, A).display();
            cout << endl;
            break;
        case 6:
            cout << "Cartesian product A x B: "
                 << Set::cartesianproduct(A, B)
                 << endl;
            cout << "Cartesian product B x A: "
                 << Set::cartesianproduct(B, A)
                 << endl;
            break;
        case 7:
            flag = 0;
            break;
        default:
            cout << "Invalid Option";
            break;
        }

        if (flag)
        {
            cout << "\nPress Enter to Continue... ";
            cin.sync();
            cin.get();
        }
    }

    delete A, B;
    return;
}

void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
}
