"""
Write a function that takes two numbers as input parameters and
returns their least common multiple and highest common factor.

Written by Sudipto Ghosh for the University of Delhi
"""


def lcmHcf(num1, num2):
    """
    Calculates least common multiple and highest
    common factor of two numbers

    Arguments:
        num1 {integer} -- term 1
        num2 {integer} -- term 2
    Returns:
        (lcm, hcf) {tuple of integers}
    """
    def hcf(a, b):
        """
        Computes the highest common factor
        """
        while b > 0:
            a, b = b, a % b
        return a

    def lcm(a, b):
        """
        Computes the least common multiple
        """
        return int(a * b / hcf(a, b))

    return lcm(num1, num2), hcf(num1, num2)


def main():
    num1 = int(input("Enter Term 1: "))
    num2 = int(input("Enter Term 2: "))
    lcm, hcf = lcmHcf(num1, num2)
    print(f"LCM of {num1} and {num2}: {lcm}")
    print(f"HCF of {num1} and {num2}: {hcf}")


if __name__ == "__main__":
    main()
