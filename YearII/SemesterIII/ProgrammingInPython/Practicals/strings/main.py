"""
Write a menu driven program to perform the following on strings:
a) Find the length of string.
b) Return maximum of three strings.
c) Accept a string and replace all vowels with “#”
d) Find number of words in the given string.
e) Check whether the string is a palindrome or not.

Written by Sudipto Ghosh for the University of Delhi
"""


def findLength():
    c = 0
    s = input('Enter a String: ')
    for i in s:
        c += 1
    print('Length of String:', c)


def maxOfStrings():
    maximum = ''
    s1 = input('Enter String 1: ')
    s2 = input('Enter String 2: ')
    s3 = input('Enter String 3: ')
    if s1 >= s2 and s1 >= s3:
        maximum = s1
    elif s2 >= s1 and s2 >= s3:
        maximum = s2
    else:
        maximum = s3
    print('Maximum of Three Strings:', maximum)


def replaceVowels():
    s = input('Enter a String: ')
    for i in s:
        if i in 'aAeEiIoOuU':
            s = s.replace(i, '#')
    print('Modified String:', s)


def numberOfWords():
    s = input('Enter a String: ')
    c = 0
    for i in s:
        if i == ' ':
            c += 1
    print('Number of Words:',  c + 1)


def isPalindrome():
    f = True
    s = input('Enter a String: ')
    for i in range(0, len(s) // 2, 1):
        if s[i] != s[len(s) - i - 1]:
            f = False
            print('String is not a Palindrome')
            break
    if f == True:
        print('String is a Palindrome')


def main():
    s = ''
    s1 = ''
    s2 = ''
    s3 = ''
    flag = 0
    while True:
        print('''
                      MENU
===================================================
(1) Find the length of string.
(2) Return maximum of three strings.
(3) Accept a string and replace all vowels with '#'
(4) Find number of words in the given string.
(5) Check whether the string is a palindrome or not.
(0) Exit

        ''')
        c = int(input('Enter Choice: '))
        if c == 1:
            findLength()
        elif c == 2:
            maxOfStrings()
        elif c == 3:
            replaceVowels()
        elif c == 4:
            numberOfWords()
        elif c == 5:
            isPalindrome()
        elif c == 0:
            break
        input('Press any key to continue...')


if __name__ == '__main__':
    main()
