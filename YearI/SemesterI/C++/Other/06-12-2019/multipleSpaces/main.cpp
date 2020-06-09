/** 
 *   WAP to replace multiple spaces in a text file With
 *   single space
 *
 *   Written by Sudipto Ghosh for University of Delhi
 */

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
	return -1;

    char ch;
    int count = 0;

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    while(fin.get(ch))
    {
	if (ch == '\t')
	    ch = ' ';
	if (ch == ' ')
	    count++;
	else
	    count = 0;
	if (count <= 1)	
	    fout.put(ch);
    }

    fin.close();
    fout.close();
    return 0;
}