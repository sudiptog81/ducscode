"""
Write a function that takes a number with two or more digits as an 
input and finds its reverse and computes the sum of its digits.

Written by Sudipto Ghosh for the University of Delhi
"""


def reverseSumDigits(n):
    """
    Calculates reverse and computes the sum of 
    the digits of a number

    Arguments:
        n {integer} -- input
    """
    rev = sumDigits = 0
    if n < 0:
        n = abs(n)
    while (n != 0):
        rev = 10 * rev + n % 10
        sumDigits += n % 10
        n //= 10
    print("Reverse:", rev)
    print("Sum of Digits:", sumDigits)


def main():
    n = int(input("Enter Number: "))
    reverseSumDigits(n)


if __name__ == "__main__":
    main()
