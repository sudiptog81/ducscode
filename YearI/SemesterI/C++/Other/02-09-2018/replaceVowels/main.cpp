#include <iostream>
#include <cctype>

using namespace std;

void replaceVowels(char[]);

int main()
{
    char input[255];
    cout << "Enter a string: ";
    cin >> input;

    replaceVowels(input);

    cout << "Replaced string: ";
    cout << input;

    return 0;
}

void replaceVowels(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
        if ((char)tolower(s[i]) == 'a' ||
            (char)tolower(s[i]) == 'e' ||
            (char)tolower(s[i]) == 'i' ||
            (char)tolower(s[i]) == 'o' ||
            (char)tolower(s[i]) == 'u')
            s[i] = '*';
    return;
}