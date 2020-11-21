def factorial(i):
    if (i == 0):
        return 1
    return i * factorial(i - 1)


def seriesSum(x, n):
    s = x
    neg = -1
    negp = 0
    for i in range(2, n + 1, 1):
        s += (neg ** negp) * (x ** i) / factorial(i)
        negp += 1
    return s


if __name__ == "__main__":
    x = int(input('Enter Value for x: '))
    n = int(input('Enter No. of Terms: '))
    print(f'Series Sum upto {n} terms: {float(seriesSum(x, n)):.3}')
