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
void clrscr();
int stringLength(char[]);
int countVowels(char[]);
void showAddresses(char[]);
void showMenu(char[], char[]);
char *lowercase(char[], char[]);
char *uppercase(char[], char[]);
char *reverseString(char[], char[]);
void compareStrings(char[], char[]);
char *concatWithStrcat(char[], char[], char[]);
char *concatWithoutStrcat(char[], char[], char[]);

int main()
{
    char string1[255], string2[255], choice = ' ';
    cout << "Enter String 1: ";
    cin >> string1;
    cout << "Enter String 2: ";
    cin >> string2;
    while (choice != 'q')
    {
        clrscr();
        showMenu(string1, string2);
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            cout << endl;
            cout << "Addresses of elements of String 1:\n";
            showAddresses(string1);
            cout << endl;
            cout << "Addresses of elements of String 2:\n";
            showAddresses(string2);
            cout << endl;
            break;
        case 'b':
            cout << endl;
            {
                char t[255];
                cout << "Concatenated String: ";
                concatWithoutStrcat(string1, string2, t);
                cout << t << endl;
            }
            cout << endl;
            break;
        case 'c':
            cout << endl;
            {
                char t[255];
                cout << "Concatenated String: ";
                concatWithStrcat(string1, string2, t);
                cout << t << endl;
            }
            cout << endl;
            break;
        case 'd':
            cout << endl;
            cout << "Result of Comparison: ";
            compareStrings(string1, string2);
            cout << endl;
            break;
        case 'e':
            cout << "\nLength of String 1: " << stringLength(string1);
            cout << "\nLength of String 2: " << stringLength(string2);
            cout << endl
                 << endl;
            break;
        case 'f':
        {
            char t[255];
            cout << "\nString 1 in Lowercase: " << lowercase(string1, t);
            cout << "\nString 2 in Lowercase: " << lowercase(string2, t);
        }
            cout << endl
                 << endl;
            break;
        case 'g':
        {
            char t[255];
            cout << "\nString 1 in Uppercase: " << uppercase(string1, t);
            cout << "\nString 2 in Uppercase: " << uppercase(string2, t);
        }
            cout << endl
                 << endl;
            break;
        case 'h':
            cout << "\nVowels in String 1: " << countVowels(string1);
            cout << "\nVowels in String 2: " << countVowels(string2);
            cout << endl
                 << endl;
            break;
        case 'i':
        {
            char t[255];
            cout << "\nReverse of String 1: " << reverseString(string1, t);
            cout << "\nReverse of String 2: " << reverseString(string2, t);
        }
            cout << endl
                 << endl;
            break;
        default:
            break;
        }

        if (choice != 'q')
        {
            cin.get();
            cout << "Press Enter to continue ...";
            cin.get();
        }
    };
    return 0;
}

void showMenu(char a[], char b[])
{
    cout << endl;
    cout << setw(3) << setfill('=') << "";
    cout << " MENU ";
    cout << setw(60) << "";
    cout << left;
    cout << endl;
    cout << endl;
    cout << " String 1: " << a;
    cout << "\n String 2: " << b;
    cout << endl;
    cout << endl;
    cout << setw(34) << setfill(' ') << " (a) show addresses";
    cout << setw(34) << "(b) concat w/o strcat";
    cout << endl;
    cout << setw(34) << " (c) concat w/ strcat";
    cout << setw(34) << "(d) compare both strings";
    cout << endl;
    cout << setw(34) << " (e) calculate lengths (ptrs)";
    cout << setw(34) << "(f) convert to lowercase";
    cout << endl;
    cout << setw(34) << " (g) convert to uppercase";
    cout << setw(34) << "(h) calculate no. of vowels";
    cout << endl;
    cout << setw(34) << " (i) reverse the strings";
    cout << setw(34) << "(q) quit";
    cout << endl
         << endl;
    return;
}

void showAddresses(char a[])
{
    for (int i = 0; i < stringLength(a); i++)
        cout << '\t' << a[i] << " => " << (void *)&a[i] << endl;
    return;
}

char *concatWithoutStrcat(char a[], char b[], char t[])
{
    int i = stringLength(a), j;
    strcpy(t, a);
    for (j = 0; j < stringLength(b); j++, i++)
        t[i] = b[j];
    t[i] = '\0';
    return t;
}

char *concatWithStrcat(char a[], char b[], char t[])
{
    strcpy(t, a);
    strcat(t, b);
    return t;
}

void compareStrings(char a[], char b[])
{
    if (stringLength(a) == stringLength(b))
        cout << "length(String 1) == length(String 2)" << endl;
    else if (stringLength(a) > stringLength(b))
        cout << "length(String 1) > length(String 2)" << endl;
    else if (stringLength(a) < stringLength(b))
        cout << "length(String 1) < length(String 2)" << endl;

    int flag = 0;
    for (int i = 0, j = 0; i < stringLength(a); i++, j++)
        if (a[i] == b[j])
            flag++;

    if (flag == stringLength(a))
        cout << "String 1 is the same as String 2!" << endl;

    return;
}

int stringLength(char *a)
{
    int i;
    for (i = 0; *(a + i) != '\0'; i++)
        ;
    return i;
}

char *lowercase(char a[], char t[])
{
    strcpy(t, a);
    for (int i = 0; i < stringLength(t); i++)
        if (t[i] >= 'A' && t[i] <= 'Z')
            t[i] = t[i] + 32;
    return t;
}

char *uppercase(char a[], char t[])
{
    strcpy(t, a);
    for (int i = 0; i < stringLength(t); i++)
        if (t[i] >= 'a' && t[i] <= 'z')
            t[i] = t[i] - 32;
    return t;
}

int countVowels(char a[])
{
    int count = 0;
    char t[255];
    for (int i = 0; i < stringLength(a); i++)
        if (lowercase(a, t)[i] == 'a' ||
            lowercase(a, t)[i] == 'e' ||
            lowercase(a, t)[i] == 'i' ||
            lowercase(a, t)[i] == 'o' ||
            lowercase(a, t)[i] == 'u')
            count++;
    return count;
}

char *reverseString(char a[], char t[])
{
    strcpy(t, a);
    int i = 0, j = stringLength(t) - 1, temp;
    while (i < j)
    {
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
        i++;
        j--;
    }
    return t;
}

void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
}