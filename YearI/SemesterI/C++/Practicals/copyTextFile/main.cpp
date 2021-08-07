/**
 *  WAP to copy the contents of one text file to another 
 *  file, after removing all whitespaces.
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 14 - 10 - 2019
 */

#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // ensure proper usage
    if (argc != 3)
    {
        cerr << "Usage: ./main infile outfile\n";
        return 1;
    }

    // attempt to open the input stream
    ifstream fin(argv[1]);
    if (!fin)
    {
        cerr << "Could not read " << argv[1] << "\n";
        return 1;
    }

    // attempt to open the output stream
    ofstream fout(argv[2]);
    if (!fout)
    {
        cerr << "Could not write to " << argv[1] << "\n";
        return 1;
    }

    // read each character from input stream to
    // buffer and write it to the output stream
    char ch;
    while (fin >> ch)
    {
        fout << ch;
    }

    // close all file i/o streams
    fin.close();
    fout.close();

    return 0;
}