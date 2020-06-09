/**
 *  Write a function that checks whether a given string 
 *  is a Palindrome or not and use it to check whether 
 *  the string entered by user is a Palindrome.
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 06 - 09 - 2019
 */

#include <iostream>

using namespace std;

void checkPalindrome(char[]);

int main()
{
    char str[255];
    cout << "Enter a string: ";
    cin >> str;
    checkPalindrome(str);
    return 0;
}

void checkPalindrome(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    i--;
    for (int j = 0, k = i; j <= i / 2; j++, k--)
    {
        if (s[j] != s[k])
        {
            cout << "String \"" << s << "\" is not a palindrome.";
            return;
        }
    }
    cout << "String \"" << s << "\" is a palindrome.";
    return;
}