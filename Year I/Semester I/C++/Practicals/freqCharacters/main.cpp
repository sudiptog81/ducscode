/**
 *  WAP that prints a table indicating the number of 
 *  occurrences of each alphabet in the text entered 
 *  as command-line arguments.
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 14 - 10 - 2019
 */

#include <cctype>
#include <iomanip>
#include <iostream>
#define FREQ_SIZE 26

using namespace std;

int main(int argc, char **argv)
{
    // ensure proper usage
    if (argc == 1)
    {
        cerr << "Usage: ./main string(s)\n";
        return 1;
    }

    // initialise array containing frequencies of letters
    int frequency[FREQ_SIZE] = {0};

    // iterate over all the command-line arguments passed
    for (int i = 1; i < argc; i++)

        // iterate over each character in a word
        for (int j = 0; argv[i][j] != '\0'; j++)

            // handle only alphabetic letters
            if (isalpha(argv[i][j]))
            {
                // convert each letter to lowercase
                argv[i][j] = tolower(argv[i][j]);

                // increment frequency of each letter in word
                frequency[(int)(argv[i][j] - 'a')]++;
            }

    // print the header of the table
    cout << "\tLetter\t\tFrequency\n";
    cout << setw(40) << setfill('-') << "" << endl;

    // print the letter and its number of occurrences
    for (int i = 0; i < FREQ_SIZE; i++)
    {
        cout << "\t  ";
        cout << setw(7) << setfill(' ') << left << (char)('a' + i);
        cout << "  |  ";
        cout << setw(7) << setfill(' ') << right << frequency[i] << endl;
    }

    return 0;
}