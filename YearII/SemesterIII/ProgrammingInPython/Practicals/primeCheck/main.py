"""
Write a function that takes a number as an input and 
determine whether it is prime or not.

Written by Sudipto Ghosh for the University of Delhi
"""


def isPrime(n):
    """
    Determines whether a number is prime

    Arguments:
        n {integer} -- term
    Returns:
        isPrime {boolean}
    """
    assert n > 0, "invalid number"
    if n == 1:
        return False
    for i in range(2, n):
        if (n % i) == 0:
            return False
    return True


def main():
    n = int(input("Enter Term: "))
    primeString = "a prime number" if isPrime(n) \
        else "not a prime number"
    print(f"{n} is {primeString}")


if __name__ == "__main__":
    main()
