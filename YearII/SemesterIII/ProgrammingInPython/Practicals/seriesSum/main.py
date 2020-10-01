'''
Write a function that finds the sum of the n terms of the
following series, import the factorial function created in Q4:
    1 – x^2 /2! + x^4 /4! – x^6 /6! + … x^n /n!

Written by Sudipto Ghosh for the University of Delhi
'''
# main.py
from factorial import factorial


def seriesSum(x, n):
    '''
    Calculates sum of n terms of the series

    Arguments:
        x {numeric} -- value of x
        n {integer} -- number of terms
    Returns:
        s {integer} -- sum
    '''
    assert n > 0, 'invalid number'
    e = 2
    s = 1
    sign = 1
    for i in range(n - 1):
        sign *= -1
        s += sign * (x ** e) / factorial(e)
        e += 2
    return s


def main():
    x = float(input('Enter x: '))
    n = int(input('Enter n: '))
    print(f'Sum of {n} Terms of the Series:', seriesSum(x, n))


if __name__ == "__main__":
    main()
