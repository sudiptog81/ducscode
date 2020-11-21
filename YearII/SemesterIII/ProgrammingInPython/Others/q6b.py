def armstrong(lower=1, upper=1):
    l = []
    for i in range(lower, upper + 1, 1):
        s = 0
        n = i
        o = len(str(n))
        while n > 0:
            d = n % 10
            s += d ** o
            n = n // 10
        if i == s:
            l.append(i)
    return l


if __name__ == "__main__":
    lbound = int(input('Enter Lower Bound of Range: '))
    ubound = int(input('Enter Upper Bound of Range: '))
    print(f'Armstrong Numbers in the Range: {armstrong(lbound, ubound)}')
