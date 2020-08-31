"""
Write a Python function that takes a string as an input 
from the user and displays its reverse.

Written by Sudipto Ghosh for the University of Delhi
"""


def stringReverse():
    """
    Takes a string as an input from the user 
    and displays its reverse.
    """
    string = input("Enter String: ")
    print("Reversed String:", string[::-1])


def main():
    stringReverse()


if __name__ == "__main__":
    main()
