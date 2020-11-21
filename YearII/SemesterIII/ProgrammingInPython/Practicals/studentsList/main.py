'''
Write a menu-driven program to accept a list of student names
and perform the following:

  (a)	Search an element using linear search/binary search.
  (b)	Sort the elements using bubble sort/insertion sort/
      selection sort.

Written by Sudipto Ghosh
'''


def linearSearch(list, e):
    for l in list:
        if e == l:
            return True
    return False


def binarySearch(list, left, right, e):
    if right >= left:
        mid = (left + right) // 2
        if list[mid] == e:
            return mid
        elif list[mid] > e:
            return binarySearch(list, left, mid - 1, e)
        else:
            return binarySearch(list, mid + 1, right, e)
    else:
        return -1


def bubbleSort(list):
    list = list.copy()
    for i in range(len(list)-1):
        for j in range(0, len(list) - i - 1):
            if list[j] > list[j + 1]:
                list[j], list[j + 1] = list[j + 1], list[j]
    return list


def insertionSort(list):
    list = list.copy()
    for i in range(1, len(list)):
        key = list[i]
        j = i - 1
        while j >= 0 and key < list[j]:
            list[j + 1] = list[j]
            j -= 1
        list[j + 1] = key
    return list


def selectionSort(list):
    list = list.copy()
    for i in range(len(list)):
        minimum = i
        for j in range(i + 1, len(list)):
            if list[minimum] > list[j]:
                minimum = j
        list[i], list[minimum] = list[minimum], list[i]
    return list


def main():
    students = []
    r = int(input('Enter Number of Students: '))
    for i in range(1, r + 1, 1):
        name = input(f'Enter Name of Student {i}: ')
        students.append(name)
    while True:
        print('''
         MENU
========================
  (1) Linear Search
  (2) Binary Search
  (3) Bubble Sort
  (4) Insertion Sort
  (5) Selection Sort
  (0) Exit
        ''')
        choice = int(input('Enter Choice: '))
        if choice == 1:
            name = input("Enter Name to Search: ")
            if (linearSearch(students, name)):
                print("Student Found in List")
            else:
                print("Student Not Found in List")
        elif choice == 2:
            name = input("Enter Name to Search: ")
            if (binarySearch(bubbleSort(students), 0, r - 1, name) >= 0):
                print("Student Found in List")
            else:
                print("Student Not Found in List")
        elif choice == 3:
            print('Original List:', students)
            print('Sorted List:', bubbleSort(students))
        elif choice == 4:
            print('Original List:', students)
            print('Sorted List:', insertionSort(students))
        elif choice == 5:
            print('Original List:', students)
            print('Sorted List:', selectionSort(students))
        elif choice == 0:
            break
        input('Press any key to continue...')


if __name__ == "__main__":
    main()
