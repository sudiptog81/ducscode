'''
Write a program that makes use of a function to accept a list
of n integers and displays a histogram.

Written by Sudipto Ghosh for the University of Delhi
'''

import random
import matplotlib.pyplot as plt


def histogram(list):
    plt.hist(list, bins=5, color='red', edgecolor='black')
    plt.xlabel('Values')
    plt.ylabel('Frequency')
    plt.title('Histogram')
    plt.show()


if __name__ == '__main__':
    n = 0
    l = []

    n = int(input('Enter Number of Elements: '))
    for i in range(0, n, 1):
        l.append(random.randint(0, 10))

    histogram(l)
