"""
Write a function that takes a number (>=10) 
as an input and return the digits of the number 
as a set.
"""


def setOfDigits(n):
    '''
    Takes a number and returns its digits
    as a set

    Accepts:
      n {int} -- a number
    Returns:
      digits {set} -- digits of the number
    '''
    assert n >= 10
    s = set()
    while n != 0:
        s.add(n % 10)
        n //= 10
    return s


def main():
    n = int(input('Enter a Number: '))
    print('Set of Digits:', setOfDigits(n))


if __name__ == '__main__':
    main()
