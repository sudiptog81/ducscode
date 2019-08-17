/**
 *  WAP to generate pay-slip of salaried employee
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float basic, hra, da, ta, tax;

    cout << left;
    cout << setw(25) << "Enter Basic Pay:";
    cin >> basic;
    cout << setw(25) << "Enter HRA (%):";
    cin >> hra;
    cout << setw(25) << "Enter DA {%}:";
    cin >> da;
    cout << setw(25) << "Enter TA (%):";
    cin >> ta;
    cout << setw(25) << "Enter Tax (%):";
    cin >> tax;

    hra = basic * (hra / 100);
    da = basic * (da / 100);
    ta = basic * (ta / 100);
    tax = basic * (tax / 100);

    cout << fixed << showpoint << endl;

    cout << right << setw(24) << "PAYMENT SLIP" << endl;
    cout << left << setw(35) << setfill('-') << "" << endl;

    cout << left << setw(25) << setfill(' ') << " BASIC PAY";
    cout << right << setw(8) << setprecision(2) << basic << endl;

    cout << left << setw(24) << setfill(' ') << " HRA";
    cout << '+';
    cout << right << setw(8) << setprecision(2) << hra << endl;

    cout << left << setw(24) << setfill(' ') << " DA";
    cout << '+';
    cout << right << setw(8) << setprecision(2) << da << endl;

    cout << left << setw(24) << setfill(' ') << " TA";
    cout << '+';
    cout << right << setw(8) << setprecision(2) << ta << endl;

    cout << left << setw(35) << setfill('-') << "" << endl;

    cout << left << setw(25) << setfill(' ') << " GROSS SALARY";
    cout << right << setw(8) << setprecision(2) << basic + ta + da + hra << endl;

    cout << left << setw(24) << setfill(' ') << " TAX DEDUCTIONS";
    cout << '-';
    cout << right << setw(8) << setprecision(2) << tax << endl;

    cout << left << setw(35) << setfill('-') << "" << endl;

    cout << left << setw(25) << setfill(' ') << " NET SALARY";
    cout << right << setw(8) << setprecision(2) << basic + ta + da + hra - tax << endl;

    cout << endl;

    return 0;
}