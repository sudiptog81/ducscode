#include <iostream>

using namespace std;

int main()
{
    // Lowercase Letters of English Alphabet

    char alphabet = 'a';

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet << "\t" << (int)alphabet << endl;
        alphabet++;
    }

    // Uppercase Letters of English Alphabet

    char alphabetCaps = 'A';

    for (int i = 0; i < 26; i++)
    {
        cout << alphabetCaps << "\t" << (int)alphabetCaps << endl;
        alphabetCaps++;
    }

    // Some ASCII Symbols

    char symbol = '!';

    for (int i = 0; i < 7; i++)
    {
        cout << symbol << "\t" << (int)symbol << endl;
        symbol++;
    }

    return 0;
}