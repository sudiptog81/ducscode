"""
Write a Python function that takes a string as an input from 
the user and determines whether it is palindrome or not.

Written by Sudipto Ghosh for the University of Delhi
"""


def palindromeCheck():
    """
    Takes a string as an input from the user 
    and determines whether it is palindrome or 
    not.
    """

    # def isPalindrome(string):
    #     return string == string[::-1]

    def isPalindrome(string):
        for i in range(len(string) // 2):
            if string[i] != string[len(string) - i - 1]:
                return False
        return True

    string = input("Enter String: ")
    print(f"{string} is",
          "a Palindrome"
          if isPalindrome(string) else
          "not a Palindrome")


def main():
    palindromeCheck()


if __name__ == "__main__":
    main()
