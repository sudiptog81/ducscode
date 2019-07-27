def sum(a, b):
    """Returns sum

    Arguments:
        a {int} -- Input 1
        b {int} -- Input 2

    Returns:
        sum -- Sum
    """
    return a + b


def difference(a, b):
    """Returns difference

    Arguments:
        a {int} -- Input 1
        b {int} -- Input 2

    Returns:
        diff -- Difference
    """
    return a - b


def product(a, b):
    """Returns product

    Arguments:
        a {int} -- Input 1
        b {int} -- Input 2

    Returns:
        product -- Product
    """
    return a * b


def quotient(a, b):
    """Returns quotient

    Arguments:
        a {float} -- Input 1
        b {float} -- Input 2

    Returns:
        quotient -- Quotient
    """
    if (b == 0):
        return 0
    return a / b


def modulus(a, b):
    """Returns modulus

    Arguments:
        a {int} -- Input 1
        b {int} -- Input 2

    Returns:
        mod -- Modulus
    """
    if (b == 0):
        return 0
    return a % b


def getInputs():
    """Accepts user inputs and returns them

    Returns:
        tuple -- set of inputs
    """
    return int(input("Enter X: ")), int(input("Enter Y: "))


if __name__ == "__main__":
    x, y = getInputs()
    for i in range(5):
        if (i == 0):
            print(f"\nSum: {sum(x, y)}")
        elif (i == 1):
            print(f"Difference: {difference(x, y)}")
        elif (i == 2):
            print(f"Product: {product(x, y)}")
        elif (i == 3):
            print(f"Quotient: {quotient(float(x), float(y))}")
        elif (i == 4):
            print(f"Modulus: {modulus(x, y)}")
    print("\nExiting...\n")