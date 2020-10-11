"""
Write a Python function to find the nth term of Fibonacci sequence
and its factorial. Return the result as a list.

Written by Sudipto Ghosh for the University of Delhi
"""


def fibonacci(n):
    '''
    Calculates nth term of Fibonacci sequence

    Arguments:
        n {integer} -- term
    Returns:
        term {integer}
    '''
    assert n > 0, 'invalid index'
    if n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def factorial(n):
    '''
    Calculates factorial of a number

    Accepts:
        n {int} -- input
    Returns:
        factorial {int}
    '''
    assert n >= 0, 'invalid number'
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


def fibonacciAndFactorial(n):
    '''
    Returns the nth term of Fibonacci sequence
    and its factorial

    Accepts:
        n {int} -- an integer
    Returns
        [term, factorial] {list}
    '''
    return [fibonacci(n), factorial(n)]


def main():
    n = int(input('Enter Term: '))
    f = fibonacciAndFactorial(n)
    print(f'Term {n} of the Fibonacci Sequence is {f[0]}')
    print(f'It\'s factorial is {f[1]}')


if __name__ == '__main__':
    main()
