/**
 *  Write a menu driven program to perform following operations on strings: 
 *   (a) Show address of each character in string. 
 *   (b) Concatenate two strings without using strcat function. 
 *   (c) Concatenate two strings using strcat function. 
 *   (d) Compare two strings. 
 *   (e) Calculate the length of the string (use pointers). 
 *   (f) Convert all lowercase characters to uppercase. 
 *   (g) Convert all uppercase characters to lowercase. 
 *   (h) Calculate the number of vowels. 
 *   (i) Reverse the string. 
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 30 - 08 - 2019
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

void showMenu(char *, char *);
void showAddresses(char *, char *);
void concatWithoutStrcat(char *, char *);
void concatWithStrcat(char *, char *);
void compareStrings(char *, char *);

int main()
{
    char string1[255], string2[255], choice = ' ';
    cout << "Enter String 1: ";
    cin >> string1;
    cout << "Enter String 2: ";
    cin >> string2;
    showMenu(string1, string2);
    while (choice != 'q')
    {
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            showAddresses(string1, string2);
            break;
        case 'b':
            concatWithoutStrcat(string1, string2);
            break;
        case 'c':
            concatWithStrcat(string1, string2);
            break;
        case 'd':
            compareStrings(string1, string2);
            break;
        default:
            break;
        }
    };
    return 0;
}

void showMenu(char a[], char b[])
{
    cout << endl;
    cout << setw(3) << setfill('=') << "";
    cout << " MENU ";
    cout << setw(81) << "";
    cout << left;
    cout << endl;
    cout << endl;
    cout << " String 1: " << a;
    cout << "\tString 2: " << b;
    cout << endl;
    cout << endl;
    cout << setw(44) << setfill(' ') << " (a) show addresses";
    cout << setw(44) << "(b) concat w/o strcat";
    cout << endl;
    cout << setw(44) << " (c) concat w/ strcat";
    cout << setw(44) << "(d) compare both strings";
    cout << endl;
    cout << setw(44) << " (e) calculate lengths (ptrs)";
    cout << setw(44) << "(f) convert to lowercase";
    cout << endl;
    cout << setw(44) << " (g) convert to uppercase";
    cout << setw(44) << "(h) calculate no. of vowels";
    cout << endl;
    cout << setw(44) << " (i) reverse the strings";
    cout << setw(44) << "(q) quit";
    cout << endl
         << endl;
    return;
}

void showAddresses(char a[], char b[])
{
    cout << endl;

    cout << "Addresses of elements of String 1:\n";
    for (int i = 0; a[i] != '\0'; i++)
        cout << '\t' << a[i] << " => " << &a + (sizeof(a[i]) * i) << endl;

    cout << endl;

    cout << "Addresses of elements of String 2:\n";
    for (int i = 0; b[i] != '\0'; i++)
        cout << '\t' << b[i] << " => " << &b + (sizeof(b[i]) * i) << endl;

    cout << endl;

    return;
}

void concatWithoutStrcat(char a[], char b[])
{
    int i, j;

    cout << endl;

    // increment i upto length of a
    for (i = 0; a[i] != '\0'; i++)
        ;

    // concat b to the end of a
    for (j = 0; b[j] != '\0'; j++, i++)
        a[i] = b[j];

    cout << "Concatenated String: " << a << endl;

    cout << endl;

    return;
}

void concatWithStrcat(char a[], char b[])
{
    cout << endl;

    strcat(a, b);

    cout << "Concatenated String: " << a << endl;

    cout << endl;

    return;
}

void compareStrings(char a[], char b[])
{
    int flag = 0, greater = (strlen(a) > strlen(b) ? strlen(a) : strlen(b));

    cout << endl;

    for (int i = 0; i < greater; i++)
        if (a[i] == b[i])
            flag = 1;

    if (flag)
        cout << "Strings are equal!" << endl;
    else if (strlen(a) > strlen(b))
        cout << "String 1 is longer than String 2!" << endl;
    else if (strlen(a) < strlen(b))
        cout << "String 2 is longer than String 1!" << endl;

    cout << endl;

    return;
}
