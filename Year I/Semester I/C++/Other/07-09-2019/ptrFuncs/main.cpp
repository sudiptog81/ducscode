#include <iostream>
#include <iomanip>

using namespace std;

float square(float);
float *func1(float &);

int main()
{
	float num;

	// points to num
	float *pnum = &num;

	// points to square()
	float (*func2)(float) = square;

	cout << "Enter a number: ";
	cin >> num;

	// print memory addresses
	cout << endl;
	cout << "Memory" << endl;
	cout << setw(26) << setfill('-') << "" << endl;
	cout << left << setfill(' ');

	cout << setw(10) << "num: " << pnum << endl;
	cout << setw(10) << "square(): " << square << endl;
	cout << setw(10) << "func1(): " << func1 << endl;
	cout << setw(10) << "func2: " << &func2 << endl;
	cout << endl;

	// print pointers
	cout << endl;
	cout << "Pointers" << endl;
	cout << setw(26) << setfill('-') << "" << endl;
	cout << left << setfill(' ');

	cout << setw(10) << "pnum =>"  << pnum << endl;
	cout << setw(10) << "func2 =>" << func2 << endl;
	cout << endl;

	// print outputs
	cout << endl;
	cout << "Output" << endl;
	cout << setw(26) << setfill('-') << "" << endl;
	cout << left << setfill(' ');

	cout << "Executing square(" << *pnum << ") ..."
		 << endl;
	cout << setw(10) << "Output: " << square(*pnum)
		 << endl;

	cout << "Executing func1(" << *pnum << ") ..."
		 << endl;
	cout << setw(10) << "Output: " << func1(*pnum)
		 << endl;

	cout << "Executing func2(" << *pnum << ") ..."
		 << endl;
	cout << setw(10) << "Output: " << (*func2)(*pnum)
		 << endl;

	cout << endl;

	cin.get();
	cout << "Press return to continue ...";
	cin.get();

	return 0;
}

// returns square of a number
float square(float a)
{
	return (a * a);
}

// returns a pointer to input parameter
float *func1(float &a)
{
	return &a;
}
