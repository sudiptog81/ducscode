def replaceZero(l, r):
    l = l.copy()
    # l = [0] * r
    for i in range(0, r, 1):
        l[i] = 0
    return l


def multiplyLists(l1, l2):
    r1 = len(l1)
    r2 = len(l2)
    product = []
    assert r1 == r2, f'{r1} != {r2}'
    # product = [i * j for i, j in zip(l1, l2)]
    # product = [l1[i] * l2[i] for i in range(0, r1, 1)]
    for i in range(0, r1, 1):
        product.append(l1[i] * l2[i])
    return product


if __name__ == "__main__":
    l = []
    l2 = []
    e = 0
    r = 0

    r = int(input("Enter Range: "))
    for i in range(0, r, 1):
        e = int(input("Enter Element: "))
        l.append(e)

    print("Original List:", l)
    print("List after Replacing with 0's:", replaceZero(l, r))

    r = int(input("Enter Range for List 2: "))
    for i in range(0, r, 1):
        e = int(input("Enter Element: "))
        l2.append(e)
    print("Multiplication of Lists:", multiplyLists(l, l2))
