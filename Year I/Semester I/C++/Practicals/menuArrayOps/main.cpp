/**
 *  Write a menu driven program to perform following actions on
 *  an array entered by the user:
 *    (a) Print the even-valued elements.
 *    (b) Print the odd-valued elements.
 *    (c) Calculate and print the sum and average of the elements
 *        of the array.
 *    (d) Print the maximum and minimum elements of the array.
 *    (e) Remove the duplicates from the array.
 *    (f) Print the array in reverse order.
 *  The program should present a menu to the user and ask for one 
 *  of the options. The menu should also include options to re-enter
 *  and to quit the program.
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iomanip>
#include <iostream>
#define MAX_DIM 100

using namespace std;

void getch();
void clrscr();

int handleMenu(int &, int *);
void getInputs(int &, int *);
void displayEven(int &, int *);
void displayOdd(int &, int *);
void displaySumAvg(int &, int *);
void displayMinMax(int &, int *);
void removeDuplicates(int &, int *);
void displayReverse(int &, int *);

int main()
{
    // initialize variables
    int choice = 0, size = 0;
    int array[MAX_DIM] = {0};

    // get initial inputs
    getInputs(size, array);

    do
    {
        // show menu and get user choice
        choice = handleMenu(size, array);

        // perform task as per user choice
        switch (choice)
        {
        case 1:
            displayEven(size, array);
            break;
        case 2:
            displayOdd(size, array);
            break;
        case 3:
            displaySumAvg(size, array);
            break;
        case 4:
            displayMinMax(size, array);
            break;
        case 5:
            removeDuplicates(size, array);
            break;
        case 6:
            displayReverse(size, array);
            break;
        case 7:
            cout << endl;
            getInputs(size, array);
            cout << endl;
            getch();
            break;
        default:
            break;
        }
    } while (choice != 0);

    cout << endl;

    return 0;
}

// displays the menu and prompts user for choice
int handleMenu(int &size, int *array)
{
    int c;
    clrscr();
    cout << setw(3) << setfill('=') << ""
         << " MENU "
         << setw(42) << setfill('=') << ""
         << "\n\nArray: [ ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "]\n\n";
    cout << " (1) Print the even-valued elements\n"
         << " (2) Print the odd-valued elements\n"
         << " (3) Calculate & Print Sum and Avg of elements\n"
         << " (4) Print maximum and minimum elements of array\n"
         << " (5) Remove duplicates from the array\n"
         << " (6) Print the array in reverse order\n"
         << " (7) Re-enter the array\n"
         << " (0) Exit the program\n";
    cout << "\nEnter Choice: ";
    cin >> c;
    return c;
}

// populates the array with user data
void getInputs(int &size, int *array)
{
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];
    return;
}

// display even-valued elements
void displayEven(int &size, int *array)
{
    cout << "\nEven-valued Elements: [ ";
    for (int i = 0; i < size; i++)
        if (array[i] % 2 == 0)
            cout << array[i] << " ";
    cout << "]\n\n";
    getch();
    return;
}

// display odd-valued elements
void displayOdd(int &size, int *array)
{
    cout << "\nOdd-valued Elements: [ ";
    for (int i = 0; i < size; i++)
        if (array[i] % 2 != 0)
            cout << array[i] << " ";
    cout << "]\n\n";
    getch();
    return;
}

// display the minimum and maximum values
void displayMinMax(int &size, int *array)
{
    int min = array[0], max = array[0];
    for (int i = 0; i < size; i++)
        if (array[i] < min)
            min = array[i];
        else if (array[i] > max)
            max = array[i];
    cout << "\nMinimum: " << min
         << "\nMaximum: " << max
         << "\n\n";
    getch();
    return;
}

// display the sum and average of the array elements
void displaySumAvg(int &size, int *array)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    cout << "\nSum: " << sum
         << "\nAverage: " << (sum / size);
    cout << "\n\n";
    getch();
    return;
}

// remove duplicate elements in the array
void removeDuplicates(int &size, int *array)
{
    int count = 0, sizeCopy = size;
    int arrayCopy[MAX_DIM] = {0};
    for (int i = 0; i < sizeCopy; i++)
        arrayCopy[i] = array[i];
    for (int i = 0; i < sizeCopy; i++)
        for (int j = i + 1; j < sizeCopy; j++)
            if (arrayCopy[i] == arrayCopy[j])
            {
                count++;
                for (int k = j; k < size; k++)
                    arrayCopy[k] = arrayCopy[k + 1];
                sizeCopy--;
                j--;
            }
    cout << "\nDuplicates Found: " << count;
    cout << "\nRemoved all duplicates ...";
    cout << "\nNew Array: [ ";
    for (int i = 0; i < sizeCopy; i++)
        cout << arrayCopy[i] << " ";
    cout << "]\n\n";
    getch();
    return;
}

// display the array elements in reverse order
void displayReverse(int &size, int *array)
{
    cout << "\nReversed Array: [ ";
    for (int i = size - 1; i >= 0; i--)
        cout << array[i] << " ";
    cout << "]\n\n";
    getch();
    return;
}

void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
    return;
}

void getch()
{
    cout << "Press Enter to continue ... ";
    cin.ignore();
    cin.get();
    return;
}