/**
 * Write a Program to create a Set A and determine the cardinality of 
 * Set for an input array of elements (repetition allowed) and perform 
 * ismember(a, A) and powerset(A) operations.
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
    void getinput();
    int at(int);
    void display();
    int getcardinality();
    static bool ismember(int, Set *);
    static string powerset(Set *);
};

/**
 * Clears the console
 */
void clrscr();

/**
 * Displays the menu
 */
void handleMenu(Set *);

/**
 * Public Constructor for a Set object
 */
Set::Set(int size)
{
    this->size = size;
    this->ar = new int[this->size];
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
    cout << "Set A: { ";
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
 * Returns the string representation of powerset(s)
 */
string Set::powerset(Set *s)
{
    // Declare a stringstream object
    stringstream sout;

    // Get Cardinality of the Set and its Powerset
    unsigned int size = s->getcardinality();
    unsigned int count = pow(2, size);

    // Base Case: {} is the element of any Powerset
    sout << "{\n {},\n ";

    // Run counter from 1 to 2^(size) - 1
    for (int i = 1; i < count; i++)
    {
        sout << "{";
        for (int j = 0; j < size; j++)
            // If jth bit is set in the counter
            // then print the jth element to the
            // stringstream
            if (i & (1 << j))
                sout << s->at(j) << ",";
        sout << "\b}";
        if (i < count - 1)
            sout << ",\n ";
    }
    sout << "\n}";

    // Return string representaion of the powerset
    return sout.str();
}

int main()
{
    Set *A;
    handleMenu(A);
    return 0;
}

void handleMenu(Set *A)
{
    int el, size, choice, flag = 1;

    cout << "Enter Size of Set: ";
    cin >> size;

    A = new Set(size);
    A->getinput();

    while (flag)
    {
        clrscr();

        A->display();

        cout << "\n\n==== MENU ==================\n";
        cout << "  (1) Get Cardinality\n";
        cout << "  (2) Check Membership\n";
        cout << "  (3) Display Powerset\n";
        cout << "  (4) Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Cardinality of A: ";
            cout << A->getcardinality();
            cout << endl;
            break;
        case 2:
            cout << "Enter Element to Check: ";
            cin >> el;
            cout << "Result: " << el;
            if (Set::ismember(el, A))
                cout << " is a member of A";
            else
                cout << " is not a member of A";
            cout << endl;
            break;
        case 3:
            cout << "Powerset of A:\n";
            cout << Set::powerset(A);
            cout << endl;
            break;
        case 4:
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

    delete A;
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