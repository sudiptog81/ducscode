def palindromes(lower=1, upper=1):
    l = []
    d = r = t = 0
    for i in range(lower, upper + 1, 1):
        r = 0
        t = i
        while i > 0:
            d = i % 10
            r = r * 10 + d
            i = i // 10
        if t == r:
            l.append(t)
    return l


def primes(lower=1, upper=1):
    l = []
    for i in range(lower, upper + 1, 1):
        if i > 1:
            for j in range(2, i, 1):
                if i % j == 0:
                    break
            else:
                l.append(i)
    return l


def palprimes(lower=1, upper=1):
    l = []
    prime = primes(lower, upper)
    palindrome = palindromes(lower, upper)
    for i in range(lower, upper, 1):
        if i in prime and i in palindrome:
            l.append(i)
    return l


if __name__ == "__main__":
    ch = lbound = ubound = 0
    while True:
        print('''
         MENU
========================
 (1) Find Palindromes
 (2) Find Primes
 (3) Find Palprimes
 (0) Exit
    ''')
        ch = int(input('Enter Choice: '))
        if ch == 1:
            lbound = int(input('Enter Lower Bound of Range: '))
            ubound = int(input('Enter Upper Bound of Range: '))
            print(f'Palindromes in the Range: {palindromes(lbound, ubound)}')
        elif ch == 2:
            lbound = int(input('Enter Lower Bound of Range: '))
            ubound = int(input('Enter Upper Bound of Range: '))
            print(f'Primes in the Range: {primes(lbound, ubound)}')
        elif ch == 3:
            lbound = int(input('Enter Lower Bound of Range: '))
            ubound = int(input('Enter Upper Bound of Range: '))
            print(f'Palprimes in the Range: {palprimes(lbound, ubound)}')
        elif ch == 0:
            break
        input('\nPress Enter to Continue ...')
