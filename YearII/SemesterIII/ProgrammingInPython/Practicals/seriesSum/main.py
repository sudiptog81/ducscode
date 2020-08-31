"""
Write a function that finds the sum of the n terms of the
following series:
    (a) 1 – x^2 /2! + x^4 /4! – x^6 /6! + … x^n /n!
    (b) 1 + x^2 /2! + x^4 /4! + x^6 /6! + … x^n /n!

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
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)


def seriesASum(x, n):
    """
    Calculates sum of n terms of the series
    1 – x^2 /2! + x^4 /4! – x^6 /6! + … x^n /n!

    Arguments:
        x {numeric} -- value of x
        n {integer} -- number of terms
    Returns:
        sum {integer}
    """
    assert n > 0, "invalid number"
    exp = 2
    sum = sign = 1
    for i in range(n - 1):
        sign *= -1
        sum += sign * (x ** exp) / factorial(exp)
        exp += 2
    return sum


def seriesBSum(x, n):
    """
    Calculates sum of n terms of the series
    1 + x^2 /2! + x^4 /4! + x^6 /6! + … x^n /n!

    Arguments:
        x {numeric} -- value of x
        n {integer} -- number of terms
    Returns:
        sum {integer}
    """
    assert n > 0, "invalid number"
    exp = 2
    sum = 1
    for i in range(n - 1):
        sum += (x ** exp) / factorial(exp)
        exp += 2
    return sum


def main():
    choice = 1
    while choice != 0:
        print("""
             Main Menu - Sum of Series
====================================================
 (1) 1 – x^2 /2! + x^4 /4! – x^6 /6! + … + x^n /n!
 (2) 1 + x^2 /2! + x^4 /4! + x^6 /6! + … + x^n /n!
 (0) Exit
        """)
        choice = int(input("Enter Choice: "))
        if choice == 1:
            x = float(input("Enter x: "))
            n = int(input("Enter n: "))
            print(f"Sum of {n} Terms of Series A:", seriesASum(x, n))
        elif choice == 2:
            x = float(input("Enter x: "))
            n = int(input("Enter n: "))
            print(f"Sum of {n} Terms of Series B :", seriesBSum(x, n))


if __name__ == "__main__":
    main()
