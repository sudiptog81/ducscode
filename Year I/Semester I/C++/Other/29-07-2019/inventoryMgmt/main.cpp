#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /**
     * Declarations
     */

    int items;
    double unitPrice, discountRate, taxRate, subtotal, discount, tax, total;

    /**
     * Input
     */

    cout << setw(30) << left << "Enter number of sold items:";
    cin >> items;

    cout << setw(30) << left << "Enter the unit price:";
    cin >> unitPrice;

    cout << setw(30) << left << "Enter the discount rate (%):";
    cin >> discountRate;

    cout << setw(30) << left << "Enter the tax rate (%):";
    cin >> taxRate;

    /**
     * Calculations
     */

    discountRate /= 100;
    taxRate /= 100;

    subtotal = items * unitPrice;
    discount = discountRate * subtotal;
    tax = taxRate * subtotal;
    total = subtotal - discount + tax;

    /**
     * Output
     */

    cout << endl;

    cout << setw(20) << left << "Quantity Sold:";
    cout << setw(1) << "";
    cout << setw(7) << right << items << endl;

    cout << setw(20) << left << "Unit Price:";
    cout << setw(1) << "";
    cout << setw(7) << right << setprecision(4) << showpoint << unitPrice << endl;

    cout << setw(20) << "";
    cout << setw(1) << "";
    cout << setw(7) << setfill('-') << right << "" << endl;

    cout << setw(20) << left << setfill(' ') << "Subtotal:";
    cout << setw(1) << setfill(' ') << "";
    cout << setw(7) << right << setprecision(5) << showpoint << subtotal << endl;

    cout << setw(20) << left << setfill(' ') << "Discount:";
    cout << setw(1) << setfill(' ') << '-';
    cout << setw(7) << right << setprecision(4) << showpoint << discount << endl;

    cout << setw(20) << left << setfill(' ') << "Discounted Total:";
    cout << setw(1) << setfill(' ') << "";
    cout << setw(7) << right << setprecision(5) << showpoint << (subtotal - discount) << endl;

    cout << setw(20) << left << setfill(' ') << "Sales Tax:";
    cout << setw(1) << setfill(' ') << '+';
    cout << setw(7) << right << setprecision(4) << showpoint << tax << endl;

    cout << setw(20) << "";
    cout << setw(1) << "";
    cout << setw(7) << setfill('-') << right << "" << endl;

    cout << setw(20) << left << setfill(' ') << "Total Sales:";
    cout << setw(1) << setfill(' ') << "";
    cout << setw(7) << right << setprecision(5) << showpoint << total << endl;

    return 0;
}