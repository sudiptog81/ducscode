"""
Write a Python function to produce the outputs such as:
  (a) Diamond of *'s
  (b) Pyramid of Numbers

Written by Sudipto Ghosh for the University of Delhi
"""


def diamondOfStars(height):
    """
    Prints a Diamond of *'s

    Arguments:
        height {integer} -- Height of the Diamond
    """
    for i in range(height // 2):
        print(' ' * (height // 2 - i), '*' * (2 * i + 1))
    for i in range(height // 2, -1, -1):
        print(' ' * (height // 2 - i), '*' * (2 * i + 1))


def pyramidOfNumbers(height):
    """
    Prints a Pyramid of Numbers

    Arguments:
        height {integer} -- Height of the Pyramid
    """
    gap = height - 1
    for j in range(1, height + 1):
        num = j
        print(' ' * gap, end='')
        gap -= 1
        for i in range(j):
            print(num, end='')
            num += 1
        num -= 2
        for i in range(j - 1):
            print(num, end='')
            num -= 1
        print()


def main():
    choice = 1
    while choice != 0:
        print("""
            Main Menu
==================================
  (1) Print a Diamond of *'s
  (2) Print a Pyramid of Numbers
  (0) Exit
        """)
        choice = int(input("Enter Choice: "))
        if choice == 1:
            height = int(input("Enter Height of Diamond: "))
            diamondOfStars(height)
        elif choice == 2:
            height = int(input("Enter Height of Pyramid: "))
            pyramidOfNumbers(height)


if __name__ == "__main__":
    main()
