#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
	string ifilename = "input.txt", ofilename = "input-copy.txt", word;

	cout << "Enter input filename (default: input.txt): ";
	cin >> ifilename;

	cout << "Enter input filename (default: output.txt): ";
	cin >> ofilename;

	ifstream infile(ifilename);
	ofstream outfile(ofilename);

	if (!infile)
	{
		cerr << "\nCannot open " << ifilename << "\n";
		return -1;
	}

	if (!outfile)
	{
		cerr << "\nCannot open " << ofilename << "\n";
		return -2;
	}

	while (infile >> word)
	{
		outfile << word << ' ';
	}

	cout << "\nCopying done...\n";

	return 0;
}
