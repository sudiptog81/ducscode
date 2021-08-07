"""
Write a Python function that takes two strings as an input 
from the user and counts the number of matching characters 
in the given pair of strings.

Written by Sudipto Ghosh for the University of Delhi
"""


def stringMatch():
    """
    Counts the number of matching characters 
    in a pair of strings.
    """
    count = 0
    str1 = input("Enter String 1: ")
    str2 = input("Enter String 2: ")
    for c in str1:
        if str2.find(c) >= 0:
            count += 1
    print("Number of Matching Characters:", count)


def main():
    stringMatch()


if __name__ == "__main__":
    main()
