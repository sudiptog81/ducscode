def removeMultipleSpaces(s):
    return ' '.join(s.split())


def count(s):
    nChars = nSpaces = 0
    for c in s:
        if c in [' ', '\t']:
            nSpaces += 1
        else:
            nChars += 1
    return nChars, nSpaces


if __name__ == '__main__':
    nChars = 0
    nSpaces = 0
    s = input('Enter a String: ')
    nChars, nSpaces = count(s)
    print(f'No. of characters: {nChars}')
    print(f'No. of whitespaces: {nSpaces}')
    s = removeMultipleSpaces(s)
    nChars, nSpaces = count(s)
    print(f'String with unnecessary spaces removed: {s}')
    print(f'No. of characters: {nChars}')
    print(f'No. of whitespaces: {nSpaces}')
