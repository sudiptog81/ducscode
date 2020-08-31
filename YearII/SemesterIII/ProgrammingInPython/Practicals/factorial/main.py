"""
Write a Python function that takes a number as an input from the 
user and computes its factorial.

Written by Sudipto Ghosh for the University of Delhi
"""


def factorial(n):
    """
    Calculates factorial of a number

    Arguments:
        n {integer} -- input
    Returns:
        factorial {integer}
    """
    assert n >= 0, 'invalid number'
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


def computeFactorial():
    """
    Takes Argumrnts from the user and computes
    its factorial
    """
    n = int(input("Enter Number: "))
    nFactorial = factorial(n)
    print("Factorial of", n, "is", nFactorial)


def main():
    computeFactorial()


if __name__ == "__main__":
    main()
