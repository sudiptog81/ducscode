"""
Write a Python function to return nth terms of Fibonacci sequence.

Written by Sudipto Ghosh for the University of Delhi
"""


def fibonacci(n):
    """
    Calculates nth term of Fibonacci sequence

    Arguments:
        n {integer} -- term
    Returns:
        term {integer}
    """
    assert n > 0, "invalid index"
    if n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def main():
    n = int(input("Enter Term: "))
    nthFibo = fibonacci(n)
    print(f"Term {n} of the Fibonacci Sequence is {nthFibo}")


if __name__ == "__main__":
    main()
