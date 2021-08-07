def printSquare(s):
    for i in range(len(s)):
        for j in range(len(s)):
            if i == 0 or i == len(s) - 1:
                print(s[j], end=' ')
            elif j == 0 or j == len(s) - 1:
                print(s[i], end=' ')
            else:
                print(' ', end=' ')
        print()


if __name__ == "__main__":
    s = 'ARSDCOLLEGE'
    printSquare(s)
