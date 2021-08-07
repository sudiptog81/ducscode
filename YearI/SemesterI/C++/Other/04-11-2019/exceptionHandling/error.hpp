#include <string>
#include <iostream>

using namespace std;

class Error
{
public:
    virtual const string print()
    {
        return "Error: An error has occurred.\n";
    }
};

class Arithmetic : public Error
{
public:
    virtual const string print()
    {
        return "ArithmeticError: An arithmetic error has occurred.\n";
    }
};

class DivByZero : public Arithmetic
{
public:
    virtual const string print()
    {
        return "DivByZeroError: Division by zero was attempted.\n";
    }
};

class DivByNeg : public Arithmetic
{
public:
    virtual const string print()
    {
        return "DivByNegError: Division by a negative integer was attempted.\n";
    }
};

class BadOperator : public Arithmetic
{
public:
    virtual const string print()
    {
        return "BadOperatorError: Operator behaviour not defined.\n";
    }
};

const string except()
{
    return "Exception: An exception has occurred.\n";
}