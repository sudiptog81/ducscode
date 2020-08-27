"""
Write a Python program to illustrate the various functions of
the Math module.

Written by Sudipto Ghosh for the University of Delhi
"""

import math


def main():
    choice = 1
    while choice != 0:
        print("""
            Main Menu
==================================
 (01) Calculate Ceiling
 (02) Calculate Floor
 (03) Calculate Absolute Value
 (04) Calculate e^x
 (05) Calculate Natural Log
 (06) Calulate Log (Base 10)
 (07) Calculate x ^ y
 (08) Calculate Square Root
 (09) Convert Radians to Degrees
 (10) Convert Degrees to Radians
 (11) Calculate sin(x)
 (12) Calculate sin^-1(x)
 (13) Calculate cos(x)
 (14) Calculate cos^-1(x)
 (15) Calculate tan(x)
 (16) Calculate tan^-1(x)
 (00) Exit
        """)
        choice = int(input("Enter Choice: "))
        if choice == 1:
            x = float(input("Enter x: "))
            print("Ceiling of x:", math.ceil(x))
        elif choice == 2:
            x = float(input("Enter x: "))
            print("Floor of x:", math.floor(x))
        elif choice == 3:
            x = float(input("Enter x: "))
            print("Absolute Value of x:", math.fabs(x))
        elif choice == 4:
            x = float(input("Enter x: "))
            print("Value of e^x:", math.exp(x))
        elif choice == 5:
            x = float(input("Enter x: "))
            print("Value of ln(x):", math.log(x))
        elif choice == 6:
            x = float(input("Enter x: "))
            print("Value of log_10(x):", math.log10(x))
        elif choice == 7:
            x = float(input("Enter x: "))
            y = float(input("Enter y: "))
            print("Value of x^y:", math.pow(x, y))
        elif choice == 8:
            x = float(input("Enter x: "))
            print("Square Root of x:", math.sqrt(x))
        elif choice == 9:
            x = float(input("Enter x (rad): "))
            print("Value of x (deg):", math.degrees(x))
        elif choice == 10:
            x = float(input("Enter x (deg): "))
            print("Value of x (rad):", math.radians(x))
        elif choice == 11:
            x = float(input("Enter x (deg): "))
            print("Value of sin(x):", math.sin(math.radians(x)))
        elif choice == 12:
            x = float(input("Enter x: "))
            print("Value of sin^-1(x):", math.degrees(math.asin(x)))
        elif choice == 13:
            x = float(input("Enter x (deg): "))
            print("Value of cos(x):", math.cos(math.radians(x)))
        elif choice == 14:
            x = float(input("Enter x: "))
            print("Value of cos^-1(x):", math.degrees(math.acos(x)))
        elif choice == 15:
            x = float(input("Enter x (deg): "))
            print("Value of tan(x):", math.tan(math.radians(x)))
        elif choice == 16:
            x = float(input("Enter x: "))
            print("Value of tan^-1(x):", math.degrees(math.atan(x)))


if __name__ == "__main__":
    main()
