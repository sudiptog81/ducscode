"""
Write a Python program to perform the following using list:

    (a)	Check if all elements in list are numbers or not.
    (b)	If it is a numeric list, then count number of odd values in it.
    (c)	If list contains all strings, then display largest string in the list.
    (d)	Display list in reverse form.
    (e)	Find a specified element in list.
    (f)	Remove the specified element from the list.
    (g)	Sort the list in descending order.
    (h)	Accept 2 lists and find the common members in them.

Written by Sudipto Ghosh for the University of Delhi
"""


def isNumericList(l):
    for i in range(0, len(l), 1):
        if not l[i].isnumeric():
            return False
    return True


def isStringList(l):
    for i in range(0, len(l), 1):
        if not type(l[i]) == str:
            return False
    return True


def revDisplay(l):
    for i in range(len(l) - 1, -1, -1):
        print(l[i], end=' ')
    print()


def linearSearch(e, l):
    for i in range(0, len(l), 1):
        if l[i] == e:
            return True
    return False


def removeElement(e, l):
    if (linearSearch(e, l)):
        l.remove(e)
        return True
    return False


def revSort(l):
    for i in range(0, len(l), 1):
        for j in range(i + 1, len(l), 1):
            if l[i] < l[j]:
                l[i], l[j] = l[j], l[i]
    return l


def displayCommon(l1, l2):
    for i in l1:
        if i in l2:
            print(i, end=' ')
    print()


def main():
    l = []
    l2 = []
    r = 0
    e = 0
    c = 0
    r = int(input('Enter a Range: '))
    for i in range(0, r, 1):
        e = input('Enter Element: ')
        l.append(e)
    print('List:', end=' ')
    print(l)
    if (isNumericList(l)):
        print('Numeric List')
        for i in l:
            if not int(i) % 2 == 0:
                c += 1
        print('No. of Odd Values in List:', c)
    elif (isStringList(l)):
        print('String List')
        print('Largest String in List:', max(l))
    print('Displaying List in Reverse:', end=' ')
    revDisplay(l)
    e = input('Enter Search Element: ')
    if (linearSearch(e, l)):
        print('Element Found in List')
    else:
        print('Element Not Found in List')
    e = input('Enter Element to Remove: ')
    r = removeElement(e, l)
    if (r):
        print('List after Removing Element:', l)
    else:
        print('Element Not Found in List')

    print('Descending Sorted List:', revSort(l))

    print('Enter Data for List 2:')
    r = int(input('Enter a Range: '))
    for i in range(0, r, 1):
        e = input('Enter Element: ')
        l2.append(e)
    print('Common Elements:', end=' ')
    displayCommon(l, l2)


if __name__ == '__main__':
    main()
