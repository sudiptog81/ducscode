"""
Write a Python function to calculate the sum and product of
two compatible matrices

Written by Sudipto Ghosh for the University of Delhi
"""


class Matrix():
    def __init__(self, rows=0, cols=0):
        if not rows or not cols:
            rows = int(input("Enter Rows: "))
            cols = int(input("Enter Columns: "))
            self.arr = [[0 for i in range(cols)] for j in range(rows)]
            for i in range(rows):
                for j in range(cols):
                    self.arr[i][j] = int(input(f"Enter Element ({i},{j}): "))

    def __str__(self):
        string = ""
        for i in range(len(self.arr)):
            for j in range(len(self.arr[0])):
                string += str(self.arr[i][j]) + ' '
            string += '\n'
        return string

    def setArr(self, arr):
        self.arr = arr

    def add(self, b):
        """
        Calculates the sum of two compatible
        matrices

        Arguments:
            self {Matrix} - Matrix A
            b {Matrix} - Matrix B

        Returns:
            sum {Matrix} - Matrix A + B
        """
        assert len(self.arr) == len(b.arr) and \
            len(self.arr[0]) == len(b.arr[0]), \
            "incompatible matrices"
        result = Matrix(len(b.arr), len(b.arr[0]))
        resultArr = [[0 for i in range(len(b.arr[0]))]
                     for j in range(len(b.arr))]
        for i in range(len(self.arr)):
            for j in range(len(self.arr[0])):
                resultArr[i][j] = self.arr[i][j] + b.arr[i][j]
        result.setArr(resultArr)
        return result

    def multiply(self, b):
        """
        Calculates the product of two compatible
        matrices

        Arguments:
            self {Matrix} - Matrix A
            b {Matrix} - Matrix B

        Returns:
            product {Matrix} - Matrix A x B
        """
        assert len(self.arr[0]) == len(b.arr), \
            "incompatible matrices"
        result = Matrix(len(self.arr), len(b.arr[0]))
        resultArr = [[0 for i in range(len(b.arr[0]))]
                     for j in range(len(self.arr))]
        for i in range(len(self.arr)):
            for j in range(len(self.arr[0])):
                for k in range(len(b.arr)):
                    resultArr[i][j] += self.arr[i][k] * b.arr[k][j]
        result.setArr(resultArr)
        return result


def main():
    print("Matrix A\n=============")
    a = Matrix()
    print()
    print("Matrix B\n=============")
    b = Matrix()
    print()
    print("Matrix A\n=============")
    print(a)
    print("Matrix B\n=============")
    print(b)
    print("Matrix A + B\n=============")
    print(a.add(b))
    print("Matrix A x B\n=============")
    print(a.multiply(b))


if __name__ == "__main__":
    main()
