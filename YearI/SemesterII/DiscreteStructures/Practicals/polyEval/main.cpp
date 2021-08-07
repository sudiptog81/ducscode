/**
 * Write a Program to store a function (polynomial/exponential), 
 * and then evaluate the polynomial.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cmath>
#include <iostream>
using namespace std;
/**
 * Function Class Declaration
 */
class Function
{
private:
    int terms;
    double *coefficients;
    double *exponentials;

public:
    void getInput();
    void display();
    double evaluate(double);
};
/**
 * Prompts user for required inputs
 */
void Function::getInput()
{
    cout << "Enter the number of terms: ";
    cin >> this->terms;
    this->coefficients = new double[this->terms];
    this->exponentials = new double[this->terms];
    for (int i = 0; i < this->terms; i++)
    {
        cout << "Enter term (coefficient exponential) "
             << i + 1 << ": ";
        cin >> this->coefficients[i] >> this->exponentials[i];
    }
}
/**
 * Prints the Function to the console
 */
void Function::display()
{
    for (int i = 0; i < this->terms; i++)
    {
        cout << this->coefficients[i];
        if (this->exponentials[i] != 0)
            cout << "(x^" << this->exponentials[i]
                 << ")";
        if (i != this->terms - 1)
            cout << " + ";
    }
    cout << endl;
}
/**
 * Evaluates f(x) for a particular x
 */
double Function::evaluate(double x)
{
    double sum = 0.0f;
    for (int i = 0; i < this->terms; i++)
        if (this->exponentials[i] > 0)
            sum += this->coefficients[i] * pow(x, this->exponentials[i]);
        else if (this->exponentials[i] < 0)
            sum += this->coefficients[i] / pow(x, abs(this->exponentials[i]));
        else
            sum += this->coefficients[i];
    return sum;
}
int main()
{
    Function p;
    p.getInput();
    cout << "Function f(x) is: ";
    p.display();
    double x;
    cout << "Enter value of x: ";
    cin >> x;
    cout << "Value of f(" << x << "): "
         << p.evaluate(x);
    return 0;
}