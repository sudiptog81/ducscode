def bubble_sort(l, r):
    l = l.copy()
    print(f'Original: {l}')
    for i in range(0, r, 1):
        for j in range(0, r - i - 1, 1):
            if l[j] > l[j + 1]:
                l[j], l[j + 1] = l[j + 1], l[j]
        print(f'After Iteration {i}: {l}')
    print(f'Sorted: {l}')


def selection_sort(l, r):
    m = 0
    l = l.copy()
    print(f'Original: {l}')
    for i in range(0, r, 1):
        m = i
        for j in range(i + 1, r, 1):
            if l[m] > l[j]:
                m = j
        l[i], l[m] = l[m], l[i]
        print(f'After Iteration {i}: {l}')
    print(f'Sorted: {l}')


def insertion_sort(l, r):
    k = 0
    l = l.copy()
    print(f'Original: {l}')
    for i in range(1, r, 1):
        k = l[i]
        j = i - 1
        while j >= 0 and k < l[j]:
            l[j + 1] = l[j]
            j -= 1
        l[j + 1] = k
        print(f'After Iteration {i}: {l}')
    print(f'Sorted: {l}')


if __name__ == '__main__':
    l = []
    e = 0
    r = 0

    r = int(input('Enter Range: '))
    for i in range(0, r, 1):
        e = int(input('Enter Element: '))
        l.append(e)
    print()

    print('Bubble Sort')
    print('===========')
    bubble_sort(l, r)
    print()

    print('Selection Sort')
    print('===========')
    bubble_sort(l, r)
    print()

    print('Insertion Sort')
    print('===========')
    insertion_sort(l, r)
    print()
