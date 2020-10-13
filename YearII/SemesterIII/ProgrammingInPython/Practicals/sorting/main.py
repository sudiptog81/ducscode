"""
Write a program to implement:
  (a) bubble sort
  (b) selection sort
  (c) insertion sort
"""


def bubble_sort(l, r):
    """
    Sorts a list using Bubble Sort Algorithm
    """
    l = l.copy()
    for i in range(0, r, 1):
        for j in range(0, r - i - 1, 1):
            if l[j] > l[j + 1]:
                l[j], l[j + 1] = l[j + 1], l[j]
    return l


def selection_sort(l, r):
    """
    Sorts a list using Selection Sort Algorithm
    """
    m = 0
    l = l.copy()
    for i in range(0, r, 1):
        m = i
        for j in range(i + 1, r, 1):
            if l[m] > l[j]:
                m = j
        l[i], l[m] = l[m], l[i]
    return l


def insertion_sort(l, r):
    """
    Sorts a list using Insertion Sort Algorithm
    """
    k = 0
    l = l.copy()
    for i in range(1, r, 1):
        k = l[i]
        j = i - 1
        while j >= 0 and k < l[j]:
            l[j + 1] = l[j]
            j -= 1
        l[j + 1] = k
    return l


if __name__ == "__main__":
    l = []
    e = 0
    r = 0

    r = int(input("Enter Range: "))
    for i in range(0, r, 1):
        e = int(input("Enter Element: "))
        l.append(e)

    print("Original List:", l)
    print("Sorted using Bubble Sort:", bubble_sort(l, r))
    print("Sorted using Selection Sort:", selection_sort(l, r))
    print("Sorted using Insertion Sort:", insertion_sort(l, r))
