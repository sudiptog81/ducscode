def factorial(n):
    '''
    Calculates factorial of a number

    Accepts:
        n {integer} -- input
    Returns:
        factorial {integer}
    '''
    assert n >= 0, 'invalid number'
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)
